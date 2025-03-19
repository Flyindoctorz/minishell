/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotehandler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:12:34 by cgelgon           #+#    #+#             */
/*   Updated: 2024/12/20 18:45:13 by cgelgon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*void	false_status(t_minishell *minishell)
{
	minishell->quote_state.in_double_quotes = false;
	minishell->quote_state.in_single_quotes = false;
	minishell->quote_state.j = 0;
}*/

// handle the quotes
size_t	quote_handler(const char *input, t_minishell *mini,	char *result)
{
	char	c;

	c = input[mini->state.i];
	if (c == '\'' && !mini->state.in_double_quotes)
	{
		mini->state.in_single_quotes = !mini->state.in_single_quotes;
		mini->state.i++;
		return (mini->state.i);
	}
	if (c == '\"' && !mini->state.in_single_quotes)
	{
		mini->state.in_double_quotes = !mini->state.in_double_quotes;
		mini->state.i++;
		return (mini->state.i);
	}
	if (c == '\\' && input[mini->state.i + 1])
	{
		result[mini->state.j++] = input[++mini->state.i];
		return (mini->state.i +1);
	}
	result[mini->state.j++] = c;
	mini->state.i++;
	return (mini->state.i);
}

// true if c is a metacharacter
bool	is_meta(char c, t_minishell *mini)
{
	if ((c == '|' || c == '&' || c == ';' || c == '(' || c == ')') && (
			!mini->state.in_single_quotes) && (!mini->state.in_double_quotes))
		return (true);
	return (false);
}

char	*parse_input(t_minishell *mini)
{
	const char	*input;
	char		*res;

	input = mini->input;
	res = malloc(ft_strlen(input) + 1);
	if (!res)
	{
		perror("malloc in parse_input failed");
		return (NULL);
	}
	mini->state.i = 0;
	mini->state.in_single_quotes = false;
	mini->state.in_double_quotes = false;
	mini->state.j = 0;
	while (input[mini->state.i])
	{
		mini->state.i = quote_handler(input, mini, res);
		printf("%s\n", res);
	}
	res[mini->state.j] = '\0';
	return (res);
}
/*
int main(int argc, char **argv)
{
    t_minishell minishell;
    char *input = NULL;

    // Initialisation de t_minishell
    minishell.input = NULL;
    minishell.state.in_single_quotes = false;
    minishell.state.in_double_quotes = false;

    if (argc > 1)
    {
        // Cas où l'entrée est fournie via argv
        size_t len = 0;
        for (int i = 1; i < argc; i++)
        {
            len += strlen(argv[i]) + 1; // Espace ou null terminator
        }

        input = malloc(len);
        if (!input)
        {
            perror("Allocation failed");
            return 1;
        }

        input[0] = '\0';
        for (int i = 1; i < argc; i++)
        {
            strcat(input, argv[i]);
            if (i != argc - 1)
                strcat(input, " "); // Ajout d'un espace entre les arguments
        }
    }
    else
    {
        // Cas où l'entrée est demandée en mode interactif
        size_t len = 0;
        printf("minishell> ");
        if (getline(&input, &len, stdin) == -1)
        {
            perror("getline failed");
            free(input);
            return 1;
        }

        // Suppression du saut de ligne final
        input[strcspn(input, "\n")] = '\0';
    }

    minishell.input = input;

    // Lancer le parsing
    printf("\n--- Parsing Input ---\n");
    parse_input(&minishell);

    // Afficher un message ou le résultat
    printf("\n--- Parsing Completed ---\n");

    // Libérer la mémoire
    free(input);
    return 0;
}*/



/*bool	logical_operator_case(t_minishell *minishell, size_t *i)
{
	const char	*input = minishell->input;
	size_t		i;
	const char	*input = minishell->input;
	char		*res;
	char		c;

	if (input[*i] == '&' && input[*i + 1] == '&')
	{
		(*i)++;
		return (true);
	}
	else if (input[*i] == '|' && input[*i + 1] == '|')
	{
		(*i)++;
		return (true);
	}
	return (false);
}*/
/*
bash--posix pour les test

DÉFINITIONS

Les définitions suivantes sont utilisées dans toute la suite ce document.

blanc
	Une espace ou une tabulation.
mot
	Une suite de caractères considérée comme une unité élémentaire par l'interpréteur. On parle également de lexème (« token »).
nom
	Un mot ne contenant que des caractères alphanumériques ou tirets bas (« underscore »),
		commençant par une lettre ou un tiret bas. On s'y réfère également sous le terme identificateur.
métacaractère
	Un caractère qui, non protégé, sépare les mots. Un de ceux-ci :

		| & ; ( ) < > espace tab

opérateur de contrôle
	Un lexème ayant une fonction de contrôle. C'est l'un des symboles suivants :

		|| & && ; ;; ( ) | |& <changement de ligne>
*/
