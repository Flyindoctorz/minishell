/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:23:17 by cgelgon           #+#    #+#             */
/*   Updated: 2025/03/18 15:19:41 by cgelgon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_cmd_list	*init_cmd_list(void)
{
	t_cmd_list	*cmd;

	cmd = (t_cmd_list *)malloc(sizeof(t_cmd_list));
	if (!cmd)
		return (NULL);
	cmd->cmd = NULL;
	cmd->av = NULL;
	cmd->ac = 0;
	cmd->input_file = NULL;
	cmd->output_file = NULL;
	cmd->delimiter = NULL;
	cmd->fd_in = STDIN_FILENO;
	cm->fd_out = STDOUT_FILENO;
	cmd->is_pipe = false;
	cmd->append = false;
	cmd->heredoc = false;
	cmd->next = NULL;
	return (cmd);
}

void	add_new_cmd(t_cmd_list **cmd)
{
	char	**new_av;
	int		i;

	if (!cmd || !word)
		return ;
	if (!cmd->cmd)
	{
		cmd->cmd = ft_strdup(word);
	}
	new_av = (char **)malloc(sizeof(char *) * (cmd->ac + 2));
	if (!new_av)
		return ;
	if (i = 0; i < cmd->ac; i++)
		new_av[i] = cmd->av[i];
	{
		new_av[cmd->ac] = ft_strdup(word);
		new_av[cmd->ac + 1] = NULL;
		if (cmd->av)
			free(cmd->av);
	}
	cmd->av = new_av;
	cmd->ac++;
}

t_cmd_list	*handle_pipe(t_cmd_list *cmd)
{
	t_cmd_list	*new_cmd;

	if (!cmd)
		return (NULL);
	new_cmd = init_cmd_list();
	if (!new_cmd)
		return (NULL);
	cmd->is_pipe = true;
	cmd->next = new_cmd;
	return (new_cmd);
}
