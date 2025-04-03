/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:33:00 by cgelgon           #+#    #+#             */
/*   Updated: 2025/04/03 14:26:16 by cgelgon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "minishell.h"


// init functions

t_lexer			*init_lexer(char *input, t_data *data);
void			advance_lexer(t_lexer *lexer);
char			look_forward(t_lexer *lexer);
bool			add_token(t_lexer *lexer, t_token *new_token);
void			free_lexer(t_lexer *lexer);

// utils functions
bool			is_whitespace(char c);
bool			is_delimiter(char c);
void			skip_whitespace(t_lexer *lexer);
t_token			*create_token(t_token_type type, char *value);

// read functions
t_token			*read_word(t_lexer *lexer);
t_token			*read_operator(t_lexer *lexer);
t_token			*read_quotes(t_lexer *lexer);
t_token			*read_expand(t_lexer *lexer);

// quotes utils
bool			is_quote(char c);
t_token_type	get_quote_type(char c);
bool			check_quote_end(t_lexer *lexer, char quote);
int				get_quote_len(t_lexer *lexer, char quote);
t_token			*create_quote_token(t_lexer *lexer, int len, int start_pos);

// expand utils
bool			is_expand_char(char c);
int				get_var_name_len(t_lexer *lexer);
t_token			*create_dollar_token(int start_pos);
t_token			*create_expand_token(t_lexer *lexer, int start_pos);
void			advance_var_position(t_lexer *lexer, int var_len);

// shrinker functions
t_token			*shrink_redir_tokens(t_token *tokens);
void			add_to_result(t_token **res, t_token **tail,
					t_token *new_token);
t_token			*create_token_copy(t_token *source);
t_token			*process_token_list(t_token *tokens, t_token **res,
					t_token **res_tail);
void			free_token_list(t_token *tokens);

// shrinker utils
bool			is_redir(t_token *token);
bool			is_operator(char c);
t_token			*merge_redir(t_token *redir, t_token *target);

// lexer main functions
t_token			*apply_shrink(t_token *tokens);
t_token			*tokenize_input(char *input, t_data *data);
t_token			*tokenize_current(t_lexer *lexer);
void			free_token_list(t_token *token);

#endif
