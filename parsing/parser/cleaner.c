/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:44:22 by cgelgon           #+#    #+#             */
/*   Updated: 2025/04/15 16:46:50 by lmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/* Free a single command structure */
void	free_command(t_cmd_list *cmd)
{
	int	i;

	i = 0;
	if (!cmd)
		return ;
	if (cmd->cmd)
		free(cmd->cmd);
	if (cmd->av)
	{
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

bool	set_input_file(t_cmd_list *cmd, char *filename)
{
	if (!cmd || !filename)
		return (false);
	if (cmd->input_file)
		free(cmd->input_file);
	cmd->input_file = ft_strdup(filename);
	if (!cmd->input_file)
		return (false);
	return (true);
}

bool	set_output_file(t_cmd_list *cmd, char *filename, bool append)
{
	if (!cmd || !filename)
		return (false);
	if (cmd->output_file)
		free(cmd->output_file);
	cmd->output_file = ft_strdup(filename);
	if (!cmd->output_file)
		return (false);
	cmd->append = append;
	return (true);
}
