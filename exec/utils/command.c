/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:37:36 by lmokhtar          #+#    #+#             */
/*   Updated: 2025/04/02 16:43:32 by lmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"
#include "../../include/command_list.h"

void	ft_cmd_listaddback(t_cmd_list **head, t_cmd_list *new)
{
	if (!head)
		return ;
	if (*head)
		ft_cmd_listlast(*head)->next = new;
	else
		*head = new;
}

t_cmd_list	*ft_cmd_listnew(char **tab, t_heredoc *redir)
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

t_cmd_list	*ft_cmd_listlast(t_cmd_list *head)
{
	while (head->next)
		head = head->next;
	return (head);
}

void	ft_cmd_listclear(t_cmd_list **cmd)
{
	t_cmd_list	*tmp;

	while (*cmd)
	{
		tmp = (*cmd)->next;
		free_tab((*cmd)->av);
		ft_redirclear((*cmd)->redir);
		free((*cmd));
		(*cmd) = tmp;
	}
}
