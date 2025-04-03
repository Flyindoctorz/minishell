/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 02:23:13 by lmokhtar          #+#    #+#             */
/*   Updated: 2025/04/03 14:30:47 by cgelgon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	ft_pwd(t_data *minishell, char **arg)
{
	char	*pwd;

	minishell->state = 0;
	(void)arg;
	pwd = getcwd(NULL, 0);
	if (!pwd)
		return (0);
	printf("%s\n", pwd);
	free(pwd);
	return (minishell->state);
}
