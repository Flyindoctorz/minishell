/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:41:01 by lmokhtar          #+#    #+#             */
/*   Updated: 2025/04/15 16:07:56 by lmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_envaddback(t_env **head, t_env *new)
{
	if (!head)
		return ;
	if (*head)
		ft_envlast(*head)->next = new;
	else
		*head = new;
}

t_env	*ft_envnew(char *key, char *value)
{
	t_env	*env;

	env = malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	env->key = key;
	env->value = value;
	env->next = NULL;
	return (env);
}

t_env	*ft_envlast(t_env *head)
{
	while (head->next)
		head = head->next;
	return (head);
}

void	ft_envclear(t_env **env)
{
	t_env	*tmp;

	while ((*env))
	{
		tmp = (*env)->next;
		free((*env)->key);
		free((*env)->value);
		free((*env));
		(*env) = tmp;
	}
}

bool	init_env(char **env, t_data *minishell)
{
	int		i;
	t_env	*env_t;

	i = 0;
	if (!env || !env[0])
		return (create_default_env_entries(minishell));
	while (env[i])
	{
		env_t = ft_envnew(get_key(env[i]), get_value(env[i]));
		if (!env_t)
			return (ft_envclear(&minishell->env), 0);
		ft_envaddback(&(minishell->env), env_t);
		i++;
	}
	return (1);
}
