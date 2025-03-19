/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   before_init_lexer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:33:40 by cgelgon           #+#    #+#             */
/*   Updated: 2025/03/11 11:12:07 by cgelgon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/lexer_test.h"

t_data	*create_test_data(void)
{
	char	*fake_av[2];
	t_data	*data;

	fake_av[0] = "test_program";
	fake_av[1] = NULL;
	data = init_data(1, fake_av, NULL);
	if (!data)
	{
		print_test("test data creation", 0);
		return (NULL);
	}
	return (data);
}

char	*create_test_input(void)
{
	char	*input;

	input = strdup("echo hello > file");
	if (!input)
	{
		print_test("input allocation", 0);
		return (NULL);
	}
	return (input);
}

bool	test_lexer_creation(t_data *data, char *input)
{
	t_lexer	*lexer;
	bool	success;

	if (!data || !input)
		return (false);
	lexer = init_lexer(input, data);
	if (!lexer)
		return (false);
	success = (lexer->curr_char == input[0]
		&& lexer->pos == 0
		&& lexer->read_pos == 1);
	free_lexer(lexer);
	return (success);
}