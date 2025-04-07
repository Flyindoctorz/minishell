/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 11:37:46 by cgelgon           #+#    #+#             */
/*   Updated: 2025/04/07 16:37:39 by lmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "structure.h"

// Fonctions principales du parser
t_cmd_list	*parse_token(t_token *tokens, t_data *data);
bool		validate_syntax(t_token *tokens);
// gestion des commandes
t_cmd_list	*init_cmd_list(void);
void		add_word_to_cmd(t_cmd_list *cmd, char *word);
t_cmd_list	*handle_pipe(t_cmd_list *cmd);
void		ft_commandaddback(t_cmd_list **head, t_cmd_list *new_cmd);
t_cmd_list	*ft_commandlast(t_cmd_list *head);
// gestion des redirections
bool		handle_redir(t_cmd_list *cmd, t_token *token, t_data *data);
bool		set_input_file(t_cmd_list *cmd, char *filename);
bool		set_output_file(t_cmd_list *cmd, char *filename, bool append);
bool		setup_redir(t_cmd_list *cmd);
// variables expansion
char		*expand_variable(char *str, t_data *data);
// int			get_env_size(char *str, int i, t_data *data);
// char		*get_env_value(char *key, t_data *data);
// utils
bool		is_redir_token(t_token_type type);
void		free_cmd_list(t_cmd_list *cmd_list);
void		free_av_array(char **av, int index);
// char		**create_av_array(t_token *tokens, int ac, t_data *data);
int			count_args(t_token *tokens);

#endif
