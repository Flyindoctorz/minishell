/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:33:40 by cgelgon           #+#    #+#             */
/*   Updated: 2025/03/11 11:12:56 by cgelgon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/lexer_test.h"

bool	test_create_token_basic(void)
{
	t_token	*token;
	bool	success;

	token = create_token(TOKEN_WORD, "test");
	if (!token)
		return (false);
	success = (token->toktype == TOKEN_WORD
		&& ft_strcmp(token->value, "test") == 0);
	print_test("create token basic", success);
	if (token->value)
		free(token->value);
	free(token);
	return (success);
}

bool	test_create_token_advanced(void)
{
	t_token	*token;
	bool	success;

	token = create_token(TOKEN_PIPE, NULL);
	if (!token)
		return (false);
	success = (token->toktype == TOKEN_PIPE && token->value == NULL);
	print_test("create token without value", success);
	free(token);
	return (success);
}