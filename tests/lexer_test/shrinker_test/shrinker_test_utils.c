/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shrinker_test_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 18:15:20 by cgelgon           #+#    #+#             */
/*   Updated: 2025/03/11 11:14:56 by cgelgon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/lexer_test.h"

void    free_test_tokens(t_token *token1, t_token *token2)
{
    if (token1)
    {
		if (token1->value)
        	free(token1->value);
        free(token1);
    }
    if (token2)
    {
		if (token2->value)
       		free(token2->value);
        free(token2);
    }
}
void    free_test_tokens_with_merged(t_token *token1, t_token *token2, t_token *merged)
{
    if (token1)
    {
		if (token1->value)
        	free(token1->value);
        free(token1);
    }
    if (token2)
    {
		if (token2->value)
        	free(token2->value);
        free(token2);
    }
    if (merged)
    {
		if (merged->value)
        	free(merged->value);
        free(merged);
    }
}

void    free_cleanup_tokens(t_token *t1, t_token *t2, t_token *t3, t_token *t4)
{
    if (t1)
    {
        if (t1->value)
            free(t1->value);
        free(t1);
    }
    if (t2)
    {
        if (t2->value)
            free(t2->value);
        free(t2);
    }
    if (t3)
    {
        if (t3->value)
            free(t3->value);
        free(t3);
    }
    if (t4)
    {
        if (t4->value)
            free(t4->value);
        free(t4);
    }
}

bool    verify_shrinked_token(t_token *token, t_token_type expected_type, char *expected_value)
{
    if (!token)
    {
        printf("Erreur: token NULL lors de la vérification\n");
        return false;
    }
    if (token->toktype != expected_type)
    {
        printf("Erreur de type: attendu %d, obtenu %d\n", expected_type, token->toktype);
        return false;
    }
    if (expected_value == NULL && token->value != NULL)
    {
        printf("Erreur de valeur: attendu NULL, obtenu %s\n", token->value);
        return false;
    }
    else if (expected_value != NULL)
    {
        if (token->value == NULL)
        {
            printf("Erreur de valeur: attendu %s, obtenu NULL\n", expected_value);
            return false;
        }
        else if (ft_strcmp(token->value, expected_value) != 0)
        {
            printf("Erreur de valeur: attendu %s, obtenu %s\n", 
                   expected_value, token->value);
            return false;
        }
    }
    return true;
}

bool    verify_multiple_tokens(t_token *tokens)
{
    if (!tokens)
        return false;
    if (tokens->toktype != TOKEN_REDIR_OUT || 
        !tokens->value || 
        ft_strcmp(tokens->value, "file1.txt") != 0 ||
        tokens->shrinked != TOKEN_WORD)
        return false;
    tokens = tokens->next;
    if (!tokens)
        return false;
    if (tokens->toktype != TOKEN_REDIR_IN || 
        !tokens->value || 
        ft_strcmp(tokens->value, "file2.txt") != 0 ||
        tokens->shrinked != TOKEN_WORD)
        return false;
    if (tokens->next != NULL)
        return false;
    
    return true;
}