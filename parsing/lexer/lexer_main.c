/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 12:28:21 by cgelgon           #+#    #+#             */
/*   Updated: 2025/03/11 14:47:57 by cgelgon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lexer.h"

t_token	*apply_shrink(t_token *tokens)
{
	t_token *shrinked;
	
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
	

//evite les white space et utilise le read adequat
// renvoie le token current
t_token *tokenize_current(t_lexer *lexer)
{
	t_token *token;
	int start_pos;

	if (is_whitespace(lexer->curr_char))
	{
		advance_lexer(lexer);
		return (NULL);
	}
	start_pos = lexer->pos;
	if (is_expand_char(lexer->curr_char))
		token = read_expand(lexer);
	else if (is_operator(lexer->curr_char))
		token = read_operator(lexer);
	else if (is_quote(lexer->curr_char))
		token = read_quotes(lexer);
	else
		token = read_word(lexer);
	if (!token)
	{
		handle_error(MNSHL_ERR_MEMORY, "process_next_token : token creation failed");
		return (NULL);
	}
	return (token);
}

static t_lexer *validate_input(char *input, t_data *data)
{
    if (!input || !data)
    {
        handle_error(MNSHL_ERR_ARGS, "Tokenize input : null input or data");
        return NULL;
    }

    t_lexer *lexer = init_lexer(input, data);
    if (!lexer)
    {
        handle_error(MNSHL_ERR_MEMORY, "tokenize_input : lexer creation failed");
        return NULL;
    }

    return lexer;
}

static void process_token_generation(t_lexer *lexer)
{
    while (lexer->curr_char)
    {
        if (lexer->curr_char == '#') 
        {
            while (lexer->curr_char && lexer->curr_char != '\n') 
            {
                advance_lexer(lexer);
            }
            continue;
        }
        t_token *token = tokenize_current(lexer);
        
        if (token)
        {
            add_token(lexer, token);
        }
    }
}

t_token *tokenize_input(char *input, t_data *data)
{
	t_lexer *lexer;
	t_token *eof_token;

	lexer = validate_input(input, data);
    if (!lexer)
        return NULL;
    process_token_generation(lexer);
    eof_token = create_token(TOKEN_EOF, NULL);
    add_token(lexer, eof_token);
    t_token *tokens = lexer->tokens;
    free_lexer(lexer);
    return (tokens);
}


