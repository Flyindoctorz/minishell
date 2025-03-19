/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 00:07:32 by zakchouc          #+#    #+#             */
/*   Updated: 2024/12/20 18:50:10 by cgelgon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_print_history(t_minishell *mini)
{
	int	i;

	using_history();
	mini->history = history_list();
	mini->history_state = history_get_history_state();
	printf("print_hist\n");
	printf("History state lenght : %d\n", mini->history_state->length);
	i = 0;
	while (mini->history[i])
	{
		printf("\n\nhistory->line : %s", mini->history[i]->line);
		printf("\nhistory->timestamp : %s", mini->history[i]->timestamp);
		++i;
	}
}

void	ft_initialize_minishell(t_minishell *mini, char *envp[])
{
	// Initialisation de l'état des quotes
	mini->state.in_single_quotes = false;
	mini->state.in_double_quotes = false;
	mini->state.i = 0;
	mini->state.j = 0;

	ft_arrcpy(mini, envp);
}

void	ft_prompt(t_minishell *mini, char *envp[])
{
	char *parsed_input;
	while (1)
	{
		mini->input = readline("minishell> ");
		if (mini->input == NULL)
			break ;
		else
		{
			add_history(mini->input);
			parsed_input = parse_input(mini);
			if (parsed_input)
			{
				printf("parsing_input ; %s\n", parsed_input);
				free(parsed_input);
			}
			ft_tokenize(mini);
			ft_parse(mini, envp);
			free(mini->input);
			// free(mini->command); // double free here
		}
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	t_minishell	*mini;

	(void)argc;
	(void)argv;
	mini = malloc(sizeof(t_minishell));
	if (!mini)
		return (EXIT_FAILURE);
	ft_initialize_minishell(mini, envp);
	ft_prompt(mini, envp);
	ft_free_everything(mini);
	return (0);
}
