/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shrinker_test_multiple.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:21:30 by cgelgon           #+#    #+#             */
/*   Updated: 2025/03/11 11:14:41 by cgelgon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/lexer_test.h"

t_token	*create_multiple_redir_tokens(void)
{
	t_token	*redir_out;
	t_token	*file1;
	t_token	*redir_in;
	t_token	*file2;
	
	redir_out = create_token(TOKEN_REDIR_OUT, ">");
	file1 = create_token(TOKEN_WORD, "file1.txt");
	redir_in = create_token(TOKEN_REDIR_IN, "<");
	file2 = create_token(TOKEN_WORD, "file2.txt");
	
	if (!redir_out || !file1 || !redir_in || !file2)
	{
		free_cleanup_tokens(redir_out, file1, redir_in, file2);
		return (NULL);
	}
	
	redir_out->next = file1;
	file1->next = redir_in;
	redir_in->next = file2;
	
	return (redir_out);
}

static void	print_multiple_tokens(t_token *tokens)
{
	t_token	*curr;
	
	printf("Tokens: ");
	if (!tokens)
	{
		printf("[NULL]\n");
		return ;
	}
	printf("[");
	curr = tokens;
	while (curr)
	{
		printf("{type=%d, value='%s'}", curr->toktype, 
			curr->value ? curr->value : "NULL");
		if (curr->next)
			printf(", ");
		curr = curr->next;
	}
	printf("]\n");
}

bool	test_shrink_multiple_redirections(void)
{
	t_token	*tokens;
	t_token	*shrinked;
	bool	success;
	
	tokens = create_multiple_redir_tokens();
	if (!tokens)
		return (print_test("Création de tokens multiples", false));
	printf("Tokens originaux:\n");
	print_multiple_tokens(tokens);
	shrinked = shrink_redir_tokens(tokens);
	printf("Tokens après shrink:\n");
	print_multiple_tokens(shrinked);
	success = verify_multiple_tokens(shrinked);
	success = print_test("Multiples redirections", success);
	if (tokens != shrinked && tokens)
		free_token_list(tokens);
	if (shrinked)
		free_token_list(shrinked);
	
	return (success);
}