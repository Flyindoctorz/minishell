/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_main2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:32:20 by lmokhtar          #+#    #+#             */
/*   Updated: 2025/04/15 16:32:57 by lmokhtar         ###   ########.fr       */
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

static bool	check_and_handle_redir_errors(t_cmd_list *cmd,
		t_cmd_list **cmd_list)
{
	if (!setup_redir(cmd))
	{
		ft_putstr_fd("minishell: ", 2);
		if (cmd->input_file)
			perror(cmd->input_file);
		else if (cmd->output_file)
			perror(cmd->output_file);
		else
			perror("redirection");
		ft_commandclear(cmd_list);
		return (false);
	}
	return (true);
}

t_cmd_list	*finalize_parsing(t_cmd_list *cmd_list, t_token *tokens,
		t_data *data)
{
	t_cmd_list	*cmd;

	(void)tokens;
	if (!cmd_list || !cmd_list->av)
	{
		ft_commandclear(&cmd_list);
		return (NULL);
	}
	cmd = cmd_list;
	while (cmd)
	{
		expand_command_args(cmd, data);
		if (!check_and_handle_redir_errors(cmd, &cmd_list))
			return (NULL);
		cmd = cmd->next;
	}
	return (cmd_list);
}
