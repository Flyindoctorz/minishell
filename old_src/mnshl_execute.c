/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mnshl_execute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakchouc <zakchouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:58:47 by zakchouc          #+#    #+#             */
/*   Updated: 2024/12/18 22:15:58 by zakchouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static char	*ft_concat_cmd(const char *path, const char *cmd)
{
	char	*full_path;
	int		i;
	size_t	len;

	// put protections here
	len = ft_strlen(path) + ft_strlen("/") + ft_strlen(cmd);
	full_path = ft_calloc(len + 1, sizeof(char));
	if (!full_path)
		return (NULL);
	i = 0;
	while (*path)
		full_path[i++] = *path++;
	full_path[i++] = '/';
	while (*cmd)
		full_path[i++] = *cmd++;
	full_path[i] = '\0';
	return (full_path);
}

void	ft_execute(t_minishell *mini)
{
	int		status;
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		ft_free_everything(mini);
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execve(mini->command, mini->token_list, mini->env.list) == -1)
		{
			perror(mini->token_list[0]);
			ft_free_everything(mini);
			exit(EXIT_FAILURE);
		}
	}
	else
		waitpid(pid, &status, 0);
}

int	ft_build_command(t_minishell *mini, char *envp[])
{
	bool	status;
	int		i;

	(void)status;
	(void)envp;
	mini->env.path_list = ft_strtok(getenv("PATH"), ":");
	i = 0;
	while (mini->env.path_list[i])
	{
		mini->command = ft_concat_cmd(mini->env.path_list[i],
				mini->token_list[0]);
		if (access(mini->command, X_OK) == 0)
		{
			// free(mini->command);
			break ;
		}
		free(mini->command); // double free here
		++i;
	}
	// free array here : free(mini->env.path_list);
	return (0);
}

// execv   : vector
// execve  : vector env
// execvp  : vector path
// execvpe : vector path
// execl   : list
// execle  : list env
// execlp  : list path
