/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:42:54 by lmokhtar          #+#    #+#             */
/*   Updated: 2025/04/11 14:56:22 by lmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static bool	heredoc_reader_one(t_heredoc *heredoc, t_data *data, int pipefd[2])
{
    char *line;
    bool keep_reading = true;
    
    while (keep_reading)
    {
        line = readline("heredoc> ");
        if (g_signal != 0)
        {
            if (heredoc->content)
                free_tab(heredoc->content);
            free(line);
            data->state = g_signal;
            g_signal = 0;
            return (false);
        }
        if (!line)
        {
            printf("minishell: warning: heredoc delimited by end-of-file \n");
            break;
        }
        if (ft_strcmp(line, heredoc->delimiter) == 0)
        {
            free(line);
            break;
        }
        char *expanded = NULL;
        if (heredoc->expand)
            expanded = expand(line, data);
        else
            expanded = ft_strdup(line); 
        free(line);
        if (!expanded)
            return (false);
        if (write_content_to_pipe(pipefd[1], expanded) == false)
        {
            free(expanded);
            return (false);
        }
        free(expanded);
    } 
    return (true);
}


int	get_heredoc(t_heredoc *redir, t_data *minishell)
{
	int	pipefd[2];

	if (!init_heredoc_pipe(pipefd))
		return (EXIT_FAILURE);
	if (!heredoc_reader_one(redir, minishell, pipefd))
	{
		close(pipefd[0]);
		close(pipefd[1]);
		return (EXIT_FAILURE);
	}
	prepare_heredoc_redir(redir, pipefd);
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

void	ft_redirclear(t_heredoc *redir)
{
	t_heredoc	*tmp;

	while (redir)
	{
		tmp = redir->next;
		free(redir->delimiter);
		free(redir);
		redir = tmp;
	}
}
