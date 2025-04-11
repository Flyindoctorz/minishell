/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:17:52 by lmokhtar          #+#    #+#             */
/*   Updated: 2025/04/11 18:13:09 by lmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

volatile sig_atomic_t	g_signal = 0;

static int	init_data_resources(t_data *data, char **env)
{
	data->envp = dup_env(env);
	if (!data->envp)
		return (0);
	data->cwd = init_cwd();
	if (!data->cwd)
	{
		free_env(data->envp);
		return (0);
	}
	if (!init_env(env, data))
	{
		free_env(data->envp);
		free(data->cwd);
		return (0);
	}
	return (1);
}

static t_data	*init_shell(char **env)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->token = NULL;
	data->command = NULL;
	data->env = NULL;
	data->state = 0;
	data->prev_pipe_read_end = -1;
	if (!init_data_resources(data, env))
	{
		ft_end(data);
		return (NULL);
	}
	return (data);
}

static int	process_input(t_data *data, char *input)
{
	if (!input)
		return (0);
	if (g_signal != 0)
	{
		data->state = g_signal;
		g_signal = 0;
		return (1);
	}
	if (!*input)
		return (1);
	add_history(input);
	data->token = tokenize_input(input, data);
	if (!data->token)
		return (1);
	data->command = parse_token(data->token, data);
	if (!data->command)
	{
		ft_tokenclear(&data->token);
		return (1);
	}
	exec(data->command, data);
	ft_tokenclear(&data->token);
	ft_commandclear(&data->command);
	free((data->token = 0, data->command = 0, NULL));
	return (1);
}

static void	run_shell(t_data *data)
{
	char	*input;

	while (1)
	{
		ft_signal();
		input = readline("$>");
		if (!process_input(data, input))
		{
			free(input);
			break ;
		}
		free(input);
	}
	rl_clear_history();
}

int	main(int ac, char **av, char **env)
{
	t_data	*data;
	int		exit_status;

	// env -i qui ne fonctionne pas comme attendu on doit prendre qques variables par defaut
	(void)ac;
	(void)av;
	if (!isatty(0))
	{
		printf("minishell: tty required\n");
		return (1);
	}
	data = init_shell(env);
	if (!data)
		return (1);
	run_shell(data);
	exit_status = data->state;
	ft_end(data);
	return (exit_status);
}
