/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 13:57:40 by cgelgon           #+#    #+#             */
/*   Updated: 2025/04/02 16:35:26 by lmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H

# include "minishell.h"

typedef struct s_redir_type
{
	IN;
	OUT;
	HEREDOC;
	APPEND;
}			t_redir_type;

typedef struct s_heredoc
{
	char *delimiter;        // Délimiteur
	int fd;                 // Descripteur de fichier
	char *content;          // Contenu collecté
	bool expand;            // Si l'expansion doit être effectuée
	t_redir_type type;      // Type de redirection
	struct s_heredoc *next; // Prochain heredoc
}			t_heredoc;

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
bool		process_all_heredocs(t_cmd_list *cmd, t_token *token, t_data *data);
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
