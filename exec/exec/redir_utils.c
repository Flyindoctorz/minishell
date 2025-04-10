/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 02:23:39 by lmokhtar          #+#    #+#             */
/*   Updated: 2025/04/10 15:53:42 by lmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	open_input(t_token *redir, t_data *minishell)
{
	int			fd;
	t_cmd_list	*cmd;

	(void)redir;
	cmd = minishell->command;
	fd = open(cmd->input_file, O_RDONLY);
	if (fd == -1)
	{
		perror(cmd->input_file);
		ft_end(minishell);
		exit(EXIT_FAILURE);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
}

void	open_output(t_token *redir, t_data *minishell)
{
	int			fd;
	t_cmd_list	*cmd;

	cmd = minishell->command;
	if (redir->toktype == TOKEN_REDIR_OUT)
		fd = open(cmd->output_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (redir->toktype == TOKEN_APPEND)
		fd = open(cmd->output_file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
	{
		perror(cmd->output_file);
		ft_end(minishell);
		exit(EXIT_FAILURE);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
}

void	free_all_heredoc(t_cmd_list *cmd)
{
	while (cmd)
	{
		if (cmd->redir && cmd->redir->content)
			free_tab(cmd->redir->content);
		cmd = cmd->next;
	}
}

void	open_heredoc(t_heredoc *redir, t_data *minishell)
{
	int			fd[2];
	int			i;
	t_cmd_list	*cmd;

	cmd = minishell->command;
	i = 0;
	(void)minishell;
	if (pipe(fd) == -1)
	{
		printf("pipe error :");
		ft_end(minishell);
		exit(-1);
	}
	while (redir->content && redir->content[i])
	{
		ft_putendl_fd(redir->content[i], fd[1]);
		i++;
	}
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
}

int	open_redirections(t_cmd_list *cmd, t_data *minishell)
{
	t_heredoc	*redir;

	if (!cmd)
		return (EXIT_FAILURE);
	if (cmd->fd_in != STDIN_FILENO && cmd->fd_in != -1)
	{
		dup2(cmd->fd_in, STDIN_FILENO);
		close(cmd->fd_in);
		cmd->fd_in = -1;
	}
	if (cmd->fd_out != STDOUT_FILENO && cmd->fd_out != -1)
	{
		dup2(cmd->fd_out, STDOUT_FILENO);
		close(cmd->fd_out);
		cmd->fd_out = -1;
	}
	redir = cmd->redir;
	while (redir)
	{
		if (redir->type == TOKEN_HEREDOC)
			open_heredoc(redir, minishell);
		redir = redir->next;
	}
	return (EXIT_SUCCESS);
}
