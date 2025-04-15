/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:38:04 by cgelgon           #+#    #+#             */
/*   Updated: 2025/04/15 18:59:50 by cgelgon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

static bool	handle_signals_or_empty(t_data *data, char *input)
{
	if (!input)
		return (false);
	if (g_signal != 0)
	{
		data->state = g_signal;
		g_signal = 0;
		return (true);
	}
	if (!*input)
		return (true);
	add_history(input);
	return (true);
}

static bool	process_tokens(t_data *data, char *input)
{
	data->token = tokenize_input(input, data);
	if (!data->token)
		return (false);
	data->command = parse_token(data->token, data);
	if (!data->command)
	{
		ft_tokenclear(&data->token);
		return (false);
	}
	return (true);
}

static void	cleanup_resources(t_data *data)
{
	if (data->token)
		ft_tokenclear(&data->token);
	if (data->command)
		ft_commandclear(&data->command);
	data->token = NULL;
	data->command = NULL;
}

int	process_input(t_data *data, char *input)
{
	if (!handle_signals_or_empty(data, input))
		return (0);
	if (!input)
		return (1);
	if (data->state == 130)
		data->state = 0;
	if (!process_tokens(data, input))
		return (1);
	exec(data->command, data);
	cleanup_resources(data);
	return (1);
}
