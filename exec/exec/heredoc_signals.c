/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_signals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:21:14 by lmokhtar          #+#    #+#             */
/*   Updated: 2025/04/15 16:25:30 by lmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	setup_heredoc_signals(void)
{
	struct sigaction	sa;

	ft_memset(&sa, 0, sizeof(sa));
	sa.sa_handler = handle_heredoc_signal;
	sigaction(SIGINT, &sa, NULL);
	signal(SIGQUIT, SIG_IGN);
}

void	restore_default_signals(void)
{
	ft_signal();
}

bool	exec_cleanup(t_data *minishell, int save[2])
{
	t_cmd_list	*cmd;

	cmd = minishell->command;
	waiter(cmd, minishell);
	free_all_heredoc(minishell->command);
	dup2(save[STDIN_FILENO], STDIN_FILENO);
	dup2(save[STDOUT_FILENO], STDOUT_FILENO);
	(close(save[0]), close(save[1]));
	check_signal_exec(minishell);
	return (0);
}
