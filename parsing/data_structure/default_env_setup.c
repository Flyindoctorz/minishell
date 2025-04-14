/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_env_setup.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:55:37 by cgelgon           #+#    #+#             */
/*   Updated: 2025/04/14 18:56:20 by cgelgon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool	create_default_env_entries(t_data *minishell)
{
	t_env	*env_entries[] = {
		ft_envnew(ft_strdup("PATH"), ft_strdup("/usr/local/bin:/usr/bin:/bin")),
		ft_envnew(ft_strdup("HOME"), ft_strdup("/")),
		ft_envnew(ft_strdup("USER"), ft_strdup("user")),
		NULL
	};
	int i = 0;

	while (env_entries[i] != NULL)
	{
		if (!env_entries[i])
		{
			while (i > 0)
			{
				free(env_entries[i-1]->key);
				free(env_entries[i-1]->value);
				free(env_entries[i-1]);
				i--;
			}
			return (false);
		}
		ft_envaddback(&(minishell->env), env_entries[i]);
		i++;
	}
	return (true);
}
