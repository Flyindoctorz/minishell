/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shrinker_three.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:00:34 by cgelgon           #+#    #+#             */
/*   Updated: 2025/04/03 14:28:37 by cgelgon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static t_token	*handle_redir_token(t_token *current, t_token *next,
		t_token **res)
{
	t_token	*new_token;

	new_token = merge_redir(current, next);
	if (!new_token)
	{
		if (*res)
			free_token_list(*res);
		return (NULL);
	}
	return (new_token);
}

static t_token	*handle_regular_token(t_token *current, t_token **res)
{
	t_token	*new_token;

	new_token = create_token_copy(current);
	if (!new_token)
	{
		if (*res)
			free_token_list(*res);
		return (NULL);
	}
	return (new_token);
}

static t_token	*handle_token(t_token **current, t_token **res)
{
	t_token	*next;
	t_token	*new_token;

	next = (*current)->next;
	if (is_redir(*current) && next && next->toktype == TOKEN_WORD)
	{
		new_token = handle_redir_token(*current, next, res);
		if (!new_token)
			return (NULL);
		*current = next->next;
	}
	else
	{
		new_token = handle_regular_token(*current, res);
		if (!new_token)
			return (NULL);
		*current = (*current)->next;
	}
	return (new_token);
}

static bool	init_process_list(t_token **res, t_token **res_tail)
{
	if (!res || !res_tail)
	{
		handle_error(MNSHL_ERR_ARGS, "process_token_list: args invalides");
		return (false);
	}
	*res = NULL;
	*res_tail = NULL;
	return (true);
}

t_token	*process_token_list(t_token *tokens, t_token **res, t_token **res_tail)
{
	t_token *current;
	t_token *new_token;

	if (!tokens || !init_process_list(res, res_tail))
		return (NULL);
	current = tokens;
	while (current)
	{
		new_token = handle_token(&current, res);
		if (!new_token)
		{
			*res = NULL;
			*res_tail = NULL;
			return (NULL);
		}
		add_to_result(res, res_tail, new_token);
	}
	return (*res);
}