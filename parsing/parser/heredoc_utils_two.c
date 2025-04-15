/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils_two.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:32:37 by cgelgon           #+#    #+#             */
/*   Updated: 2025/04/15 16:38:22 by lmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*expand_line(char *line, t_data *data)
{
	if (!line || !data)
		return (NULL);
	return (expand(line, data));
}

static char	*get_content(char *line, t_heredoc *heredoc, t_data *data)
{
	char	*expanded;

	expanded = NULL;
	if (heredoc->expand)
		expanded = expand(line, data);
	else
		expanded = ft_strdup(line);
	free(line);
	return (expanded);
}

static bool	process_line(char *line, t_heredoc *heredoc, t_data *data,
		int pipe_fd)
{
	char	*expanded;

	if (!line)
	{
		handle_heredoc_eof();
		return (false);
	}
	if (ft_strcmp(line, heredoc->delimiter) == 0)
	{
		free(line);
		return (false);
	}
	expanded = get_content(line, heredoc, data);
	if (!expanded)
		return (false);
	if (write_content_to_pipe(pipe_fd, expanded) == false)
	{
		free(expanded);
		return (false);
	}
	free(expanded);
	return (true);
}

bool	heredoc_reader_one(t_heredoc *heredoc, t_data *data, int pipefd[2])
{
	char	*line;
	bool	keep_reading;

	keep_reading = true;
	while (keep_reading)
	{
		line = readline("> ");
		keep_reading = process_line(line, heredoc, data, pipefd[1]);
	}
	return (true);
}
