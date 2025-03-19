/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whitespace_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:23:50 by cgelgon           #+#    #+#             */
/*   Updated: 2025/03/11 11:13:17 by cgelgon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/lexer_test.h"

bool	test_whitespace_true(void)
{
	bool	success;

	printf("\nis_whitespace true cases:\n");
	success = true;
	success &= print_test("space", is_whitespace(' '));
	success &= print_test("tab", is_whitespace('\t'));
	success &= print_test("newline", is_whitespace('\n'));
	success &= print_test("carriage return", is_whitespace('\r'));
	return (success);
}

bool	test_whitespace_false(void)
{
	bool	success;

	printf("is_whitespace false cases:\n");
	success = true;
	success &= print_test("letter", !is_whitespace('a'));
	success &= print_test("number", !is_whitespace('1'));
	success &= print_test("pipe", !is_whitespace('|'));
	success &= print_test("null byte", !is_whitespace('\0'));
	return (success);
}

bool	test_whitespace(void)
{
	bool	success;

	success = test_whitespace_true();
	success &= test_whitespace_false();
	return (success);
}

bool	test_skip_whitespace(void)
{
	t_lexer	*lexer;
	t_data	*data;
	bool	success;

	data = create_test_data();
	if (!data)
		return (false);
	lexer = init_lexer("   hello", data);
	if (!lexer)
	{
		free_data(data);
		return (false);
	}
	skip_whitespace(lexer);
	success = (lexer->curr_char == 'h');
	print_test("skip basic whitespace", success);
	free_lexer(lexer);
	free_data(data);
	return (success);
}

bool	test_skip_mixed_whitespace(void)
{
	t_lexer	*lexer;
	t_data	*data;
	bool	success;

	data = create_test_data();
	if (!data)
		return (false);
	lexer = init_lexer(" \t\n\r hello", data);
	if (!lexer)
	{
		free_data(data);
		return (false);
	}
	skip_whitespace(lexer);
	success = (lexer->curr_char == 'h');
	print_test("skip mixed whitespace", success);
	free_lexer(lexer);
	free_data(data);
	return (success);
}
