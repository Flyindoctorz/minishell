/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:42:54 by lmokhtar          #+#    #+#             */
/*   Updated: 2025/04/15 15:50:26 by lmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	hrd_lin(char *line, t_heredoc *redir, t_data *minishell)
{
	if (!line)
	{
		printf("minihell: warning: heredoc delimited by end-of-file \n");
		return (1);
	}
	if (ft_strcmp(line, redir->delimiter) == 0)
		return (1);
	redir->content = add_argument(redir->content, expand(line, minishell));
	free(line);
	return (0);
}

int	get_heredoc(t_heredoc *redir, t_data *minishell)
{
	char	*line;

	while (1)
	{
		line = readline("heredoc> ");
		if (g_signal != 0)
		{
			free(line);
			if (redir->content)
				free_tab(redir->content);
			minishell->state = g_signal;
			g_signal = 0;
			return (EXIT_FAILURE);
		}
		if (hrd_lin(line, redir, minishell))
			break ;
	}
	return (EXIT_SUCCESS);
}

void	ft_rediraddback(t_heredoc **head, t_heredoc *new)
{
	if (!head)
		return ;
	if (*head)
		ft_redirlast(*head)->next = new;
	else
		*head = new;
}

t_heredoc	*ft_redirnew(char *str, t_token_type type, t_data *minishell)
{
	t_heredoc	*redir;

	if (!str)
		return (NULL);
	redir = malloc(sizeof(t_heredoc));
	if (!redir)
		return (NULL);
	redir->content = NULL;
	redir->type = type;
	redir->delimiter = str;
	if (type == TOKEN_HEREDOC)
	{
		if (get_heredoc(redir, minishell) == EXIT_FAILURE)
		{
			free(redir);
			return (NULL);
		}
	}
	redir->next = NULL;
	return (redir);
}

t_heredoc	*ft_redirlast(t_heredoc *head)
{
	while (head->next)
		head = head->next;
	return (head);
}
