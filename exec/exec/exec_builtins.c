/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 02:23:25 by lmokhtar          #+#    #+#             */
/*   Updated: 2025/03/31 18:23:11 by lmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	exec_builtins(t_data *minishell, char **arg)
{
	if (ft_strcmp("cd", arg[0]) == 0)
		return (ft_cd(minishell, arg));
	if (ft_strcmp("echo", arg[0]) == 0)
		return (ft_echo(minishell, arg));
	if (ft_strcmp("env", arg[0]) == 0)
		return (ft_env(minishell, arg));
	if (ft_strcmp("export", arg[0]) == 0)
		return (ft_export(minishell, arg));
	if (ft_strcmp("pwd", arg[0]) == 0)
		return (ft_pwd(minishell, arg));
	if (ft_strcmp("unset", arg[0]) == 0)
		return (ft_unset(minishell, arg));
	else
		return (0);
}

int	builtins(t_data *minishell, t_command *cmd)
{
	int	save[2];
	int	status;

	save[STDIN_FILENO] = dup(STDIN_FILENO);
	save[STDOUT_FILENO] = dup(STDOUT_FILENO);
	open_redirections(cmd, minishell);
	if (ft_strcmp("exit", cmd->arguments[0]) == 0)
	{
		dup2(save[STDIN_FILENO], STDIN_FILENO);
		dup2(save[STDOUT_FILENO], STDOUT_FILENO);
		(close(save[0]), close(save[1]));
		free_all_heredoc(minishell->command);
		return (ft_exit(minishell, cmd->arguments));
	}
	status = exec_builtins(minishell, cmd->arguments);
	dup2(save[STDIN_FILENO], STDIN_FILENO);
	dup2(save[STDOUT_FILENO], STDOUT_FILENO);
	(close(save[0]), close(save[1]));
	free_all_heredoc(minishell->command);
	return (status);
}

bool	is_a_builtin(char **arg)
{
	if (arg == NULL || arg[0] == NULL)
		return (0);
	if (ft_strcmp("cd", arg[0]) == 0)
		return (1);
	if (ft_strcmp("echo", arg[0]) == 0)
		return (1);
	if (ft_strcmp("env", arg[0]) == 0)
		return (1);
	if (ft_strcmp("exit", arg[0]) == 0)
		return (1);
	if (ft_strcmp("export", arg[0]) == 0)
		return (1);
	if (ft_strcmp("pwd", arg[0]) == 0)
		return (1);
	if (ft_strcmp("unset", arg[0]) == 0)
		return (1);
	return (0);
}
