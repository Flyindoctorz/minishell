/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_word_test_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:27:42 by cgelgon           #+#    #+#             */
/*   Updated: 2025/03/11 11:13:04 by cgelgon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/lexer_test.h"

bool	init_word_test(t_data **data, t_lexer **lexer, char *input)
{
	*data = create_test_data();
	if (!*data)
		return (false);
	*lexer = init_lexer(input, *data);
	if (!*lexer)
	{
		free_data(*data);
		return (false);
	}
	return (true);
}

bool	compare_token(t_token *token, char *expected)
{
	if (!token && !expected)
		return (true);
	if (!token || !expected)
		return (false);
	return (token->toktype == TOKEN_WORD
		&& ft_strcmp(token->value, expected) == 0);
}

bool	test_single_word(char *input, char *expected)
{
	t_data	*data;
	t_lexer	*lexer;
	t_token	*token;
	bool	success;
	
	if (!input)
		return (!expected);
	data = create_test_data();
	if (!data)
		return (false);
	lexer = init_lexer(input, data);
	if (!lexer)
	{
		free_data(data);
		return (!expected);
	}
	skip_whitespace(lexer);
	token = read_word(lexer);
	success = compare_token(token, expected);
	if (token)
		free(token);
	free_lexer(lexer);
	free_data(data);
	return (success);
}
