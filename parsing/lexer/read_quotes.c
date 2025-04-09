/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_quotes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:54:38 by cgelgon           #+#    #+#             */
/*   Updated: 2025/04/09 13:37:36 by cgelgon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// // lit et tokenize le content sous quotes
// // gere double quotes et single quotes
// // renvoie le token cree
// t_token	*read_quotes(t_lexer *lexer)
// {
// 	char	quote_type;
// 	int		start_pos;
// 	int		len;
// 	t_token	*token;

// 	if (!lexer || !is_quote(lexer->curr_char))
// 	{
// 		handle_error(MNSHL_ERR_ARGS, "read_quotes : null lexer");
// 		return (NULL);
// 	}
// 	quote_type = lexer->curr_char;
// 	if (!check_quote_end(lexer, quote_type))
// 		return (NULL);
// 	advance_lexer(lexer);
// 	start_pos = lexer->pos;
// 	len = get_quote_len(lexer, quote_type);
// 	token = create_quote_token(lexer, len, start_pos);
// 	if (!token)
// 		return (NULL);
// 	if (lexer->curr_char == quote_type)
// 		advance_lexer(lexer);
// 	return (token);
// }

// false si quote not terminated
static bool	validate_and_scan_quotes(t_lexer *lexer, char quote_type,
		int before_quote, int *inside_start_pos, int *len)
{
	advance_lexer(lexer);
	*inside_start_pos = lexer->pos;
	*len = 0;
	while (lexer->curr_char != '\0' && lexer->curr_char != quote_type)
	{
		advance_lexer(lexer);
		(*len)++;
	}
	if (lexer->curr_char == '\0')
	{
		handle_error(MNSHL_ERR_SYNTAX, ERR_MSG_QUOTE_SYNTAX);
		lexer->pos = before_quote;
		lexer->read_pos = before_quote + 1;
		lexer->curr_char = lexer->input[before_quote];
		return (false);
	}
	return (true);
}
// lis et tokenize le content sous quotes
// handle erreurs et empty quotes
t_token	*read_quotes(t_lexer *lexer)
{
	char quote_type;
	int before_quote;
	int inside_start_pos;
	int len;
	t_token *token;

	if (!lexer || !is_quote(lexer->curr_char))
	{
		handle_error(MNSHL_ERR_ARGS, "read_quotes : null lexer");
		return (NULL);
	}
	quote_type = lexer->curr_char;
	before_quote = lexer->pos;
	if (!validate_and_scan_quotes(lexer, quote_type, before_quote,
			&inside_start_pos, &len))
		return (NULL);
	token = create_token(get_quote_type(quote_type), ft_substr(lexer->input,
				inside_start_pos, len));
	if (!token)
		return (NULL);
	token->position = before_quote;
	advance_lexer(lexer);
	return (token);
}