/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:31:51 by cgelgon           #+#    #+#             */
/*   Updated: 2025/04/03 14:27:50 by cgelgon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// simple init des variables de la structure
t_lexer	*init_lexer(char *input, t_data *data)
{
	t_lexer	*lexer;

	if (!input || !data)
	{
		handle_error(MNSHL_ERR_ARGS, "Lexer init : null input or data");
		return (NULL);
	}
	lexer = malloc(sizeof(t_lexer));
	if (!lexer)
	{
		handle_error(MNSHL_ERR_MEMORY, "lexer malloc failed");
		return (NULL);
	}
	lexer->input = input;
	lexer->input_len = ft_strlen(input);
	lexer->pos = 0;
	lexer->read_pos = 0;
	lexer->curr_char = input[0];
	lexer->curr_tok = NULL;
	lexer->tokens = NULL;
	lexer->token_count = 0;
	if (lexer->input_len > 0)
		lexer->read_pos = 1;
	return (lexer);
}

// usage : avance dans le lexer
void	advance_lexer(t_lexer *lexer)
{
	if (!lexer)
	{
		handle_error(MNSHL_ERR_ARGS, "advance_lexer : null lexer");
		return ;
	}
	if ((size_t)lexer->read_pos < lexer->input_len)
	{
		lexer->curr_char = lexer->input[lexer->read_pos];
		lexer->pos = lexer->read_pos;
		lexer->read_pos++;
	}
	else
		lexer->curr_char = '\0';
}

// usage : regarde a pos +1. Utilise pour les double >> << ||
char	look_forward(t_lexer *lexer)
{
	if (!lexer || (size_t)lexer->read_pos >= lexer->input_len)
	{
		handle_error(MNSHL_ERR_ARGS,
			"look_forward args invalid or pos unavailable");
		return ('\0');
	}
	return (lexer->input[lexer->read_pos]);
}

// Add new token to the token list in lexer
// attribute curr->tok to new_token
// increment token_count
// if token list exist already, add new_token to the end
// if token list doest exist yet, create it and add new_token
// A->B->C->D->NULL
bool	add_token(t_lexer *lexer, t_token *new_token)
{
	if (!lexer || !new_token)
	{
		handle_error(MNSHL_ERR_ARGS, "add token : lexer or new_token invalid");
		return (false);
	}
	new_token->next = NULL;
	if (!lexer->tokens)
	{
		lexer->tokens = new_token;
		lexer->curr_tok = new_token;
		lexer->token_count++;
	}
	else if (lexer->curr_tok)
	{
		lexer->curr_tok->next = new_token;
		lexer->curr_tok = new_token;
		lexer->token_count++;
	}
	else
	{
		handle_error(MNSHL_ERR_ARGS,
			"add token : add token : invalid list state");
		return (false);
	}
	return (true);
}

// free lexer mais pas input car vient de readline

void	free_lexer(t_lexer *lexer)
{
	if (!lexer)
		return ;
	free(lexer);
}
