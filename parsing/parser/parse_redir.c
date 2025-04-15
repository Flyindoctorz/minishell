/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:31:49 by cgelgon           #+#    #+#             */
/*   Updated: 2025/04/15 16:45:13 by lmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static bool	process_input_redirection(t_cmd_list *cmd, char *filename)
{
	return (set_input_file(cmd, filename));
}

static bool	process_output_redirection(t_cmd_list *cmd, char *filename,
		t_token_type type)
{
	bool	append;

	append = (type == TOKEN_APPEND);
	return (set_output_file(cmd, filename, append));
}

static bool	process_heredoc(t_cmd_list *cmd, char *filename)
{
	cmd->heredoc = true;
	if (cmd->delimiter)
		free(cmd->delimiter);
	cmd->delimiter = ft_strdup(filename);
	if (!cmd->delimiter)
		return (false);
	return (true);
}

bool	handle_redir(t_cmd_list *cmd, t_token *token, t_data *data)
{
	t_token_type	type;
	char			*filename;
	t_heredoc		*new_redir;

	if (!cmd || !token || !token->next || !token->next->value || !data)
		return (false);
	type = token->toktype;
	filename = token->next->value;
	if (type == TOKEN_REDIR_IN && !process_input_redirection(cmd, filename))
		return (false);
	else if ((type == TOKEN_REDIR_OUT || type == TOKEN_APPEND)
		&& !process_output_redirection(cmd, filename, type))
		return (false);
	else if (type == TOKEN_HEREDOC && !process_heredoc(cmd, filename))
		return (false);
	new_redir = ft_redirnew(ft_strdup(filename), type, data);
	if (!new_redir)
		return (false);
	ft_rediraddback(&cmd->redir, new_redir);
	return (true);
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
	}
	return (true);
}
