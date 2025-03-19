/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lexer_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:33:40 by cgelgon           #+#    #+#             */
/*   Updated: 2025/03/11 11:12:19 by cgelgon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/lexer_test.h"

bool	test_init_lexer(void)
{
	t_data	*data;
	char	*input;
	bool	success;

	data = create_test_data();
	if (!data)
		return (false);
	input = create_test_input();
	if (!input)
	{
		free_data(data);
		return (false);
	}
	success = test_lexer_creation(data, input);
	print_test("init lexer basic", success);
	free_data(data);
	free(input);
	return (success);
}

bool	test_look_forward_basic(void)
{
	t_lexer	*lexer;
	t_data	*data;
	bool	success;

	data = create_test_data();
	if (!data)
		return (false);
	lexer = init_lexer("abc", data);
	if (!lexer)
	{
		free_data(data);
		return (false);
	}
	success = (look_forward(lexer) == 'b');
	print_test("look_forward basic", success);
	free_lexer(lexer);
	free_data(data);
	return (success);
}

bool	test_look_forward_advanced(void)
{
	t_lexer	*lexer;
	t_data	*data;
	bool	success;

	data = create_test_data();
	if (!data)
		return (false);
	lexer = init_lexer("abc", data);
	if (!lexer)
	{
		free_data(data);
		return (false);
	}
	advance_lexer(lexer);
	success = (look_forward(lexer) == 'c');
	print_test("look_forward after advance", success);
	free_lexer(lexer);
	free_data(data);
	return (success);
}

bool	test_null_input(void)
{
	t_lexer	*lexer;
	t_data	*data;
	bool	success;

	success = true;
	data = create_test_data();
	lexer = init_lexer(NULL, data);
	if (lexer != NULL)
		success = false;
	lexer = init_lexer("", data);
	if (lexer == NULL)
		success = false;
	else
		free_lexer(lexer);
	free_data(data);
	print_test("error above is logical", success);
    print_test("null input handling", success);
	return (success);
}

bool	test_empty_input(void)
{
	t_lexer	*lexer;
	t_data	*data;
	bool	success;

	data = create_test_data();
	if (!data)
		return (false);
	lexer = init_lexer("", data);
	if (!lexer)
	{
		free_data(data);
		return (false);
	}
	success = (lexer->curr_char == '\0' && lexer->pos == 0);
	print_test("empty input handling", success);
	free_lexer(lexer);
	free_data(data);
	return (success);
}