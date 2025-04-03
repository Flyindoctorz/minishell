/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:20:05 by cgelgon           #+#    #+#             */
/*   Updated: 2025/04/03 14:27:56 by cgelgon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// defini les quotes
bool	is_quote(char c)
{
	return (c == '\'' || c == '\"');
}

t_token_type	get_quote_type(char c)
{
	if (c == '\'')
		return (TOKEN_QUOTES);
	else if (c == '\"')
		return (TOKEN_DQUOTES);
	return (TOKEN_ERROR);
}
// parcours tout les charac pour trouver la fin de la quote
// s'il trouve = true = valide
// s'il ne trouve pas = false = erreur
bool	check_quote_end(t_lexer *lexer, char quote)
{
	int		saved_pos;
	int		saved_read_pos;
	char	saved_char;

	if (!lexer)
		return (false);
	saved_pos = lexer->pos;
	saved_read_pos = lexer->read_pos;
	saved_char = lexer->curr_char;
	advance_lexer(lexer);
	while (lexer->curr_char != '\0')
	{
		if (lexer->curr_char == quote)
		{
			lexer->pos = saved_pos;
			lexer->read_pos = saved_read_pos;
			lexer->curr_char = saved_char;
			return (true);
		}
		advance_lexer(lexer);
	}
	lexer->pos = saved_pos;
	lexer->read_pos = saved_read_pos;
	lexer->curr_char = saved_char;
	handle_error(MNSHL_ERR_SYNTAX, ERR_MSG_QUOTE_SYNTAX);
	return (false);
}

// parcours tout les charac pour trouver la fin de la quote sa len
int	get_quote_len(t_lexer *lexer, char quote)
{
	int	len;
	int	curr_pos;

	len = 0;
	curr_pos = lexer->pos;
	while (lexer->curr_char && lexer->curr_char != quote)
	{
		advance_lexer(lexer);
		len++;
	}
	lexer->pos = curr_pos;
	lexer->curr_char = lexer->input[curr_pos];
	lexer->read_pos = curr_pos + 1;
	return (len);
}

// le contenu des quotes est renvoye dans un pointeur malloc
// le token est cree avec le contenu des quotes
t_token	*create_quote_token(t_lexer *lexer, int len, int start_pos)
{
	t_token	*token;
	char	*inside_quote;

	if (!lexer || len < 0 || start_pos < 0)
	{
		handle_error(MNSHL_ERR_ARGS, "create_quote_token : invalid args");
		return (NULL);
	}
	inside_quote = ft_substr(lexer->input, start_pos, len);
	if (!inside_quote)
	{
		handle_error(MNSHL_ERR_MEMORY, "create_quote_token : ft_substr failed");
		return (NULL);
	}
	token = create_token(get_quote_type(lexer->input[start_pos - 1]),
			inside_quote);
	free(inside_quote);
	if (!token)
	{
		handle_error(MNSHL_ERR_MEMORY,
			"create_quote_token : create_token failed");
		return (NULL);
	}
	token->position = start_pos - 1;
	return (token);
}

//