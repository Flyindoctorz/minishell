/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delimiter_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:33:40 by cgelgon           #+#    #+#             */
/*   Updated: 2025/03/11 11:12:13 by cgelgon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/lexer_test.h"

bool	test_delimiter_true(void)
{
	bool	success;

	printf("\nis_delimiter true cases:\n");
	success = true;
	success &= print_test("space", is_delimiter(' '));
	success &= print_test("pipe", is_delimiter('|'));
	success &= print_test("less than", is_delimiter('<'));
	success &= print_test("greater than", is_delimiter('>'));
	success &= print_test("single quote", is_delimiter('\''));
	success &= print_test("\0", is_delimiter('\0'));
	return (success);
}

bool	test_delimiter_false(void)
{
	bool	success;

	printf("is_delimiter false cases:\n");
	success = true;
	success &= print_test("letter", !is_delimiter('a'));
	success &= print_test("number", !is_delimiter('1'));
	success &= print_test("underscore", !is_delimiter('_'));
	return (success);
}

bool	test_delimiter(void)
{
	bool	success;

	success = test_delimiter_true();
	success &= test_delimiter_false();
	return (success);
}