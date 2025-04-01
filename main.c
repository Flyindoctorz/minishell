/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 19:00:00 by lmokhtar          #+#    #+#             */
/*   Updated: 2025/04/01 14:12:02 by lmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

volatile sig_atomic_t	g_signal = 0;

static void	init_shell(t_data *minishell, char **env)
{
	minishell->ac = 0;
	minishell->av = NULL;
	minishell->envp = dup_env(env);
	minishell->cwd = init_cwd();
	minishell->exit = 0;
	minishell->nodenb = 0;
	minishell->prev_pipe_read_end = -1;
	minishell->token = NULL;
	minishell->command = NULL;
	minishell->state = 0;
}

static void	cleanup_shell(t_data *minishell)
{
	if (minishell->token)
		ft_tokenclear(&minishell->token);
	if (minishell->command)
		ft_commandclear(&minishell->command);
	if (minishell->envp)
		free_env(minishell->envp);
	if (minishell->cwd)
		free(minishell->cwd);
}

static int	process_input(t_data *minishell, char *input)
{
	if (g_signal != 0)
	{
		minishell->state = g_signal;
		g_signal = 0;
		return (1);
	}
	if (!input)
		return (0);
	if (!*input)
		return (1);
	add_history(input);
	minishell->token = tokenize_input(input, minishell);
	if (!minishell->token)
		return (1);
	minishell->command = parse_tokens(minishell->token, minishell);
	if (!minishell->command)
	{
		ft_tokenclear(&minishell->token);
		return (1);
	}
	exec(minishell->command, minishell);
	ft_tokenclear(&minishell->token);
	ft_commandclear(&minishell->command);
	return (1);
}

int	main_loop(t_data *minishell)
{
	char	*input;

	while (1)
	{
		ft_signal();
		input = readline("$> ");
		if (!process_input(minishell, input))
			break ;
		free(input);
	}
	return (0);
}

int	main(int ac, char **av, char **env)
{
	t_data	minishell;
	
	(void)ac;
	(void)av;
	if (!isatty(0))
		return (printf("minishell: tty required\n"), 1);
	init_shell(&minishell, env);
	main_loop(&minishell);
	cleanup_shell(&minishell);
	return (minishell.exit);
}
