/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_prompter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:55:08 by cgelgon           #+#    #+#             */
/*   Updated: 2025/04/03 18:28:08 by lmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*add_prompt_suffix(char *prefix)
{
	char	*prompt;

	if (!prefix)
		return (ft_strdup("minishell> "));
	prompt = ft_strjoin(prefix, "$ ");
	free(prefix);
	if (!prompt)
		return (ft_strdup("minishell> "));
	return (prompt);
}

char	*get_prompt(t_data *data)
{
	char	*prefix;

	if (!data)
		return (ft_strdup("minishell> "));
	prefix = create_prompt_prefix(data);
	return (add_prompt_suffix(prefix));
}

char	*read_input(t_data *data)
{
	char	*input;
	char	*prompt;

	ft_signal();
	prompt = get_prompt(data);
	input = readline(prompt);
	free(prompt);
	if (!input)
	{
		write(STDOUT_FILENO, "exit\n", 5);
		return (NULL);
	}
	if (input && *input)
		add_history(input);
	return (input);
}

void	clear_readline_history(void)
{
	rl_clear_history();
}
