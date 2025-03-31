/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 02:22:31 by lmokhtar          #+#    #+#             */
/*   Updated: 2025/03/27 02:22:32 by lmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	chdir_fail(char *str)
{
	printf("minishell: cd: %s : No such file or directory\n", str);
	return (1);
}

int	ft_cd(t_data *shell, char **arg)
{
	char	*inter;
	char	*home;

	shell->state = 1;
	if (!arg[1])
	{
		if (!search_env(shell->env, "HOME"))
			return (printf("minishell: cd: HOME not set\n"), shell->state);
		inter = ft_strdup("$HOME");
		home = expand(inter, shell);
		if (!home)
			return (printf("minishell: cd: malloc issue\n"), shell->state);
		if (chdir(home) == -1)
		{
			chdir_fail(home);
			return (free(home), free(inter), 1);
		}
		return (free(home), free(inter), 0);
	}
	if (arg[2])
		return (printf("minishell: cd: too many arguments\n"), shell->state);
	if (chdir(arg[1]) == -1)
		return (chdir_fail(arg[1]));
	shell->state = 0;
	return (shell->state);
}
