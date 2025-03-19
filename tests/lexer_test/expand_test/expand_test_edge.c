/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_test_edge.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:21:15 by cgelgon           #+#    #+#             */
/*   Updated: 2025/03/11 11:13:38 by cgelgon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/lexer_test.h"

//Test d'expansion avec caractères spéciaux 
static bool	test_special_chars(void)
{
	return (print_test("expansion with special chars", 
			test_expand_content("$VAR?", "VAR", TOKEN_EXPAND)));
}

//Test d'expansion avant une quote
static bool	test_before_quote(void)
{
	return (print_test("expansion before quote", 
			test_expand_content("$VAR'quoted'", "VAR", TOKEN_EXPAND)));
}

//Test d'expansion avant un opérateur
static bool	test_before_operator(void)
{
	return (print_test("expansion before operator", 
			test_expand_content("$VAR>file", "VAR", TOKEN_EXPAND)));
}

//Teste les cas limites des expansions
bool	test_expand_edge_cases(void)
{
	bool	success;

	printf("\nExpansion edge cases:\n");
	success = true;
	success &= test_special_chars();
	success &= test_before_quote();
	success &= test_before_operator();
	return (success);
}

//Teste les comportements spéciaux des expansions
bool	test_expand_special_cases(void)
{
	t_data	*data;
	t_lexer	*lexer;
	bool	success;
	
	printf("\nExpansion special cases:\n");
	success = true;
	data = create_test_data();
	if (!data)
		return (false);
	lexer = init_lexer("hello", data);
	success &= print_test("not starting with $", 
					read_expand(lexer) == NULL);
	free_lexer(lexer);
	lexer = init_lexer(NULL, data);
	success &= print_test("null input", read_expand(lexer) == NULL);
	free_data(data);
	return (success);
}