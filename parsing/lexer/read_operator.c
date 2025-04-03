/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_operator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:16:58 by cgelgon           #+#    #+#             */
/*   Updated: 2025/04/03 17:33:59 by lmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// si double op >> <<, les crees, avance de 2 et return le token
static t_token	*double_op_handler(t_lexer *lexer)
{
	t_token	*token;

	if (lexer->curr_char == '>')
		token = create_token(TOKEN_APPEND, ">>");
	else
		token = create_token(TOKEN_HEREDOC, "<<");
	if (!token)
	{
		handle_error(MNSHL_ERR_MEMORY,
			"double_op_handler : create_token failed");
		return (NULL);
	}
	advance_lexer(lexer);
	advance_lexer(lexer);
	return (token);
}

static t_token	*single_op_handler(t_lexer *lexer)
{
	t_token	*token;

	if (lexer->curr_char == '|')
		token = create_token(TOKEN_PIPE, "|");
	else if (lexer->curr_char == '>')
		token = create_token(TOKEN_REDIR_OUT, ">");
	else if (lexer->curr_char == '<')
		token = create_token(TOKEN_REDIR_IN, "<");
	else
	{
		handle_error(MNSHL_ERR_SYNTAX, "read_operator : invalid operator");
		return (NULL);
	}
	advance_lexer(lexer);
	return (token);
}

static bool	check_op_syntax(t_lexer *lexer)
{
	char	next;

	if (!lexer)
	{
		handle_error(MNSHL_ERR_ARGS, "check_op_syntax : null lexer");
		return (false);
	}
	next = look_forward(lexer);
	if (lexer->curr_char == '|' && lexer->pos == 0)
	{
		handle_error(MNSHL_ERR_SYNTAX, ERR_MSG_PIPE_SYNTAX);
		return (false);
	}
	if ((lexer->curr_char == '>' || lexer->curr_char == '<') && !next)
	{
		handle_error(MNSHL_ERR_SYNTAX, ERR_MSG_REDIR_SYNTAX);
		return (false);
	}
	if ((lexer->curr_char == '>' && next == '<') || (lexer->curr_char == '<'
			&& next == '>'))
	{
		handle_error(MNSHL_ERR_SYNTAX, ERR_MSG_CONSEC_SYNTAX);
		return (false);
	}
	return (true);
}

t_token	*read_operator(t_lexer *lexer)
{
	t_token	*op_token;
	char	next;
	int		start_pos;

	if (!check_op_syntax(lexer))
		return (NULL);
	next = look_forward(lexer);
	start_pos = lexer->pos;
	if ((lexer->curr_char == '>' && next == '>') || (lexer->curr_char == '<'
			&& next == '<'))
		op_token = double_op_handler(lexer);
	else
		op_token = single_op_handler(lexer);
	if (!op_token)
	{
		handle_error(MNSHL_ERR_MEMORY,
			"read_operator : op_token creation failed");
		return (NULL);
	}
	op_token->position = start_pos;
	return (op_token);
}
