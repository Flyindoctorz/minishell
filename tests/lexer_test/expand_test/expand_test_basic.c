/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_test_basic.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:08:30 by cgelgon           #+#    #+#             */
/*   Updated: 2025/03/11 11:13:31 by cgelgon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/lexer_test.h"

//Test d'expansion basique : variable simple

static bool	test_basic_var(void)
{
	return (print_test("simple expansion var", 
			test_expand_content("$HOME", "HOME", TOKEN_EXPAND)));
}

//Test d'expansion : variable avec chiffres

static bool	test_var_with_numbers(void)
{
	return (print_test("var with numbers", 
			test_expand_content("$USER42", "USER42", TOKEN_EXPAND)));
}

//Test d'expansion : variable avec underscore
static bool	test_var_with_underscore(void)
{
	return (print_test("var with underscore", 
			test_expand_content("$MY_VAR", "MY_VAR", TOKEN_EXPAND)));
}

//Teste les expansions de base
bool	test_expand_basic(void)
{
	bool	success;

	printf("\nBasic expansion tests:\n");
	success = true;
	success &= test_basic_var();
	success &= test_var_with_numbers();
	success &= test_var_with_underscore();
	return (success);
}

//Teste les expansions isolées ($ seul)
bool	test_expand_isolated(void)
{
	bool	success;

	printf("\nIsolated $ tests:\n");
	success = true;
	success &= print_test("$ followed by space", 
			test_expand_content("$ ", "$", TOKEN_DOLLAR));
	success &= print_test("$ followed by pipe", 
			test_expand_content("$|", "$", TOKEN_DOLLAR));
	success &= print_test("$ at end of string", 
			test_expand_content("$", "$", TOKEN_DOLLAR));
	return (success);
}