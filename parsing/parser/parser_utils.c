/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 11:57:17 by cgelgon           #+#    #+#             */
/*   Updated: 2025/04/08 13:50:22 by cgelgon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool	is_redir_token(t_token_type type)
{
	return (type == TOKEN_REDIR_IN || type == TOKEN_REDIR_OUT
		|| type == TOKEN_APPEND || type == TOKEN_HEREDOC);
}

void	free_av_array(char **av, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		free(av[i]);
		i++;
	}
	free(av);
}

void	skip_redir_token(t_token **current)
{
	if (is_redir_token((*current)->toktype) && (*current)->next)
		*current = (*current)->next;
}

char	**create_av_array(t_token *tokens, int ac, t_data *data)
{
	char	**av;
	int		i;
	t_token	*current;

	(void)data;
	av = malloc(sizeof(char *) * (ac + 1));
	if (!av)
		return (NULL);
	i = 0;
	current = tokens;
	while (current && i < ac)
	{
		if (current->toktype == TOKEN_WORD)
		{
			av[i] = ft_strdup(current->value);
			if (!av[i])
				return (free_av_array(av, i), NULL);
			i++;
		}
		else
			skip_redir_token(&current);
		current = current->next;
	}
	av[i] = NULL;
	return (av);
}

int	count_args(t_token *tokens)
{
	int		count;
	t_token	*current;

	count = 0;
	current = tokens;
	while (current && current->toktype != TOKEN_EOF
		&& current->toktype != TOKEN_PIPE)
	{
		if (current->toktype == TOKEN_WORD)
			count++;
		else if (is_redir_token(current->toktype) && current->next)
			current = current->next;
		current = current->next;
	}
	return (count);
}
