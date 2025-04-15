/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:18:03 by lmokhtar          #+#    #+#             */
/*   Updated: 2025/04/15 16:18:42 by lmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static void	set_env_value(t_data *minishell, t_env *current, int *i)
{
	if (current->key)
	{
		if (current->value)
			minishell->envp[*i] = ft_strjoin3(current->key, "=",
					current->value);
		else
			minishell->envp[*i] = ft_strdup(current->key);
		if (!minishell->envp[*i])
		{
			free_env(minishell->envp);
			minishell->envp = NULL;
			return ;
		}
		(*i)++;
	}
}

static int	count_env_entries(t_env *env)
{
	t_env	*current;
	int		count;

	count = 0;
	current = env;
	while (current)
	{
		if (current->key)
			count++;
		current = current->next;
	}
	return (count);
}

void	update_envp_array(t_data *minishell)
{
	t_env	*current;
	int		count;
	int		i;

	if (minishell->envp)
		free_env(minishell->envp);
	count = count_env_entries(minishell->env);
	minishell->envp = malloc(sizeof(char *) * (count + 1));
	if (!minishell->envp)
		return ;
	current = minishell->env;
	i = 0;
	while (current)
	{
		set_env_value(minishell, current, &i);
		if (!minishell->envp)
			return ;
		current = current->next;
	}
	minishell->envp[i] = NULL;
}
