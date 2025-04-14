/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 02:23:18 by lmokhtar          #+#    #+#             */
/*   Updated: 2025/04/14 18:39:36 by lmokhtar         ###   ########.fr       */
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

void ft_tabupdate(t_data *minishell)
{
    t_env *env;
    int count = 0;
    int i;
    
    // Free existing envp if it exists
    if (minishell->envp)
        free_env(minishell->envp);
    
    // Count valid environment variables
    env = minishell->env;
    while (env)
    {
        if (env->key) // Only count nodes with valid keys
            count++;
        env = env->next;
    }
    
    // Allocate the new array
    minishell->envp = malloc(sizeof(char *) * (count + 1));
    if (!minishell->envp)
        return;
    
    // Fill the array
    env = minishell->env;
    i = 0;
    while (env)
    {
        if (env->key) { // Only process nodes with valid keys
            if (env->value)
                minishell->envp[i] = ft_strjoin3(env->key, "=", env->value);
            else
                minishell->envp[i] = ft_strdup(env->key);
            
            if (!minishell->envp[i])
            {
                free_env(minishell->envp);
                minishell->envp = NULL;
                return;
            }
            i++;
        }
        env = env->next;
    }
    minishell->envp[i] = NULL; // Terminate the array properly
}
