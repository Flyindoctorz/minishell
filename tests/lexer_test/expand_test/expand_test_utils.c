/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_test_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:32:48 by cgelgon           #+#    #+#             */
/*   Updated: 2025/03/11 11:13:43 by cgelgon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/lexer_test.h"

//Initialise les ressources pour tester l'expansion
bool	init_expand_test(t_data **data, t_lexer **lexer, char *input)
{
	*data = create_test_data();
	if (!*data)
		return (false);
	*lexer = init_lexer(input, *data);
	if (!*lexer)
	{
		free_data(*data);
		return (false);
	}
	return (true);
}

//Vérifie si le token correspond aux attentes
bool	verify_expand_token(t_token *token, char *expected, 
		t_token_type expected_type)
{
	if (!token && !expected)
		return (true);
	if (!token || !expected)
		return (false);
	return (token->toktype == expected_type
		&& ft_strcmp(token->value, expected) == 0);
}

//Nettoie les ressources utilisées dans le test
void	cleanup_expand_test(t_token *token, t_lexer *lexer, t_data *data)
{
	if (token)
	{
		free(token->value);
		free(token);
	}
	free_lexer(lexer);
	free_data(data);
}

//Fonction principale pour tester les expansions
bool	test_expand_content(char *input, char *expected, 
		t_token_type expected_type)
{
	t_data	*data;
	t_lexer	*lexer;
	t_token	*token;
	bool	success;

	if (!init_expand_test(&data, &lexer, input))
		return (false);
	token = read_expand(lexer);
	success = verify_expand_token(token, expected, expected_type);
	cleanup_expand_test(token, lexer, data);
	return (success);
}

//Exécute tous les tests d'expansion
bool	run_expand_tests(void)
{
	bool	success;

	printf("\n=== EXPAND TEST SUITE START ===\n");
	success = test_expand_basic();
	success &= test_expand_isolated();
	success &= test_expand_edge_cases();
	success &= test_expand_special_cases();
	printf("=== EXPAND TEST SUITE END ===\n");
	return (success);
}