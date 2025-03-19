/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:01:26 by cgelgon           #+#    #+#             */
/*   Updated: 2025/03/11 11:13:00 by cgelgon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/lexer_test.h"

static bool    test_quote_content(char *input, char *expected)
{
    t_data  *data;
    t_lexer *lexer;
    t_token *token;
    bool    success;

    data = create_test_data();
    if (!data)
        return (false);
    lexer = init_lexer(input, data);
    if (!lexer)
    {
        free_data(data);
        return (false);
    }
    token = read_quotes(lexer);
    if (!token && !expected)
        success = true;
    else if (!token || !expected)
        success = false;
    else
        success = (ft_strcmp(token->value, expected) == 0);

    if (token)
    {
        free(token->value);
        free(token);
    }
    free_lexer(lexer);
    free_data(data);
    return (success);
}

bool    test_quotes_basic(void)
{
    bool    success;

    printf("\nBasic quotes tests:\n");
    success = true;
    success &= print_test("simple single quote", 
            test_quote_content("'hello'", "hello"));
    success &= print_test("simple double quote", 
            test_quote_content("\"world\"", "world"));
    success &= print_test("empty quotes", 
            test_quote_content("''", ""));
    return (success);
}

bool    test_quotes_advanced(void)
{
    bool    success;

    printf("\nAdvanced quotes tests:\n");
    success = true;
    success &= print_test("mixed quotes", 
            test_quote_content("'test\"123\"'", "test\"123\""));
    success &= print_test("quotes with spaces", 
            test_quote_content("'hello world'", "hello world"));
    success &= print_test("quotes with special chars", 
            test_quote_content("'$HOME'", "$HOME"));
    success &= print_test("quotes with operators", 
            test_quote_content("'echo > file'", "echo > file"));
    return (success);
}

bool    test_quotes_edge_cases(void)
{
    t_data  *data;
    t_lexer *lexer;
    bool    success;

    printf("\nQuotes edge cases:\n");
    success = true;
    data = create_test_data();
    if (!data)
        return (false);
    lexer = init_lexer("'unclosed", data);
    success &= print_test("unclosed single quote", read_quotes(lexer) == NULL);
    free_lexer(lexer);
    lexer = init_lexer("\"unclosed", data);
    success &= print_test("unclosed double quote", read_quotes(lexer) == NULL);
    free_lexer(lexer);
    lexer = init_lexer("'don\\'t'", data);
    success &= print_test("escaped single quote", read_quotes(lexer) != NULL);
    free_lexer(lexer);

    lexer = init_lexer("\"he said \\\"hello\\\"\"", data);
    success &= print_test("escaped double quote", read_quotes(lexer) != NULL);
    free_lexer(lexer);
    free_data(data);
    return (success);
}

bool    test_quotes_type(void)
{
    bool    success;
    
    printf("\nQuotes type tests:\n");
    success = true;
    success &= print_test("single quote type", 
            get_quote_type('\'') == TOKEN_QUOTES);
    success &= print_test("double quote type", 
            get_quote_type('\"') == TOKEN_DQUOTES);
    success &= print_test("invalid quote type", 
            get_quote_type('a') == TOKEN_ERROR);
    return (success);
}

bool    run_quotes_tests(void)
{
    bool    success;

    printf("\n=== QUOTES TEST SUITE START ===\n");
	success = test_quote_content("'hello'", "hello");
    success = test_quotes_basic();
    success &= test_quotes_advanced();
    success &= test_quotes_edge_cases();
    success &= test_quotes_type();
    printf("=== QUOTES TEST SUITE END ===\n");
    return (success);
}