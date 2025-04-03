/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_environment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:48:41 by cgelgon           #+#    #+#             */
/*   Updated: 2025/04/03 14:27:12 by cgelgon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	init_environment(t_data *data, char **envp)
{
	if (envp)
		data->envp = dup_env(envp);
	else
		data->envp = ft_calloc(1, sizeof(char *));
	if (!data->envp)
	{
		handle_error(MNSHL_ERR_MEMORY, "Environment initialization failed");
		return (MNSHL_ERR_ENV);
	}
	return (MNSHL_SUCCESS);
}

int	init_working_directory(t_data *data)
{
	data->cwd = init_cwd();
	if (!data->cwd)
	{
		handle_error(MNSHL_ERR_CWD, NULL);
		return (MNSHL_ERR_CWD);
	}
	return (MNSHL_SUCCESS);
}

char	*init_cwd(void)
{
	char	buffer[PATH_MAX];
	char	*cwd;

	if (!getcwd(buffer, PATH_MAX))
		return (NULL);
	cwd = ft_strdup(buffer);
	if (!cwd)
		return (NULL);
	return (cwd);
}

char	**dup_env(char **envp)
{
	char	**new_env;
	int		i;

	i = 0;
	while (envp && envp[i])
		i++;
	new_env = ft_calloc(i + 1, sizeof(char *));
	if (!new_env)
		return (NULL);
	i = 0;
	while (envp && envp[i])
	{
		new_env[i] = ft_strdup(envp[i]);
		if (!new_env[i])
		{
			free_env(new_env);
			return (NULL);
		}
		i++;
	}
	return (new_env);
}
