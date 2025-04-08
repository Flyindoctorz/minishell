/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 13:57:40 by cgelgon           #+#    #+#             */
/*   Updated: 2025/04/08 14:08:29 by cgelgon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H

# include "structure.h"

// heredoc utils
bool		write_content_to_pipe(int fd, char *content);
bool		init_heredoc_pipe(int pipefd[2]);
bool		process_heredoc_line(char *line, t_heredoc *heredoc, t_data *data,
				int pipefd[2]);
void		handle_heredoc_eof(void);
void		prepare_heredoc_redir(t_heredoc *heredoc, int pipefd[2]);
// heredoc parser
bool		is_heredoc_token(t_token *token);
bool		is_valid_heredoc_delimiter(char *delimiter);
char		*extract_heredoc_delim(t_token *token);
bool		process_heredoc_tok(t_cmd_list *cmd, t_token *token, t_data *data);
// heredoc reader
t_heredoc	*init_heredoc(char *delimiter, bool expand);
bool		heredoc_reader(t_heredoc *heredoc, t_data *data);
void		free_heredoc(t_heredoc *heredoc);
// heredoc handler
bool		setup_heredoc_redir(t_cmd_list *cmd, t_heredoc *heredoc);
bool		should_expand_heredoc(char *delimiter);
void		*save_and_set_signals(void);
void		restore_signals(void *old_handler);
bool		handle_heredoc(t_cmd_list *cmd, char *delimiter, t_data *data);

#endif
