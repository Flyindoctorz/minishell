/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 02:23:39 by lmokhtar          #+#    #+#             */
/*   Updated: 2025/04/14 17:56:25 by cgelgon          ###   ########.fr       */
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
		// exit(EXIT_FAILURE);
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
