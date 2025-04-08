/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 11:37:46 by cgelgon           #+#    #+#             */
/*   Updated: 2025/04/08 13:49:19 by cgelgon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "structure.h"

// Fonctions principales du parser
t_cmd_list	*parse_token(t_token *tokens, t_data *data);
bool		validate_syntax(t_token *tokens);

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
void		free_heredoc(t_heredoc *heredoc);

// Variables expansion
char		*expand(char *str, t_data *data);

// Utils
bool		is_redir_token(t_token_type type);
void		free_cmd_list(t_cmd_list *cmd_list);
void		free_av_array(char **av, int index);
int			count_args(t_token *tokens);

#endif
