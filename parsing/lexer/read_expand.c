/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_expand.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:16:56 by cgelgon           #+#    #+#             */
/*   Updated: 2025/04/15 16:47:30 by lmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// Lit un symbole d'expansion ($) et crée un token approprié
// Détecte si c'est un $ isolé ou une variable à expandre
t_token	*read_expand(t_lexer *lexer)
{
	int	start_pos;

	if (!lexer || lexer->curr_char != '$')
	{
		handle_error(MNSHL_ERR_ARGS, "read_expand : invalid input");
		return (NULL);
	}
	start_pos = lexer->pos;
	advance_lexer(lexer);
	if (is_whitespace(lexer->curr_char) || lexer->curr_char == '\0'
		|| is_delimiter(lexer->curr_char))
		return (create_dollar_token(start_pos));
	return (create_expand_token(lexer, start_pos));
}

t_token	*create_token(t_token_type type, char *value)
{
	t_token	*token;

	token = (t_token *)malloc(sizeof(t_token));
	if (!token)
	{
		handle_error(MNSHL_ERR_MEMORY, "malloc failed in create_token");
		return (NULL);
	}
	token->toktype = type;
	if (value)
	{
		token->value = strdup(value);
		if (!token->value)
		{
			free(token);
			handle_error(MNSHL_ERR_MEMORY, "stdup failed in create_token");
			return (NULL);
		}
	}
	else
		token->value = NULL;
	token->position = 0;
	token->next = NULL;
	return (token);
}
