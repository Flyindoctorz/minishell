/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mnshl_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 10:46:20 by zakchouc          #+#    #+#             */
/*   Updated: 2024/12/20 13:08:08 by cgelgon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_parse(t_minishell *mini, char *envp[])
{
	printf("parsing input : %s\n", mini->input);
	if (ft_strncmp(mini->input, "echo", 4) == 0)
		ft_handle_echo(mini, envp);
	else if (ft_strncmp(mini->input, "cd", 2) == 0)
		ft_handle_cd(mini);
	else if (ft_strncmp(mini->input, "pwd", 3) == 0)
		ft_handle_pwd(mini);
	else if (ft_strncmp(mini->input, "env", 3) == 0)
		ft_handle_env(mini);
	else if (ft_strncmp(mini->input, "exit", 4) == 0)
		ft_exit_minishell(mini);
	else if (ft_strncmp(mini->input, "sandbox", 7) == 0)
		ft_sanbox(mini);
	else
	{
		ft_build_command(mini, envp);
		ft_execute(mini);
	}
}
