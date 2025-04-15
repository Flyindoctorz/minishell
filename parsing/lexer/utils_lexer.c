/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lexer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:50:35 by cgelgon           #+#    #+#             */
/*   Updated: 2025/04/15 16:47:43 by lmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// skip les tab et espaces pour parcourir l'input

#include "../../include/minishell.h"

// defini white space
bool	is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r');
}
// defini delimiter

bool	is_delimiter(char c)
{
	return (is_whitespace(c) || c == '\'' || c == '|' || c == '<' || c == '>'
		|| c == '\"' || c == '$' || c == '\0');
}

bool	is_operator(char c)
{
	return (c == '|' || c == '<' || c == '>');
}

t_lexer	*validate_input(char *input, t_data *data)
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
}

// skip tout les white space
void	skip_whitespace(t_lexer *lexer)
{
	if (!lexer)
	{
		handle_error(MNSHL_ERR_ARGS, "Skip_whitespace args invalids");
		return ;
	}
	while (lexer->curr_char && is_whitespace(lexer->curr_char))
		advance_lexer(lexer);
}
