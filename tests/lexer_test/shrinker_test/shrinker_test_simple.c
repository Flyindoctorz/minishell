/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shrinker_test_simple.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:21:05 by cgelgon           #+#    #+#             */
/*   Updated: 2025/03/11 11:14:50 by cgelgon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/lexer_test.h"

t_token	*create_simple_redir_tokens(void)
{
	t_token	*redir;
	t_token	*file;

	redir = create_token(TOKEN_REDIR_OUT, ">");
	if (!redir)
		return (NULL);
	file = create_token(TOKEN_WORD, "file.txt");
	if (!file)
	{
		if (redir->value)
			free(redir->value);
		free(redir);
		return (NULL);
	}
	redir->next = file;
	return (redir);
}

static void	print_simple_tokens(t_token *tokens, t_token *shrinked)
{
	printf("Tokens originaux: ");
	if (tokens && tokens->value)
		printf("[%s", tokens->value);
	else
		printf("[NULL");
	if (tokens && tokens->next && tokens->next->value)
		printf(", %s]\n", tokens->next->value);
	else
		printf(", NULL]\n");
	printf("Tokens après shrink: ");
	if (shrinked && shrinked->value)
		printf("[%s]\n", shrinked->value);
	else
		printf("[NULL]\n");
}

bool	test_shrink_simple_redirection(void)
{
	t_token	*tokens;
	t_token	*shrinked;
	bool	success;

	tokens = create_simple_redir_tokens();
	if (!tokens)
		return (print_test("Création de tokens simple", false));
	print_simple_tokens(tokens, NULL);
	shrinked = shrink_redir_tokens(tokens);
	print_simple_tokens(NULL, shrinked);
	success = verify_shrinked_token(shrinked, TOKEN_REDIR_OUT, "file.txt");
	success = print_test("Redirection simple", success);
	if (tokens != shrinked && tokens)
		free_token_list(tokens);
	if (shrinked)
		free_token_list(shrinked);
	return (success);
}