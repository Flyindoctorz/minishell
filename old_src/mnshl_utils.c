/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mnshl_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:41:56 by zakchouc          #+#    #+#             */
/*   Updated: 2024/12/20 18:29:46 by cgelgon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_sanbox(t_minishell *mini)
{
	char	path[255];

	(void)mini;
	printf("------Sandbox function begin------\n");

	// printf("%s", );

	printf("Current working directory (getcwd)   : %s\n", getcwd(path, 50));
	printf("Current working directory (path var) : %s\n", path);

	printf("------Sandbox function end------\n");
}

void	ft_print_tokens(t_minishell *mini)
{
	int	i;

	i = 0;
	while (mini->token_list[i])
	{
		printf("token list [%d] : %s\n", i, mini->token_list[i]);
		++i;
	}
}

void	ft_arrcpy(t_minishell *mini, char *envp[])
{
	int	i;
	int	j;

	i = 0;
	while (envp[i])
		++i;
	mini->env.list = ft_calloc(i + 1, sizeof(char *));
	if (!mini->env.list)
	{
		ft_free_everything(mini);
		exit(EXIT_FAILURE);
	}
	j = i;
	i = 0;
	while (i < j)
	{
		mini->env.list[i] = ft_strdup(envp[i]);
		++i;
	}
	mini->env.list[i] = NULL;
}

size_t	ft_arrlen(char *arr[])
{
	int	len;

	len = 0;
	while (arr[len])
		++len;
	return (len);
}
