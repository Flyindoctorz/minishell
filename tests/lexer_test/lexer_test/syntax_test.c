/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:23:56 by cgelgon           #+#    #+#             */
/*   Updated: 2025/03/11 11:13:13 by cgelgon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/lexer_test.h"

bool    test_operator_syntax_errors(void)
{
    t_data  *data;
    t_lexer *lexer;
    bool    success;
    success = true;
    data = create_test_data();
    if (!data)
        return (false);
    lexer = init_lexer("| ls", data);
    success &= print_test("Pipe at start", read_operator(lexer) == NULL);
    free_lexer(lexer);
    lexer = init_lexer(">", data);
	success &= print_test("Redir without target", read_operator(lexer) == NULL);
    free_lexer(lexer);
    lexer = init_lexer("><", data);
    success &= print_test("Consecutive operators", read_operator(lexer) == NULL);
    free_lexer(lexer);
    free_data(data);
    return (success);
}

bool	test_pipe_syntax_errors(void)
{
	t_data	*data;
	t_lexer	*lexer;
	bool	success;

	success = true;
	data = create_test_data();
	if (!data)
		return (false);
	lexer = init_lexer("| ls", data);
	success &= print_test("Pipe at start", read_operator(lexer) == NULL);
	free_lexer(lexer);
	lexer = init_lexer("ls | | grep", data);
	success &= print_test("Double pipe", read_operator(lexer) == NULL);
	free_lexer(lexer);
	success = init_lexer("ls ||", data); // verifier veracite et comportement du || dans le sujet
	success &= print_test("Pipe at end", read_operator(lexer) == NULL);
	free_lexer(lexer);
	free_data(data);
	return (success);
}

bool	test_redir_syntax_errors(void)
{
	t_data	*data;
	t_lexer	*lexer;
	bool	success;

	success = true;
	data = create_test_data();
	if (!data)
		return (false);
	lexer = init_lexer(">", data);
	success &= print_test("Redir without target", read_operator(lexer) == NULL);
	free_lexer(lexer);
	lexer = init_lexer("ls > >", data);
	success &= print_test("Double redir", read_operator(lexer) == NULL);
	free_lexer(lexer);
	lexer = init_lexer("ls ><", data);
	success &= print_test("Mixed redir", read_operator(lexer) == NULL);
	free_lexer(lexer);
	lexer = init_lexer("cat < >", data);
	success &= print_test("Invalid redir sequence", read_operator(lexer) == NULL);
	free_lexer(lexer);
	free_data(data);
	return (success);
}
