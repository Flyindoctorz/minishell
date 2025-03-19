/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shrinker_test_basic.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:11:22 by cgelgon           #+#    #+#             */
/*   Updated: 2025/03/11 11:14:26 by cgelgon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/lexer_test.h"

bool	test_is_redir(void)
{
	bool	success;
	t_token	*redir_token;
	t_token	*word_token;

	printf("\nTest de is_redir:\n");
	redir_token = create_token(TOKEN_REDIR_OUT, ">");
	success = print_test("Token de redirection", is_redir(redir_token));
	word_token = create_token(TOKEN_WORD, "hello");
	success &= print_test("Token non-redirection", !is_redir(word_token));
	success &= print_test("Token NULL", !is_redir(NULL));
	free_test_tokens(redir_token, word_token);
	return (success);
}

static void	print_token_info(t_token *token, char *desc)
{
	if (token)
		printf("%s : toktype=%d, value='%s'%s\n", 
			desc, token->toktype, token->value ? token->value : "NULL",
			token->shrinked ? ", shrinked" : "");
	else
		printf("%s : NULL\n", desc);
}

static bool	check_merged_token(t_token *merged)
{
	if (!merged)
		return (false);
	return (merged->toktype == TOKEN_REDIR_OUT &&
			merged->value &&
			strcmp(merged->value, "file.txt") == 0 &&
			merged->shrinked == TOKEN_WORD);
}

bool	test_merge_redir(void)
{
	bool	success;
	t_token	*redir_token;
	t_token	*target_token;
	t_token	*merged_token;

	printf("\nTest de merge_redir:\n");
	redir_token = create_token(TOKEN_REDIR_OUT, ">");
	target_token = create_token(TOKEN_WORD, "file.txt");
	merged_token = merge_redir(redir_token, target_token);
	print_token_info(redir_token, "Token de redirection");
	print_token_info(target_token, "Token cible");
	print_token_info(merged_token, "Token fusionné");
	success = print_test("Fusion basique", check_merged_token(merged_token));
	success &= print_test("Target NULL", 
				merge_redir(redir_token, NULL) == NULL);
	success &= print_test("Redir NULL", 
				merge_redir(NULL, target_token) == NULL);
	free_test_tokens_with_merged(redir_token, target_token, merged_token);
	return (success);
}