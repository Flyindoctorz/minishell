/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_expand_in_quotes.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 13:52:58 by cgelgon           #+#    #+#             */
/*   Updated: 2025/04/15 13:53:23 by cgelgon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool	was_in_single_quotes(const char *arg, t_token *tokens)
{
	t_token	*current;

	current = tokens;
	while (current)
	{
		if (current->toktype == TOKEN_QUOTES && current->value
			&& ft_strcmp(current->value, arg) == 0)
			return (true);
		current = current->next;
	}
	return (false);
}

bool	expand_command_args(t_cmd_list *cmd, t_data *data)
{
	int		i;
	char	*expanded;
	t_token	*token;

	token = data->token;
	if (!cmd || !cmd->av)
		return (true);
	i = 0;
	while (cmd->av[i])
	{
		if (ft_strchr(cmd->av[i], '$') && !was_in_single_quotes(cmd->av[i],
				token))
		{
			expanded = expand(cmd->av[i], data);
			if (expanded)
			{
				free(cmd->av[i]);
				cmd->av[i] = expanded;
			}
		}
		i++;
	}
	return (true);
}
