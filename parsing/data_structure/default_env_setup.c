/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_env_setup.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:55:37 by cgelgon           #+#    #+#             */
/*   Updated: 2025/04/15 17:08:57 by cgelgon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

#include "../../include/minishell.h"

static bool	create_default_env_entries_cleanup(t_env **env_entries, int index)
{
	while (index > 0)
	{
		free(env_entries[index - 1]->key);
		free(env_entries[index - 1]->value);
		free(env_entries[index - 1]);
		index--;
	}
	return (false);
}

bool	create_default_env_entries(t_data *minishell)
{
	t_env	*env_entries[4];
	int		i;

	env_entries[0] = ft_envnew(ft_strdup("PATH"),
			ft_strdup("/usr/local/bin:/usr/bin:/bin"));
	env_entries[1] = ft_envnew(ft_strdup("HOME"), ft_strdup("/"));
	env_entries[2] = ft_envnew(ft_strdup("USER"), ft_strdup("user"));
	env_entries[3] = NULL;
	i = 0;
	while (env_entries[i] != NULL)
	{
		if (!env_entries[i])
			return (create_default_env_entries_cleanup(env_entries, i));
		ft_envaddback(&(minishell->env), env_entries[i]);
		i++;
	}
	return (true);
}
