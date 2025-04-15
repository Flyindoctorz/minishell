/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 02:23:18 by lmokhtar          #+#    #+#             */
/*   Updated: 2025/04/15 16:20:27 by lmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static bool	delete_node(t_env **env, char *to_delete)
{
	int	flag;
	int	len;

	len = count_env(*env);
	flag = search_env(*env, to_delete);
	if (flag == 0)
		return (0);
	if (flag == 1)
		remove_first(env);
	else if (flag == len + 1)
		remove_last(*env);
	else
		remove_node(*env, to_delete);
	return (1);
}

int	ft_unset(t_data *minishell, char **arg)
{
	int	i;

	minishell->state = 0;
	i = 1;
	if (!arg[1])
		return (minishell->state);
	while (arg[i])
	{
		if (!delete_node(&minishell->env, arg[i]))
			i++;
		else
			i++;
	}
	return (minishell->state);
}

static void	allocate_envp(t_data *minishell, int count)
{
	minishell->envp = malloc(sizeof(char *) * (count + 1));
	if (!minishell->envp)
		return ;
}

char	*create_env_string(t_env *env)
{
	if (env->value)
		return (ft_strjoin3(env->key, "=", env->value));
	else
		return (ft_strdup(env->key));
}

void	ft_tabupdate(t_data *minishell)
{
	t_env	*env;
	int		count;

	count = 0;
	if (minishell->envp)
		free_env(minishell->envp);
	env = minishell->env;
	while (env)
	{
		if (env->key)
			count++;
		env = env->next;
	}
	allocate_envp(minishell, count);
	if (!minishell->envp)
		return ;
	fill_envp_array(minishell);
}
