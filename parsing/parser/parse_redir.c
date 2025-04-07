/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:31:49 by cgelgon           #+#    #+#             */
/*   Updated: 2025/04/07 16:26:02 by lmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool	set_input_file(t_cmd_list *cmd, char *filename)
{
	if (!cmd || !filename)
		return (false);
	if (cmd->input_file)
		free(cmd->input_file);
	cmd->input_file = ft_strdup(filename);
	if (!cmd->input_file)
		return (false);
	return (true);
}

bool	set_output_file(t_cmd_list *cmd, char *filename, bool append)
{
	if (!cmd || !filename)
		return (false);
	if (cmd->output_file)
		free(cmd->output_file);
	cmd->output_file = ft_strdup(filename);
	if (!cmd->output_file)
		return (false);
	cmd->append = append;
	return (true);
}

bool	handle_redir(t_cmd_list *cmd, t_token *token, t_data *data)
{
	t_token_type	type;
	char			*filename;

	if (!cmd || !token || !token->next || !token->next->value || !data)
		return (false);
	type = token->toktype;
	filename = token->next->value;
	if (type == TOKEN_REDIR_IN)
		return (set_input_file(cmd, filename));
	else if (type == TOKEN_REDIR_OUT)
		return (set_output_file(cmd, filename, false));
	else if (type == TOKEN_APPEND)
		return (set_output_file(cmd, filename, true));
	else if (type == TOKEN_HEREDOC)
	{
		cmd->heredoc = true;
		cmd->delimiter = ft_strdup(filename);
		return (cmd->delimiter != NULL);
	}
	return (false);
}

bool	setup_redir(t_cmd_list *cmd)
{
	int	flags;

	if (!cmd)
		return (false);
	if (cmd->input_file)
	{
		cmd->fd_in = open(cmd->input_file, O_RDONLY);
		if (cmd->fd_in < 0)
			return (false);
	}
	if (cmd->output_file)
	{
		flags = O_WRONLY | O_CREAT;
		if (cmd->append)
			flags |= O_APPEND;
		else
			flags |= O_TRUNC;
		cmd->fd_out = open(cmd->output_file, flags, 0644);
		if (cmd->fd_out < 0)
			return (false);
		return (true);
	}
	return (true);
}
