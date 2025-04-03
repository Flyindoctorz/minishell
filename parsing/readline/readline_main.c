/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:04:32 by cgelgon           #+#    #+#             */
/*   Updated: 2025/04/03 16:43:21 by lmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// static void	process_input(t_data *data, char *input)
// {
// 	t_token	*tokens;

// 	if (!input || !*input)
// 		return ;
// 	tokens = tokenize_input(input, data);
// 	if (!tokens)
// 		return ;
// 	free_token_list(tokens);
// }
// void	run_shell(t_data *data)
// {
// 	char	*input;

// 	if (!data)
// 		return ;
// 	while (1)
// 	{
// 		input = read_input(data);
// 		if (!input)
// 			break ;
// 		if (get_signal_status() == SIGINT)
// 		{
// 			free(input);
// 			data->exit = 130;
// 			continue ;
// 		}
// 		process_input(data, input);
// 		free(input);
// 	}
// 	clear_readline_history();
// }

int	readline_main(int ac, char **av, char **env)
{
	t_data *data;
	int exit_status;

	data = init_data(ac, av, env);
	if (!data)
		return (MNSHL_ERR_MEMORY);
	run_shell(data);
	exit_status = data->exit;
	free_data(data);
	return (exit_status);
}