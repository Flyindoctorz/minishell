/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 02:23:01 by lmokhtar          #+#    #+#             */
/*   Updated: 2025/03/27 02:23:02 by lmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*trim_spaces(char *str)
{
	char	*end;

	while (ft_isspace(*str))
		str++;
	end = str + ft_strlen(str) - 1;
	while (end > str && ft_isspace(*end))
		end--;
	end[1] = '\0';
	return (str);
}

void	exit_value(t_data *minishell, char *msg)
{
	minishell->state = 2;
	printf("minishell: exit: %s: numeric argument required\n", msg);
	ft_end(minishell);
	exit(minishell->state);
}

int	too_many(t_data *minishell)
{
	printf("minishell: exit: too many arguments\n");
	minishell->state = 1;
	return (1);
}

bool	is_valid_exit(char *str)
{
	int	i;

	i = 0;
	str = trim_spaces(str);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isnum(str[i]))
		i++;
	while (ft_isspace(str[i]))
		i++;
	return (!str[i]);
}

void	while_exit(char *str, char **arg, t_data *minishell)
{
	int	i;

	i = 0;
	str = trim_spaces(str);
	if (!is_valid_exit(str))
		exit_value(minishell, str);
	while (ft_isnum(str[i]) && !arg[2])
	{
		minishell->state = ft_atoi(str);
		if (minishell->state == 0)
			exit_value(minishell, str);
		ft_end(minishell);
		exit(minishell->state % 256);
	}
	i++;
}

int	ft_exit(t_data *minishell, char **arg)
{
	int	i;

	i = -1;
	minishell->state = 0;
	printf("exit\n");
	if (!arg[1])
	{
		ft_end(minishell);
		exit(minishell->state);
	}
	while_exit(arg[1], arg, minishell);
	if (arg[2])
		return (too_many(minishell));
	return (minishell->state);
}
