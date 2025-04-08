/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 12:28:21 by cgelgon           #+#    #+#             */
/*   Updated: 2025/04/08 15:05:28 by cgelgon          ###   ########.fr       */
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
t_token	*tokenize_current(t_lexer *lexer)
{
	t_token	*token;
	int		start_pos;

	if (is_whitespace(lexer->curr_char))
	{
		advance_lexer(lexer);
		return (NULL);
	}
	start_pos = lexer->pos;
	if (is_expand_char(lexer->curr_char))
		token = read_expand(lexer);
	else if (is_operator(lexer->curr_char))
	{
		if (!check_op_syntax(lexer))
		{
			token = create_token(TOKEN_ERROR, "Syntax error");
			token->position = start_pos;
			return (token);
		}
		token = read_operator(lexer);
	}
	else if (is_quote(lexer->curr_char))
		token = read_quotes(lexer);
	else
		token = read_word(lexer);
	if (!token)
	{
		handle_error(MNSHL_ERR_MEMORY,
			"process_next_token : token creation failed");
		token = create_token(TOKEN_ERROR, "Token creation failed");
		token->position = start_pos;
	}
	return (token);
}
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

bool skip_comment(t_lexer *lexer)
{
    if (lexer->curr_char == '#')
    {
        while (lexer->curr_char && lexer->curr_char != '\n')
            advance_lexer(lexer);
        return (true);
    }
    return (false);
}

t_token *process_token_error(t_lexer *lexer, t_token *token)
{
    printf("Syntax error at position %d\n", token->position);
    free_token_list(lexer->tokens);
    free_token_list(token);
    return (NULL);
}

static t_token *generate_tokens(t_lexer *lexer)
{
    t_token *token;
    t_token *eof_token;

    while (lexer->curr_char)
    {
        if (skip_comment(lexer))
            continue;

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

t_token *tokenize_input(char *input, t_data *data)
{
    t_lexer *lexer;
    t_token *tokens;

    lexer = init_lexer(input, data);
    if (!lexer)
    {
        handle_error(MNSHL_ERR_MEMORY, "tokenize_input : lexer creation failed");
        return (NULL);
    }

    tokens = generate_tokens(lexer);

    free_lexer(lexer);
    return (tokens);
}
