/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 02:23:29 by lmokhtar          #+#    #+#             */
/*   Updated: 2025/04/07 15:18:24 by lmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	execut_me(t_cmd_list *cmd, t_data *shell, int save[2], int fd[2])
{
	int	status;

	set_signal_child();
	if (cmd->next)
		dup2(fd[1], STDOUT_FILENO);
	(close(save[0]), close(save[1]));
	(close(fd[0]), close(fd[1]));
	open_redirections(cmd, shell);
	if (cmd->av == NULL)
	{
		free_all_heredoc(shell->command);
		ft_end(shell);
		exit(EXIT_SUCCESS);
	}
	if (is_a_builtin(cmd->av) == true)
	{
		status = builtins(shell, cmd);
		ft_end(shell);
		exit(status);
	}
	ft_tabupdate(shell);
	excute(cmd->av, shell->envp, shell);
}

int	all_cmd(t_data *minishell, int save[2], t_cmd_list *cmd)
{
	int	fd[2];

	if (pipe(fd) == -1)
		return (1);
	cmd->pid = fork();
	if (cmd->pid == -1)
		return (close(fd[0]), close(fd[1]), -1);
	if (cmd->pid == 0)
		execut_me(cmd, minishell, save, fd);
	dup2(fd[0], STDIN_FILENO);
	(close(fd[0]), close(fd[1]));
	return (1);
}

void	check_signal_exec(t_data *minishell)
{
	if (minishell->state == 128 + SIGINT)
		printf("\n");
	else if (minishell->state == 128 + SIGQUIT)
		printf("Quit (core dumped)\n");
}

void	waiter(t_cmd_list *cmd, t_data *minishell)
{
	while (cmd)
	{
		waitpid(cmd->pid, &minishell->state, 0);
		if (WIFEXITED(minishell->state))
			minishell->state = WEXITSTATUS(minishell->state);
		else if (WIFSIGNALED(minishell->state))
			minishell->state = 128 + WTERMSIG(minishell->state);
		else if (WIFSTOPPED(minishell->state))
			minishell->state = 128 + WSTOPSIG(minishell->state);
		cmd = cmd->next;
	}
}

bool	exec(t_cmd_list *cmd, t_data *minishell)
{
	int	save[2];

	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
	if (!cmd->next && is_a_builtin(cmd->av))
		return (builtins(minishell, cmd), 1);
	save[STDIN_FILENO] = dup(STDIN_FILENO);
	save[STDOUT_FILENO] = dup(STDOUT_FILENO);
	while (cmd)
	{
		all_cmd(minishell, save, cmd);
		cmd = cmd->next;
	}
	cmd = minishell->command;
	waiter(cmd, minishell);
	free_all_heredoc(minishell->command);
	dup2(save[STDIN_FILENO], STDIN_FILENO);
	dup2(save[STDOUT_FILENO], STDOUT_FILENO);
	(close(save[0]), close(save[1]));
	check_signal_exec(minishell);
	return (0);
}
