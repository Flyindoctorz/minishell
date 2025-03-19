/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mnshl_handle_builtin.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:08:55 by zakchouc          #+#    #+#             */
/*   Updated: 2024/12/20 13:08:31 by cgelgon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_handle_echo(t_minishell *mini, char *envp[])
{
	int		i;
	bool	newline;

	(void)envp;
	i = 1;
	newline = true;
	if (ft_strncmp(mini->token_list[1], "-n", 2) == 0)
	{
		newline = false;
		++i;
	}
	while (mini->token_list[i])
	{
		printf("%s", (mini->token_list[i]));
		if (mini->token_list[i + 1])
			printf(" ");
		++i;
	}
	if (newline)
		printf("\n");
}

void	ft_handle_cd(t_minishell *mini)
{
	int	status;

	status = chdir(mini->token_list[1]);
	printf("cd cmd status : %d\n", status);
	if (status < 0)
		perror("cd");
}

void	ft_handle_pwd(t_minishell *mini)
{
	char	*cwd_path;

	cwd_path = NULL;
	cwd_path = getcwd(cwd_path, 0);
	if (cwd_path == NULL)
		perror("pwd");
	if (mini->token_list[1])
		printf("pwd: too many arguments\n");
	else
		printf("%s\n", cwd_path);
}

void	ft_handle_export(t_minishell *mini)
{
	size_t	arr_len;
	int		i;

	arr_len = ft_arrlen(mini->env.list);
	i = 0;
	while (mini->env.list[i])
	{
		if (ft_strnstr(mini->env.list[i], mini->token_list[1],
			ft_strlen(mini->token_list[1])))
			break ; // env found, don't do anything
		++i;
	}
}

void	ft_handle_env(t_minishell *mini)
{
	int	i;

	i = 0;
	while (mini->env.list[i])
	{
		printf("%s\n", mini->env.list[i++]);
		// ++i;
	}
}

// export MY_VARIABLE="value"