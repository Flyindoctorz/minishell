/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 02:23:04 by lmokhtar          #+#    #+#             */
/*   Updated: 2025/04/14 18:39:56 by lmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

// Add this to exec/utils/export.c
void update_envp_array(t_data *minishell)
{
    t_env *current;
    int count = 0;
    int i = 0;
    
    if (minishell->envp)
        free_env(minishell->envp);
        
    // Count valid environment variables
    current = minishell->env;
    while (current)
    {
        if (current->key)
            count++;
        current = current->next;
    }
    
    minishell->envp = malloc(sizeof(char *) * (count + 1));
    if (!minishell->envp)
        return;
        
    current = minishell->env;
    i = 0;
    while (current)
    {
        if (current->key) {
            if (current->value)
                minishell->envp[i] = ft_strjoin3(current->key, "=", current->value);
            else
                minishell->envp[i] = ft_strdup(current->key);
            
            if (!minishell->envp[i])
            {
                free_env(minishell->envp);
                minishell->envp = NULL;
                return;
            }
            i++;
        }
        current = current->next;
    }
    minishell->envp[i] = NULL;
}

int	export_rule(char *str)
{
	int	i;

	i = 0;
	if (str[0] != '_' && ft_isalpha(str[0]) != 1)
		return (0);
	while (str[i] && str[i] != '=')
	{
		if (str[i] != '_' && ft_isalpha(str[i]) != 1 && ft_isnum(str[i]) != 1)
			return (0);
		i++;
	}
	return (1);
}

void	export_create(t_data *minishell, char *arg)
{
	t_env	*new;
	char	*key;
	char	*value;

	if (ft_strchr(arg, '='))
	{
		key = get_key(arg);
		value = get_value(arg);
		new = ft_envnew(key, value);
	}
	else
	{
		if (search_env(minishell->env, arg))
			return ;
		key = ft_strdup(arg);
		new = ft_envnew(key, NULL);
	}
	if (!search_env(minishell->env, key))
		ft_envaddback(&minishell->env, new);
	else
	{
		free(new);
		modify_value(minishell->env, key, value);
	}
}

int	ft_export(t_data *minishell, char **arg)
{
	int	i;

	minishell->state = 0;
	if (!arg[1])
	{
		export_print(minishell->env);
		return (minishell->state);
	}
	i = 1;
	while (arg[i])
	{
		if (!export_rule(arg[i]))
		{
			printf("bash: export: `%s': not a valid identifier\n", arg[i]);
			i++;
			minishell->state = 1;
			continue ;
		}
		export_create(minishell, arg[i]);
		i++;
	}
	update_envp_array(minishell);
	return (minishell->state);
}
