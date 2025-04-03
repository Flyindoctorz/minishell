/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:42:46 by lmokhtar          #+#    #+#             */
/*   Updated: 2025/04/03 14:46:34 by lmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	search_env(t_env *env, char *key)
{
	int	i;

	i = 1;
	while (env)
	{
		if (ft_strcmp(env->key, key) == 0)
			return (i);
		env = env->next;
		i++;
	}
	return (0);
}

void	export_print(t_env *env)
{
	while (env)
	{
		if (!env->value)
			printf("export %s\n", env->key);
		else
			printf("export %s=%s\n", env->key, env->value);
		env = env->next;
	}
}

void	modify_value(t_env *env, char *key, char *value)
{
	while (ft_strcmp(env->key, key) != 0)
		env = env->next;
	free(key);
	free(env->value);
	env->value = value;
}

char	*get_key(char *str)
{
	int		i;
	char	*key;

	i = 0;
	while (str[i] != '=')
		i++;
	key = malloc(sizeof(char) * i + 1);
	if (!key)
		return (NULL);
	i = 0;
	while (str[i] != '=')
	{
		key[i] = str[i];
		i++;
	}
	key[i] = 0;
	return (key);
}
