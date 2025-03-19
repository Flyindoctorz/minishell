/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shrinker_test_run.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:50:20 by cgelgon           #+#    #+#             */
/*   Updated: 2025/03/11 11:14:44 by cgelgon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/lexer_test.h"

bool	test_shrink_redir_tokens(void)
{
    bool success;
    
    printf("\nTests de shrink_redir_tokens:\n");
    success = test_shrink_simple_redirection();
    success &= test_shrink_multiple_redirections();
    success &= test_shrink_mixed_tokens();
    
    return (success);
}

void	print_shrinker_results(bool success)
{
	printf("\nRésumé des tests shrinker: ");
	if (success)
		printf("\033[0;32mTous les tests ont réussi\033[0m\n");
	else
		printf("\033[0;31mCertains tests ont échoué\033[0m\n");
}

bool	run_shrinker_tests(void)
{
	bool	success;
	
	success = true;
	printf("\n=== SHRINKER TEST SUITE START ===\n");
	success &= test_is_redir();
	success &= test_merge_redir();
	success &= test_shrink_redir_tokens();
	print_shrinker_results(success);
	printf("=== SHRINKER TEST SUITE END ===\n");
	return (success);
}