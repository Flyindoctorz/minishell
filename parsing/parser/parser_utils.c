/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 11:57:17 by cgelgon           #+#    #+#             */
/*   Updated: 2025/04/07 16:48:05 by lmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool	is_redir_token(t_token_type type)
{
	return (type == TOKEN_REDIR_IN || type == TOKEN_REDIR_OUT
		|| type == TOKEN_APPEND || type == TOKEN_HEREDOC);
}

// void free_cmd_list(t_cmd_list *cmd_list)
// {
//     t_cmd_list *temp;

//     while (cmd_list)
//     {
//         temp = cmd_list;
//         cmd_list = cmd_list->next;
//         if (temp->cmd)
//             free(temp->cmd);
//         if (temp->av)
//             free_tab(temp->av);
//         if (temp->input_file)
//             free(temp->input_file);
//         if (temp->output_file)
//             free(temp->output_file);
//         if (temp->delimiter)
//             free(temp->delimiter);
//         free(temp);
//     }
// }
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
		else if (is_redir(current) && current->next)
			current = current->next;
		current = current->next;
	}
	av[i] = NULL;
	return (av);
}

int	count_args(t_token *tokens)

{
	int count;
	t_token *current;

	count = 0;
	current = tokens;
	while (current)
	{
		if (current->toktype == TOKEN_WORD)
			count++;
		else if (is_redir(current) && current->next)
			current = current->next;
		current = current->next;
	}
	return (count);
}
