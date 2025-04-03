/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 11:31:40 by cgelgon           #+#    #+#             */
/*   Updated: 2025/04/03 14:29:05 by cgelgon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// ecrit dans fd
bool	write_content_to_pipe(int fd, char *content)
{
	size_t	len;

	if (fd < 0 || !content)
		return (false);
	len = ft_strlen(content);
	if (write(fd, content, len) != (ssize_t)len)
		return (false);
	if (write(fd, "\n", 1) != 1)
		return (false);
	return (true);
}

bool	init_heredoc_pipe(int pipefd[2])
{
	if (pipe(pipefd) < 0)
		return (false);
	return (true);
}

bool	process_heredoc_line(char *line, t_heredoc *heredoc, t_data *data,
		int pipefd[2])
{
	char	*expanded_line;

	if (!line || !heredoc || !data || pipefd[1] < 0)
		return (false);
	if (heredoc->expand)
	{
		expanded_line = expand_line(line, data);
		free(line);
		if (!expanded_line)
			return (false);
		line = expanded_line;
	}
	if (!write_content_to_pipe(pipefd[1], line))
	{
		free(line);
		return (false);
	}
	free(line);
	return (true);
}
void	handle_heredoc_eof(void)
{
	ft_putstr_fd("minishell: warning: here-document", 2);
	ft_putstr_fd("delimited by end-of-file", 2);
}

void	prepare_heredoc_redir(t_heredoc *heredoc, int pipefd[2])
{
	if (!heredoc || pipefd[1] < 0)
		return ;
	close(pipefd[1]);
	if (heredoc->fd >= 0)
		close(heredoc->fd);
	heredoc->fd = pipefd[0];
}