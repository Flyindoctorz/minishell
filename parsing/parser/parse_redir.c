/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:13:45 by cgelgon           #+#    #+#             */
/*   Updated: 2025/04/03 17:30:15 by lmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool	set_input_redir(t_cmd_list *cmd, char *filename)
{
	if (!cmd || !filename)
		return (false);
	if (cmd->input_redir)
		free(cmd->input_redir);
	cmd->input_redir = ft_strdup(filename);
	if (!cmd->input_redir)
		return (false);
	return (true);
}

bool	set_output_redir(t_cmd_list *cmd, char *filename)
{
	if (!cmd || !filename)
		return (false);
	if (cmd->output_redir)
		free(cmd->output_redir);
	cmd->output_redir = ft_strdup(filename);
	if (!cmd->output_redir)
		return (false);
	return (true);
}

bool	set_heredoc(t_cmd_list *cmd, char *delimiter)
{
	if (!cmd || !delimiter)
		return (false);
	if (cmd->delimiter)
		free(cmd->delimiter);
	cmd->heredoc = ft_strdup(delimiter);
	if (!cmd->heredoc)
		return (false);
	cmd->heredoc = true;
	return (true);
}

bool	setup_redir(t_cmd_list *cmd)
{
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
		if (cmd->append)
			cmd->fd_out = open(cmd->output_file, O_WRONLY | O_CREAT | O_APPEND,
					0644);
		else
			cmd->fd_out = open(cmd->output_file, O_WRONLY | O_CREAT | O_TRUNC,
					0644);
		if (cmd->fd_out < 0)
			return (false);
	}
	return (true);
}

bool	handle_heredoc_input(t_cmd_list *cmd)
{
	int		pipe_fd[2];
	char	*line;

	if (!cmd || cmd->delimiter)
		return (false);
	if (pipe(pipe_fd) < 0)
		return (false);
	while (1)
	{
		line = readline("> ");
		if (!line)
			break ;
		if (ft_strcmp(line, cmd->delimiter) == 0)
		{
			free(line);
			break ;
		}
		write(pipe_fd[1], line, ft_strlen(line));
		write(pipe_fd[1], "\n", 1);
		free(line);
	}
	close(pipe_fd[1]);
	cmd->fd_in = pipe_fd[0];
	return (true);
}
