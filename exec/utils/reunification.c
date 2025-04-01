/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reunification.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:15:47 by cgelgon           #+#    #+#             */
/*   Updated: 2025/04/01 14:18:11 by cgelgon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

volatile sig_atomic_t	g_signal = 0;

int	main(int ac, char **av, char **envp)
{
	t_data	*data;

	(void)ac;
	(void)av;

	data = init_data(ac, av, envp);
	if (!data)
		return (1);
	setup_signal();
	
}