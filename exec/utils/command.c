/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:37:36 by lmokhtar          #+#    #+#             */
/*   Updated: 2025/04/08 17:09:21 by lmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_commandaddback(t_cmd_list **head, t_cmd_list *new)
{
	if (!head)
		return ;
	if (*head)
		ft_commandlast(*head)->next = new;
	else
		*head = new;
}

t_cmd_list	*ft_commandnew(char **tab, t_heredoc *redir)
{
	t_cmd_list	*cmd;

	cmd = malloc(sizeof(t_cmd_list));
	if (!cmd)
		return (NULL);
	cmd->av = tab;
	cmd->redir = redir;
	cmd->next = NULL;
	return (cmd);
}

t_cmd_list	*ft_commandlast(t_cmd_list *head)
{
	while (head->next)
		head = head->next;
	return (head);
}

// void	ft_commandclear(t_cmd_list **cmd)
// {
// 	t_cmd_list	*tmp;

// 	while (*cmd)
// 	{
// 		tmp = (*cmd)->next;
// 		free_tab((*cmd)->av);
// 		ft_redirclear((*cmd)->redir);
// 		free((*cmd));
// 		(*cmd) = tmp;
// 	}
// }

static void	free_cmd_content(t_cmd_list *current)
{
	int	i;

	if (current->cmd)
		free(current->cmd);
	if (current->av)
	{
		i = 0;
		while (i < current->ac)
			free(current->av[i++]);
		free(current->av);
	}
	if (current->input_file)
		free(current->input_file);
	if (current->output_file)
		free(current->output_file);
	if (current->delimiter)
		free(current->delimiter);
	if (current->redir)
		ft_redirclear(current->redir);
	if (current->fd_in != STDIN_FILENO)
		close(current->fd_in);
	if (current->fd_out != STDOUT_FILENO)
		close(current->fd_out);
}

void	ft_commandclear(t_cmd_list **cmd)
{
	t_cmd_list	*current;
	t_cmd_list	*next;

	if (!cmd || !*cmd)
		return ;
	current = *cmd;
	while (current)
	{
		next = current->next;
		free_cmd_content(current);
		free(current);
		current = next;
	}
	*cmd = NULL;
}
