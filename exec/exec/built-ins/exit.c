/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 02:23:01 by lmokhtar          #+#    #+#             */
/*   Updated: 2025/04/15 18:35:20 by lmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	exit_value(t_data *minishell, char *msg)
{
	int	exit_code;

	minishell->state = 2;
	printf("minishell: exit: %s: numeric argument required\n", msg);
	exit_code = minishell->state;
	ft_end(minishell);
	exit(exit_code);
}

int	error_arg(t_data *minishell)
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
	if (!ft_isnum(str[i]))
		return (false);
	while (ft_isnum(str[i]))
		i++;
	while (str[i])
	{
		if (!ft_isspace(str[i]))
			return (false);
		i++;
	}
	return (is_in_int_range(str));
}

void	while_exit(char *str, char **arg, t_data *minishell)
{
	int	exit_code;

	str = trim_spaces(str);
	if (!is_valid_exit(str))
	{
		printf("minishell: exit: %s: numeric argument required\n", str);
		minishell->state = 2;
		exit_code = minishell->state;
		ft_end(minishell);
		exit(exit_code);
	}
	if (arg[2])
		return ;
	minishell->state = ft_atoi(str);
	exit_code = minishell->state % 256;
	ft_end(minishell);
	exit(exit_code);
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
		return (error_arg(minishell));
	return (minishell->state);
}
