/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:32:42 by cgelgon           #+#    #+#             */
/*   Updated: 2025/04/15 17:08:44 by cgelgon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static t_data	*create_empty_data(void)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	if (!data)
	{
		handle_error(MNSHL_ERR_MEMORY, NULL);
		return (NULL);
	}
	data->prev_pipe_read_end = -1;
	data->token = NULL;
	data->command = NULL;
	data->state = 0;
	data->env = NULL;
	data->parsing = NULL;
	data->input = NULL;
	data->pid = 0;
	data->pipe_fd[0] = -1;
	data->pipe_fd[1] = -1;
	data->last_exit_status = 0;
	data->is_child = false;
	return (data);
}

// Crée et valide la structure t_data initiale
static t_data	*validate_args(int ac, char **av)
{
	t_data	*data;

	if (!av)
	{
		handle_error(MNSHL_ERR_ARGS, NULL);
		return (NULL);
	}
	data = create_empty_data();
	if (!data)
		return (NULL);
	data->ac = ac;
	data->av = av;
	data->exit = 0;
	data->nodenb = 0;
	return (data);
}

t_data	*init_data(int ac, char **av, char **envp)
{
	t_data	*data;
	int		status;

	data = validate_args(ac, av);
	if (!data)
		return (NULL);
	status = init_environment(data, envp);
	if (status == MNSHL_SUCCESS)
		status = init_working_directory(data);
	if (status != MNSHL_SUCCESS)
	{
		free_data(data);
		return (NULL);
	}
	return (data);
}
