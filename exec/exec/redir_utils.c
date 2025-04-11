/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 02:23:39 by lmokhtar          #+#    #+#             */
/*   Updated: 2025/04/11 14:56:04 by lmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	open_input(t_heredoc *redir, t_data *minishell)
{
	int	fd;

	fd = open(redir->delimiter, O_RDONLY);
	if (fd == -1)
	{
		perror(redir->delimiter);
		ft_end(minishell);
		exit(EXIT_FAILURE);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
}

void	open_output(t_heredoc *redir, t_data *minishell)
{
	int	fd;

	if (redir->type == TOKEN_REDIR_OUT)
		fd = open(redir->delimiter, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (redir->type == TOKEN_APPEND)
		fd = open(redir->delimiter, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
	{
		perror(redir->delimiter);
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
	int			i;
	int			pipe_fd[2];

	i = 0;
	if (!redir || !minishell)
		return ;
	if (redir->fd >= 0)
	{
		dup2(redir->fd, STDIN_FILENO);
		close(redir->fd);
		redir->fd = -1;
	}
	else if (redir->content)
	{
		if (pipe(pipe_fd) == -1)
		{
			handle_error(MNSHL_ERR_PIPE, "open_heredoc pipe issues");
			return;
		}
		while(redir->content && redir->content[i])
		{
			ft_putendl_fd(redir->content[i], pipe_fd[1]);
			i++;
		}
	}
	close(pipe_fd[1]);
	dup2(pipe_fd[0], STDIN_FILENO);
	close(pipe_fd[0]);
}

int	open_redirections(t_cmd_list *cmd, t_data *minishell)
{
	t_heredoc	*redir;

	(void)minishell;
	redir = cmd->redir;
	while (redir != NULL)
	{
		if (redir->type == TOKEN_HEREDOC)
			open_heredoc(redir, minishell);
		else if (redir->type == TOKEN_REDIR_IN)
			open_input(redir, minishell);
		else
			open_output(redir, minishell);
		redir = redir->next;
	}
	return (EXIT_SUCCESS);
}
