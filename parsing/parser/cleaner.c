/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:44:22 by cgelgon           #+#    #+#             */
/*   Updated: 2025/04/15 16:59:39 by cgelgon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	free_command(t_cmd_list *cmd)
{
	int	i;

	if (!cmd)
		return ;
	if (cmd->cmd)
		free(cmd->cmd);
	if (cmd->av)
	{
		i = 0;
		while (i < cmd->ac)
			free(cmd->av[i++]);
		free(cmd->av);
	}
	if (cmd->input_file)
		free(cmd->input_file);
	if (cmd->output_file)
		free(cmd->output_file);
	if (cmd->delimiter)
		free(cmd->delimiter);
	if (cmd->fd_in != STDIN_FILENO)
		close(cmd->fd_in);
	if (cmd->fd_out != STDOUT_FILENO)
		close(cmd->fd_out);
	free(cmd);
}

/* Free entire command list */
void	free_cmd_list(t_cmd_list *cmd_list)
{
	t_cmd_list	*current;
	t_cmd_list	*next;

	current = cmd_list;
	while (current)
	{
		next = current->next;
		free_command(current);
		current = next;
	}
}
