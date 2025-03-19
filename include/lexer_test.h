/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_test.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:06:28 by cgelgon           #+#    #+#             */
/*   Updated: 2025/03/05 10:44:03 by cgelgon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef LEXER_TEST_H
# define LEXER_TEST_H

#include "minishell.h"
#include "lexer.h"
#include "data.h"

// lexer usefuls to init
t_data	*create_test_data(void);
char	*create_test_input(void);
bool	test_lexer_creation(t_data *data, char *input);
// before init tests
bool	test_init_lexer(void);
bool	test_look_forward_basic(void);
bool	test_look_forward_advanced(void);
bool	test_null_input(void);
bool	test_empty_input(void);
// whitespace tests
bool	test_whitespace_true(void);
bool	test_whitespace_false(void);
bool	test_whitespace(void);
bool	test_skip_whitespace(void);
bool	test_skip_mixed_whitespace(void);
// delimiter tests
bool	test_delimiter_true(void);
bool	test_delimiter_false(void);
bool	test_delimiter(void);
// create token tests
bool	test_create_token_basic(void);
bool	test_create_token_advanced(void);
// read word tests
bool	test_read_word_basic(void);
bool	test_read_word_advanced(void);
bool	test_read_word(void);
// read word utils
bool	init_word_test(t_data **data, t_lexer **lexer, char *input);
bool	compare_token(t_token *token, char *expected);
bool	test_single_word(char *input, char *expected);
// read operator tests
bool	test_operator_syntax_errors(void);
bool	test_pipe_syntax_errors(void);
bool	test_redir_syntax_errors(void);
// quotes tests
bool	test_quotes_basic(void);
bool	test_quotes_advanced(void);
bool	test_quotes_edge_cases(void);
bool	test_quotes_type(void);
// expand utils
bool	init_expand_test(t_data **data, t_lexer **lexer, char *input);
bool	verify_expand_token(t_token *token, char *expected, t_token_type expected_type);
void	cleanup_expand_test(t_token *token, t_lexer *lexer, t_data *data);
bool	test_expand_content(char *input, char *expected, t_token_type expected_type);
// expand tests
bool	test_expand_basic(void);
bool	test_expand_isolated(void);
bool	test_expand_edge_cases(void);
bool	test_expand_special_cases(void);
// shrinker tests
bool    test_is_redir(void);
bool    test_merge_redir(void);
bool    test_shrink_simple_redirection(void);
bool    test_shrink_multiple_redirections(void);
bool    test_shrink_mixed_tokens(void);
bool    test_shrink_redir_tokens(void);
// shrinker test utils
void    free_test_tokens(t_token *token1, t_token *token2);
void    free_test_tokens_with_merged(t_token *token1, t_token *token2, t_token *merged);
bool    verify_shrinked_token(t_token *token, t_token_type expected_type, char *expected_value);
bool    verify_multiple_tokens(t_token *tokens);
bool    verify_mixed_tokens(t_token *tokens);
void    free_cleanup_tokens(t_token *t1, t_token *t2, t_token *t3, t_token *t4);
// run tests
void	run_init_tests(void);
void	run_utils_tests(void);
void	run_lexer_test(void);
bool    run_quotes_tests(void);
bool	run_expand_tests(void);
bool	run_shrinker_tests(void);

#endif