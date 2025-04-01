/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:42:14 by cgelgon           #+#    #+#             */
/*   Updated: 2025/04/01 14:33:26 by lmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/data.h"

// regroupe les fonctions destinees a free/clean

// reprend error code de minishell.h
static int	convert_error_code(int mnshl_code)
{
	if (mnshl_code == MNSHL_SUCCESS)
		return (EXIT_SUCCESS);
	if (mnshl_code == MNSHL_ERR_MEMORY)
		return (EXIT_FAILURE);
	if (mnshl_code == MNSHL_ERR_ARGS)
		return (EXIT_FAILURE);
	if (mnshl_code == MNSHL_ERR_ENV)
		return (EXIT_FAILURE);
	if (mnshl_code == MNSHL_ERR_CWD)
		return (127);
	if (mnshl_code == MNSHL_ERR_PIPE)
		return (1);
	if (mnshl_code == MNSHL_ERR_FORK)
		return (1);
	if (mnshl_code == MNSHL_ERR_EXEC)
		return (127);
	return (1);
}

static void	close_all_fds(t_data *data)
{
	if (!data)
		return ;
	if (data->prev_pipe_read_end != -1)
	{
		close(data->prev_pipe_read_end);
		data->prev_pipe_read_end = -1;
	}
}

/*
** Assure une sortie propre du programme
** @param data: structure principale à libérer
** @param mnshl_code: code d'erreur minishell
*/
void	clean_exit(t_data *data, int mnshl_code)
{
	int	exit_code;

	if (!data)
		exit(convert_error_code(mnshl_code));
	if (mnshl_code == -1)
		exit_code = data->exit;
	else
		exit_code = convert_error_code(mnshl_code);
	if (mnshl_code != MNSHL_SUCCESS)
		handle_error(mnshl_code, NULL);
	close_all_fds(data);
	free_data(data);
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	exit(exit_code);
}

void	free_env(char **env)
{
	int	i;

	if (!env)
		return ;
	i = 0;
	while (env[i])
		free(env[i++]);
	free(env);
}

void	free_data(t_data *data)
{
	if (!data)
		return ;
	if (data->token)
		ft_tokenclear(&data->token);
	if (data->command)
		ft_commandclear(&data->command);
	if (data->env)
		ft_envclear(&data->env);
	if (data->parsing)
		free(data->parsing);
	if (data->input)
		free(data->input);
	if (data->pipe_fd[0] != -1)
		close(data->pipe_fd[0]);
	if (data->pipe_fd[1] != -1)
		close(data->pipe_fd[1]);
	free_env(data->envp);
	free(data->cwd);
	free(data);
}

void	ft_commandclear(t_cmd_list **cmd)
{
	t_cmd_list	*current;
	t_cmd_list	*next;

	if (!cmd || !*cmd)
		return ;
	current = *cmd;
	while (current)
	{
		next = current->next;
		if (current->arguments)
			free_array(current->arguments);
		if (current->redir)
			ft_redirclear(current->redir);
		free(current);
		current = next;
	}
	*cmd = NULL;
}
