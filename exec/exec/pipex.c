/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 02:23:33 by lmokhtar          #+#    #+#             */
/*   Updated: 2025/04/15 18:36:13 by lmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*cmd_find(char **cmd, char **env)
{
	int		i;
	char	*tmp;
	char	*slash;

	if (cmd[0][0] == '\0')
		return (free_tab(env), NULL);
	slash = ft_strjoin("/", cmd[0]);
	if (!slash)
		return (NULL);
	i = -1;
	while (env[++i])
	{
		tmp = ft_strjoin(env[i], slash);
		if (!tmp)
			return (free(slash), NULL);
		if (access(tmp, F_OK) == 0)
			return (free_tab(env), free(slash), tmp);
		free(tmp);
	}
	return (free_tab(env), free(slash), NULL);
}

void	message_err(char *path, char **cmd, t_data *minishell)
{
	(void)minishell;
	if (ft_strchr(cmd[0], '/') != 0)
		ft_putstr_fd("No such file or directory : ", 2);
	else if (!path)
		ft_putstr_fd("command not found: ", 2);
	else if (access(path, F_OK) == 0 && access(path, X_OK) != 0)
	{
		ft_putstr_fd("Permission denied: ", 2);
		ft_putendl_fd(cmd[0], 2);
		free(path);
		ft_end(minishell);
		exit(126);
	}
	if (path)
		free(path);
	ft_putendl_fd(cmd[0], 2);
	ft_end(minishell);
	exit(127);
}

void	end_exec(char *path, char **cmd, char **env, t_data *minishell)
{
	if (!path)
		message_err(path, cmd, minishell);
	free_all_heredoc(minishell->command);
	execve(path, cmd, env);
	message_err(path, cmd, minishell);
}

void	exec_path(char **cmd, char **env, t_data *minishell)
{
	int		i;
	char	*path;
	char	**tmp_path;

	tmp_path = NULL;
	path = NULL;
	i = 0;
	if (!cmd)
		return ;
	if (ft_strchr(cmd[0], '/') && !access(cmd[0], F_OK | X_OK))
		path = ft_strdup(cmd[0]);
	else if (env[i] && !ft_strchr(cmd[0], '/'))
	{
		while (env[i] && ft_strncmp(env[i], "PATH=", 5) != 0)
			i++;
		if (env[i])
			tmp_path = ft_split(&env[i][5], ':');
		if (!tmp_path)
			message_err(path, cmd, minishell);
		path = cmd_find(cmd, tmp_path);
	}
	end_exec(path, cmd, env, minishell);
	exit(0);
}
