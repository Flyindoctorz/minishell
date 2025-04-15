/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 12:28:21 by cgelgon           #+#    #+#             */
/*   Updated: 2025/04/15 17:08:45 by lmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
static t_lexer	*validate_input(char *input, t_data *data)
{
	t_lexer	*lexer;

	if (!input || !data)
	{
		handle_error(MNSHL_ERR_ARGS, "Tokenize input : null input or data");
		return (NULL);
	}
	lexer = init_lexer(input, data);
	if (!lexer)
	{
		handle_error(MNSHL_ERR_MEMORY,
			"tokenize_input : lexer creation failed");
		return (NULL);
	}
	return (lexer);
}*/
bool	skip_comment(t_lexer *lexer)
{
	if (lexer->curr_char == '#')
	{
		while (lexer->curr_char && lexer->curr_char != '\n')
			advance_lexer(lexer);
		return (true);
	}
	return (false);
}

t_token	*process_token_error(t_lexer *lexer, t_token *token)
{
	printf("Syntax error at position %d\n", token->position);
	free_token_list(lexer->tokens);
	free_token_list(token);
	return (NULL);
}

static t_token	*generate_tokens(t_lexer *lexer)
{
	t_token	*token;
	t_token	*eof_token;

	while (lexer->curr_char)
	{
		if (skip_comment(lexer))
			continue ;
		token = tokenize_current(lexer);
		if (token)
		{
			if (token->toktype == TOKEN_ERROR)
				return (process_token_error(lexer, token));
			add_token(lexer, token);
		}
	}
	eof_token = create_token(TOKEN_EOF, NULL);
	add_token(lexer, eof_token);
	return (lexer->tokens);
}

t_token	*tokenize_input(char *input, t_data *data)
{
	t_lexer	*lexer;
	t_token	*tokens;

	lexer = init_lexer(input, data);
	if (!lexer)
	{
		handle_error(MNSHL_ERR_MEMORY,
			"tokenize_input : lexer creation failed");
		return (NULL);
	}
	tokens = generate_tokens(lexer);
	free_lexer(lexer);
	return (tokens);
}
