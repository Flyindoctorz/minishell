/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_word_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:40:56 by cgelgon           #+#    #+#             */
/*   Updated: 2025/03/11 11:13:09 by cgelgon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/lexer_test.h"

bool	test_read_word_basic(void)
{
	bool	success;

	printf("\nBasic word reading tests:\n");
	success = true;
	success &= print_test("simple word", 
			test_single_word("hello", "hello"));
	success &= print_test("word with space", 
			test_single_word("hello ", "hello"));
	success &= print_test("word with underscore",
			test_single_word("hello_world", "hello_world"));
	return (success);
}

bool	test_read_word_advanced(void)
{
	bool	success;

	printf("\nAdvanced word reading tests:\n");
	success = true;
	if (!print_test("empty input",
			test_single_word("", NULL)))
		success = false;
	if (!print_test("spaces before word",
			test_single_word("   hello", "hello")))
		success = false;
	if (!print_test("word before operator",
			test_single_word("hello|world", "hello")))
		success = false;
	return (success);
}

bool	test_read_word_edge(void)
{
	bool	success;

	printf("\nEdge cases word reading tests:\n");
	success = true;
	success &= print_test("special chars",
			test_single_word("hello@world#123", "hello@world#123"));
	success &= print_test("word before redirect",
			test_single_word("hello>file", "hello"));
	return (success);
}

bool	test_read_word(void)
{
	bool	success;

	success = test_read_word_basic();
	success &= test_read_word_advanced();
	success &= test_read_word_edge();
	return (success);
}