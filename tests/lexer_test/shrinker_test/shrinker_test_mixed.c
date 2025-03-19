/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shrinker_test_mixed.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:20:31 by cgelgon           #+#    #+#             */
/*   Updated: 2025/03/11 11:22:34 by cgelgon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/lexer_test.h"

/**
 * @brief Crée une liste mixte de tokens pour les tests
 * 
 * @return t_token* La liste créée, ou NULL en cas d'erreur
 */
t_token	*create_mixed_tokens(void)
{
	t_token	*echo;
	t_token	*hello;
	t_token	*redir;
	t_token	*file;
	
	echo = create_token(TOKEN_WORD, "echo");
	hello = create_token(TOKEN_WORD, "hello");
	redir = create_token(TOKEN_REDIR_OUT, ">");
	file = create_token(TOKEN_WORD, "file.txt");
	
	if (!echo || !hello || !redir || !file)
	{
		free_cleanup_tokens(echo, hello, redir, file);
		return (NULL);
	}
	
	echo->next = hello;
	hello->next = redir;
	redir->next = file;
	
	return (echo);
}

static void	print_mixed_tokens(t_token *tokens)
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

bool verify_mixed_tokens(t_token *shrinked)
{
    if (!shrinked)
        return (false);

    if (shrinked->toktype != TOKEN_WORD || 
        ft_strcmp(shrinked->value, "echo") != 0)
        return (false);
    if (!shrinked->next || 
        shrinked->next->toktype != TOKEN_WORD || 
        ft_strcmp(shrinked->next->value, "hello") != 0)
        return (false);
    if (!shrinked->next->next || 
        shrinked->next->next->toktype != TOKEN_REDIR_OUT || 
        ft_strcmp(shrinked->next->next->value, "file.txt") != 0 ||
        shrinked->next->next->shrinked != TOKEN_WORD)
        return (false);
    if (shrinked->next->next->next != NULL)
        return (false);

    return (true);
}

bool test_shrink_mixed_tokens(void)
{
    t_token *tokens;
    t_token *shrinked;
    bool success;
    
    tokens = create_mixed_tokens();
    if (!tokens)
        return (print_test("Création de tokens mixtes", false));
    printf("Tokens originaux avant shrinking:\n");
    print_mixed_tokens(tokens);
    shrinked = shrink_redir_tokens(tokens);
    printf("Tokens après shrinking:\n");
    print_mixed_tokens(shrinked);
    success = verify_mixed_tokens(shrinked);
    success = print_test("Tokens mixtes", success);
    if (tokens != shrinked)
        free_token_list(tokens);
    free_token_list(shrinked);
    
    return (success);
}