/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 02:22:38 by lmokhtar          #+#    #+#             */
/*   Updated: 2025/04/02 15:41:15 by lmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/exec.h"

int	good_flag(const char *str)
{
	int	i;

	if (str[0] != '-' || !str[1])
		return (0);
	i = 1;
	while (str[i])
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

void	print_args(char **args, int start)
{
	int	i;

	i = start;
	while (args[i])
	{
		printf("%s", args[i]);
		if (args[i + 1])
			printf(" ");
		i++;
	}
}

int	ft_echo(t_data *minishell, char **arg)
{
	int flag;
	int i;

	minishell->state = 0;
	flag = 0;
	i = 1;
	if (!arg[1])
		return (printf("\n"), 0);
	while (arg[i] && good_flag(arg[i]))
	{
		flag = 1;
		i++;
	}
	print_args(arg, i);
	if (flag == 0)
		printf("\n");
	return (minishell->state);
}