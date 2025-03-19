/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_expand.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:16:56 by cgelgon           #+#    #+#             */
/*   Updated: 2025/02/26 11:35:11 by cgelgon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lexer.h"


//Lit un symbole d'expansion ($) et crée un token approprié
//Détecte si c'est un $ isolé ou une variable à expandre
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