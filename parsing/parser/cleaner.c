/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:44:22 by cgelgon           #+#    #+#             */
/*   Updated: 2025/04/08 14:04:51 by lmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/* Free a single command structure */
void	free_command(t_cmd_list *cmd)
{
	int	i;

	if (!cmd)
		return ;
	if (cmd->cmd)
		free(cmd->cmd);
	if (cmd->av)
	{
		for (i = 0; i < cmd->ac; i++)
			free(cmd->av[i]);
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
// void	free_cmd_list(t_cmd_list *cmd_list)
// {
// 	t_cmd_list	*current;
// 	t_cmd_list	*next;

// 	current = cmd_list;
// 	while (current)
// 	{
// 		next = current->next;
// 		free_command(current);
// 		current = next;
// 	}
// }
