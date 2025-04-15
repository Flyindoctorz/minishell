/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_quotes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:54:38 by cgelgon           #+#    #+#             */
/*   Updated: 2025/04/15 16:55:09 by lmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static bool	validate_and_scan_quotes(t_lexer *lexer, t_quote_scan *qscan)
{
	advance_lexer(lexer);
	qscan->inside_start_pos = lexer->pos;
	qscan->len = 0;
	while (lexer->curr_char != '\0' && lexer->curr_char != qscan->quote_type)
	{
		advance_lexer(lexer);
		(qscan->len)++;
	}
	if (lexer->curr_char == '\0')
	{
		handle_error(MNSHL_ERR_SYNTAX, ERR_MSG_QUOTE_SYNTAX);
		lexer->pos = qscan->before_quote;
		lexer->read_pos = qscan->before_quote + 1;
		lexer->curr_char = lexer->input[qscan->before_quote];
		return (false);
	}
	return (true);
}

static void	init_quote_scan(t_quote_scan *qscan, t_lexer *lexer)
{
	qscan->before_quote = lexer->pos;
	qscan->quote_type = lexer->curr_char;
}

static t_token	*create__token(t_lexer *lexer, t_quote_scan *qscan)
{
	char	*quoted_content;
	t_token	*token;

	quoted_content = ft_substr(lexer->input, qscan->inside_start_pos,
			qscan->len);
	if (!quoted_content)
		return (NULL);
	token = create_token(get_quote_type(qscan->quote_type), quoted_content);
	if (!token)
	{
		free(quoted_content);
		return (NULL);
	}
	free(quoted_content);
	token->position = qscan->before_quote;
	advance_lexer(lexer);
	return (token);
}

t_token	*read_quotes(t_lexer *lexer)
{
	t_quote_scan	qscan;

	if (!lexer || !is_quote(lexer->curr_char))
	{
		handle_error(MNSHL_ERR_ARGS, "read_quotes : null lexer");
		return (NULL);
	}
	init_quote_scan(&qscan, lexer);
	if (!validate_and_scan_quotes(lexer, &qscan))
		return (NULL);
	return (create__token(lexer, &qscan));
}
