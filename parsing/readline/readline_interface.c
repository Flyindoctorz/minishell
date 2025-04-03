/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_interface.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:28:58 by cgelgon           #+#    #+#             */
/*   Updated: 2025/04/03 17:30:01 by lmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// variable globale pour le signal
// @volatile pour eviter l'optimisation
// @atomic pour eviter les problemes de concurrence
static volatile sig_atomic_t	g_signal_status = 0;

// fonction de gestion du signal
static void	handle_signal(int signum)
{
	g_signal_status = signum;
	if (signum == SIGINT)
	{
		write(STDOUT_FILENO, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

// renvoie le status du signal et reinit variable globale
int	get_signal_status(void)
{
	int	status;

	status = g_signal_status;
	g_signal_status = 0;
	return (status);
}

void	setup_signal(void)
{
	struct sigaction	sa;

	ft_memset(&sa, 0, sizeof(sa));
	sa.sa_handler = handle_signal;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGQUIT, &sa, NULL);
}

void	reset_sig_to_default(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}
