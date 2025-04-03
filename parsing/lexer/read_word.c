/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:16:27 by cgelgon           #+#    #+#             */
/*   Updated: 2025/04/03 14:28:25 by cgelgon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

//renvoi le nombre de charactere dans le mot 
// et avance la pos en consequence
static size_t	get_word_len(t_lexer *lexer)
{
	size_t	len;

	len = 0;
	while (lexer->curr_char && !is_delimiter(lexer->curr_char))
	{
		len++;
		advance_lexer(lexer);
	}
	return (len);
}

//stock le mot dans un token de type WORD et le return
// start pos = curr dans l'input(lexer)
static t_token	*create_word_token_type(t_lexer *lexer,
	int start_pos, size_t len)
{
	char	*word;
	t_token *word_token;

	word = ft_substr(lexer->input, start_pos, len);
	if (!word)
	{
		handle_error(MNSHL_ERR_MEMORY, "read_word : ft_substr failed");
		return (NULL);
}
word_token = create_token(TOKEN_WORD, word);
free(word);
if (!word_token)
{
	handle_error(MNSHL_ERR_MEMORY, "read_word : create_token failed");
	return (NULL);
}
word_token->position = start_pos;
return (word_token);
}
// mot = tout les carac jusqu'au delimiter
// lit le mot complet et return le mot lu
t_token	*read_word(t_lexer *lexer)
{
	size_t	len;
	int		start_pos;
	
	if (!lexer)
	{
		handle_error(MNSHL_ERR_ARGS, "read_word : lexer is NULL");
		return (NULL);
	}
	if (!lexer->input)
	{
		handle_error(MNSHL_ERR_ARGS, "read_word : lexer->input is NULL");
		return (NULL);
	}
	if (lexer->input[0] == '\0')
		return (NULL);
	start_pos = lexer->pos;
	len = get_word_len(lexer);
	if (len == 0)
		return (NULL);
	return (create_word_token_type(lexer, start_pos, len));
}

