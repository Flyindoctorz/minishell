/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:54:33 by cgelgon           #+#    #+#             */
/*   Updated: 2025/03/19 15:16:16 by cgelgon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool	write_content_to_pipe(int fd, char *content)
{
	size_t	len;

	if (fd < 0 || !content)
		return (false);
	len = ft_strlen(content);
	if (write(fd, content, len) != (ssize_t)len)
		return (false);
	return (true);
}

t_heredoc	*init_heredoc(char *delimiter, bool expand)
{
	t_heredoc	*heredoc;
	int			pipefd[2];
	
	if (!delimiter)
		return (NULL);
	if (!heredoc)
		return (NULL);
	heredoc = (t_heredoc *)malloc(sizeof(t_heredoc));
	if (!heredoc)
		return (NULL);
	heredoc->delimiter = ft_strdup(delimiter);
	if (!heredoc->delimiter)
	{
		free(heredoc);
		return (NULL);
	}
	if (pipe(pipefd) < 0)
	{
		free(heredoc->delimiter);
		free(heredoc);
		return (NULL);
	}
	write_content_to_pipe(pipefd[1], "");
	close(pipefd[1]);
	return (heredoc);
}

void	free_heredoc(t_heredoc *heredoc)
{
	if (!heredoc)
		return ;
	if (heredoc->delimiter)
		free(heredoc->delimiter);
	if (heredoc->content)
		free(heredoc->content);
	if (heredoc->fd >= 0)
		close(heredoc->fd);
	free(heredoc);
}