/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 02:23:45 by lmokhtar          #+#    #+#             */
/*   Updated: 2025/04/10 16:39:24 by cgelgon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	set_signal_child(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}

int	sig_event(void)
{
	return (EXIT_SUCCESS);
}

void	signal_handler(int sig)
{
	if (sig == SIGINT)
	{
		rl_done = 1;
		g_signal = sig + 128;
	}
}

void	ft_signal(void)
{
	rl_event_hook = sig_event;
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
}
void handle_heredoc_signal(int sig)
{
    if (sig == SIGINT)
    {
        g_signal = sig;
        rl_done = 1;
        write(STDOUT_FILENO, "\n", 1);
    }
}

void setup_heredoc_signals(void)
{
    struct sigaction sa;
    
    ft_memset(&sa, 0, sizeof(sa));
    sa.sa_handler = handle_heredoc_signal;
    sigaction(SIGINT, &sa, NULL);
    signal(SIGQUIT, SIG_IGN);
}

void restore_default_signals(void)
{
    ft_signal();
}