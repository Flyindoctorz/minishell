/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_empty_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:02:52 by cgelgon           #+#    #+#             */
/*   Updated: 2025/04/15 16:59:11 by cgelgon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*create_env_entry(char *key, char *value)
{
	return (ft_strjoin3(key, "=", value));
}

static void	free_env_entries(char **entries, int count)
{
	int i;

	i = 0;
	while(i < count)
	{
		free(entries[i]);
		i++;
	}
	free(entries);
}

char	**create_minimal_envp(char *cwd)
{
	char	**envp;

	envp = ft_calloc(4, sizeof(char *));
	if (!envp)
		return (NULL);
	envp[0] = create_env_entry("PWD", cwd);
	envp[1] = create_env_entry("SHLVL", "1");
	envp[2] = create_env_entry("_", "/usr/bin/env");
	envp[3] = NULL;
	if (!envp[0] || !envp[1] || !envp[2])
	{
		free_env_entries(envp, 3);
		return (NULL);
	}
	return (envp);
}

bool	init_minimal_env_vars(t_data *data)
{
	t_env	*pwd;
	t_env	*shlvl;
	t_env	*underscore;

	pwd = ft_envnew(ft_strdup("PWD"), ft_strdup(data->cwd));
	if (!pwd)
		return (false);
	ft_envaddback(&data->env, pwd);
	shlvl = ft_envnew(ft_strdup("SHLVL"), ft_strdup("1"));
	if (!shlvl)
		return (false);
	ft_envaddback(&data->env, shlvl);
	underscore = ft_envnew(ft_strdup("_"), ft_strdup("/usr/bin/env"));
	if (!underscore)
		return (false);
	ft_envaddback(&data->env, underscore);
	return (true);
}

bool	create_minimal_env(t_data *data)
{
	if (!init_minimal_env_vars(data))
		return (false);
	free_env(data->envp);
	data->envp = create_minimal_envp(data->cwd);
	if (!data->envp)
		return (false);
	return (true);
}
/*
int	init_data_resources(t_data *data, char **env)
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

	if (!env || !env[0])
	{
		return (create_minimal_env(data) ? 1 : 0);
	}

	if (!init_env(env, data))
	{
		free_env(data->envp);
		free(data->cwd);
		return (0);
	}
	return (1);
}*/