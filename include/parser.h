/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 11:37:46 by cgelgon           #+#    #+#             */
/*   Updated: 2025/04/15 16:36:52 by lmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "structure.h"

// Fonctions principales du parser
t_cmd_list	*parse_token(t_token *tokens, t_data *data);
bool		validate_syntax(t_token *tokens);
bool		validate_syntax_part2(t_token *curr, bool *had_word);
t_cmd_list	*finalize_parsing(t_cmd_list *cmd_list, t_token *tokens,
				t_data *data);

// Gestion des commandes
t_cmd_list	*init_cmd_list(void);
void		add_word_to_cmd(t_cmd_list *cmd, char *word);
t_cmd_list	*handle_pipe(t_cmd_list *cmd);
void		ft_commandaddback(t_cmd_list **head, t_cmd_list *new_cmd);
t_cmd_list	*ft_commandlast(t_cmd_list *head);

// Gestion des redirections
bool		handle_redir(t_cmd_list *cmd, t_token *token, t_data *data);
bool		set_input_file(t_cmd_list *cmd, char *filename);
bool		set_output_file(t_cmd_list *cmd, char *filename, bool append);
bool		setup_redir(t_cmd_list *cmd);

// Gestion des heredocs
t_heredoc	*init_heredoc(char *delimiter, bool expand);
bool		handle_heredoc(t_cmd_list *cmd, char *delimiter, t_data *data);
bool		process_all_heredocs(t_cmd_list *cmd, t_token *token, t_data *data);
bool		process_heredoc_tok(t_cmd_list *cmd, t_token *token, t_data *data);
bool		is_heredoc_token(t_token *token);
bool		is_valid_heredoc_delimiter(char *delimiter);
char		*extract_heredoc_delim(t_token *token);
void		free_heredoc(t_heredoc *heredoc);
bool		read_heredoc_content(t_heredoc *heredoc, t_data *data);
bool		heredoc_reader(t_heredoc *heredoc, t_data *data);
bool		process_heredoc_line(char *line, t_heredoc *heredoc, t_data *data,
				int pipefd[2]);
bool		write_content_to_pipe(int fd, char *content);
bool		init_heredoc_pipe(int pipefd[2]);
void		handle_heredoc_eof(void);
void		prepare_heredoc_redir(t_heredoc *heredoc, int pipefd[2]);
bool		should_expand_heredoc(char *delimiter);
void		*save_and_set_signals(void);
void		restore_signals(void *old_handler);
bool		heredoc_reader_one(t_heredoc *heredoc, t_data *data, int pipefd[2]);

// Variables expansion
char		*expand(char *str, t_data *data);

// Utils
bool		is_redir_token(t_token_type type);
void		free_cmd_list(t_cmd_list *cmd_list);
void		free_command(t_cmd_list *cmd);
void		free_av_array(char **av, int index);
char		**create_av_array(t_token *tokens, int ac, t_data *data);
void		skip_redir_token(t_token **current);
int			count_args(t_token *tokens);

#endif