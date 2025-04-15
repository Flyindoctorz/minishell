/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_finalize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 13:55:22 by cgelgon           #+#    #+#             */
/*   Updated: 2025/04/15 14:13:30 by cgelgon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool	setup_cmd_redir(t_cmd_list *cmd)
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
		return (false);
	}
	return (true);
}

t_cmd_list	*finalize_parsing(t_cmd_list *cmd_list, t_token *tokens,
		t_data *data)
{
	t_cmd_list *cmd;

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
		if (!setup_cmd_redir(cmd))
		{
			ft_commandclear(&cmd_list);
			return (NULL);
		}
		cmd = cmd->next;
	}
	return (cmd_list);
}