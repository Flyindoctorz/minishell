/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_run.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:09:15 by cgelgon           #+#    #+#             */
/*   Updated: 2025/03/11 11:12:23 by cgelgon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/lexer_test.h"

void	run_init_tests(void)
{
	printf("\nInit Tests:\n");
	test_init_lexer();
	test_look_forward_basic();
	test_look_forward_advanced();
	test_null_input();
	test_empty_input();
}

void	run_utils_tests(void)
{
	printf("\nUtils Tests:\n");
	test_whitespace();
	test_delimiter();
	test_create_token_basic();
	test_create_token_advanced();
	test_skip_whitespace();
	test_skip_mixed_whitespace();
	test_read_word();
	test_operator_syntax_errors();
	test_pipe_syntax_errors();
	test_redir_syntax_errors();
	run_quotes_tests();
	run_expand_tests();
	run_shrinker_tests();
}

void	run_lexer_test(void)
{
	printf("\n=== LEXER TEST SUITE START ===\n");
	run_init_tests();
	run_utils_tests();
	printf("\n=== LEXER TEST SUITE END ===\n");
}



