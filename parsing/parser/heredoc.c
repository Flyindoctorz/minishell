/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:54:33 by cgelgon           #+#    #+#             */
/*   Updated: 2025/04/03 14:29:15 by cgelgon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool	setup_heredoc_redir(t_cmd_list *cmd, t_heredoc *heredoc)
{
	if (!cmd || !heredoc || heredoc->fd < 0)
		return (false);
	if (cmd->fd_in != STDIN_FILENO)
		close(cmd->fd_in);
	cmd->fd_in = heredoc->fd;
	cmd->heredoc = (true);
	if (cmd->delimiter)
	{
		free(cmd->delimiter);
		cmd->delimiter = NULL;
	}
	cmd->delimiter = ft_strdup(heredoc->delimiter);
	if (!cmd->delimiter)
		return (false);
	return (true);
}
bool	should_expand_heredoc(char *delimiter)
{
	int	i;
	int	quote_count;

	if (!delimiter)
		return (true);
	i = 0;
	quote_count = 0;
	while (delimiter[i])
	{
		if (delimiter[i] == '\'' || delimiter[i] == '"')
			quote_count++;
		i++;
	}
	return (quote_count % 2 == 0);
}

void	*save_and_set_signals(void)
{
	struct sigaction	sa;
	struct sigaction	old_sa;

	ft_memset(&sa, 0, sizeof(sa));
	sa.sa_handler = SIG_IGN;
	sigaction(SIGINT, &sa, &old_sa);
	return ((void *)old_sa.sa_handler);
}
void	restore_signals(void *old_handler)
{
	struct sigaction	sa;

	ft_memset(&sa, 0, sizeof(sa));
	sa.sa_handler = old_handler;
	sigaction(SIGINT, &sa, NULL);
}
// if TOKEN_HEREDOC,
bool	handle_heredoc(t_cmd_list *cmd, char *delimiter, t_data *data)
{
	t_heredoc	*heredoc;
	bool		expand;
	bool		success;
	void		*old_sigint;

	if (!cmd || !delimiter || !data)
		return (false);
	expand = should_expand_heredoc(delimiter);
	heredoc = init_heredoc(delimiter, expand);
	if (!heredoc)
		return (false);
	old_sigint = save_and_set_signals();
	success = read_heredoc_content(heredoc, data);
	restore_signals(old_sigint);
	if (!success)
	{
		free_heredoc(heredoc);
		return (false);
	}
	success = setup_heredoc_redir(cmd, heredoc);
	heredoc->fd = -1;
	free_heredoc(heredoc);
	return (success);
}
