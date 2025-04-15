/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_main2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:07:15 by lmokhtar          #+#    #+#             */
/*   Updated: 2025/04/15 17:08:40 by lmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_token	*apply_shrink(t_token *tokens)
{
	t_token	*shrinked;

	if (!tokens)
		return (NULL);
	shrinked = shrink_redir_tokens(tokens);
	if (!shrinked)
	{
		free_token_list(tokens);
		return (NULL);
	}
	if (shrinked != tokens)
		free_token_list(tokens);
	return (shrinked);
}

// evite les white space et utilise le read adequat
// renvoie le token current
static t_token	*handle_token_error(t_lexer *lexer, int start_pos, char *msg)
{
	t_token	*token;

	(void)lexer;
	handle_error(MNSHL_ERR_MEMORY, msg);
	token = create_token(TOKEN_ERROR, "Token creation failed");
	token->position = start_pos;
	return (token);
}

static t_token	*handle_syntax_error(int start_pos)
{
	t_token	*token;

	token = create_token(TOKEN_ERROR, "Syntax error");
	token->position = start_pos;
	return (token);
}

static t_token	*process_token(t_lexer *lexer, int start_pos)
{
	t_token	*token;

	if (is_expand_char(lexer->curr_char))
		token = read_expand(lexer);
	else if (is_operator(lexer->curr_char))
	{
		if (!check_op_syntax(lexer))
			return (handle_syntax_error(start_pos));
		token = read_operator(lexer);
	}
	else if (is_quote(lexer->curr_char))
		token = read_quotes(lexer);
	else
		token = read_word(lexer);
	if (!token)
		return (handle_token_error(lexer, start_pos,
				"process_next_token : token creation failed"));
	return (token);
}

t_token	*tokenize_current(t_lexer *lexer)
{
	int	start_pos;

	if (is_whitespace(lexer->curr_char))
	{
		advance_lexer(lexer);
		return (NULL);
	}
	start_pos = lexer->pos;
	return (process_token(lexer, start_pos));
}
