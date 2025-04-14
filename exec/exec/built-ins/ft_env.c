/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 02:22:55 by lmokhtar          #+#    #+#             */
/*   Updated: 2025/04/14 21:22:46 by lmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static void	env_print(t_env *env)
{
	while (env)
	{
		if (env->value != NULL)
			printf("%s=%s\n", env->key, env->value);
		env = env->next;
	}
}

int	ft_env(t_data *minishell, char **arg)
{
	int	i;

	i = 1;
	minishell->state = 0;
	while (arg[i])
	{
		if (arg[i][0] == '-')
		{
			ft_putstr_fd("env: ", 2);
			ft_putstr_fd(arg[i], 2);
			ft_putstr_fd(": Invalid option\n", 2);
			ft_putstr_fd("usage: env\n", 2);
			minishell->state = 1;
			return (minishell->state);
		}
		i++;
	}
	env_print(minishell->env);
	return (minishell->state);
}
