/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_reader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 11:55:07 by cgelgon           #+#    #+#             */
/*   Updated: 2025/04/15 16:38:32 by lmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_heredoc	*init_heredoc(char *delimiter, bool expand)
{
	t_heredoc	*heredoc;

	if (!delimiter)
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
	heredoc->content = NULL;
	heredoc->expand = expand;
	heredoc->fd = -1;
	return (heredoc);
}

bool	heredoc_reader(t_heredoc *heredoc, t_data *data)
{
	int		pipefd[2];
	bool	res;

	setup_heredoc_signals();
	if (!init_heredoc_pipe(pipefd))
	{
		restore_default_signals();
		return (false);
	}
	res = heredoc_reader_one(heredoc, data, pipefd);
	restore_default_signals();
	if (!res)
	{
		close(pipefd[0]);
		close(pipefd[1]);
		return (false);
	}
	prepare_heredoc_redir(heredoc, pipefd);
	return (true);
}
// bool	heredoc_reader(t_heredoc *heredoc, t_data *data)
// {
// 	int		pipefd[2];
// 	bool	res;

// 	if (!heredoc || !data)
// 		return (false);
// 	if (!init_heredoc_pipe(pipefd))
// 		return (false);
// 	res = heredoc_reader_one(heredoc, data, pipefd);
// 	if (!res)
// 	{
// 		close(pipefd[0]);
// 		close(pipefd[1]);
// 		return (false);
// 	}
// 	prepare_heredoc_redir(heredoc, pipefd);
// 	return (true);
// }

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

bool	read_heredoc_content(t_heredoc *heredoc, t_data *data)
{
	if (!heredoc || !data)
		return (false);
	ft_putstr_fd("heredoc> ", STDOUT_FILENO);
	if (!heredoc_reader(heredoc, data))
	{
		handle_error(MNSHL_ERR_MEMORY, "read_heredoc_content");
		return (false);
	}
	return (true);
}
