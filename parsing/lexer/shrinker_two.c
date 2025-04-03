/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shrinker_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:05:31 by cgelgon           #+#    #+#             */
/*   Updated: 2025/04/03 14:28:40 by cgelgon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// res = liste de token / tail = dernier token / new_token = token a ajouter
void add_to_result(t_token **res, t_token **tail, t_token *new_token)
{
	if (!new_token || !res || !tail)
		return;
	new_token->next = NULL;
	if (!*res)
	{
		*res = new_token;
		*tail = new_token;
	}
	else if (*tail)
	{
		(*tail)->next = new_token;
		*tail = new_token;
	}
}

// duplique un token source et renvoie le nouveau
t_token *create_token_copy(t_token *source)
{
	t_token *copy;

	if (!source)
		return (NULL);

	copy = create_token(source->toktype, source->value);
	if (!copy)
	{
		handle_error(MNSHL_ERR_MEMORY, "create_token_copy : token creation failed");
		return (NULL);
	}
	copy->position = source->position;
	copy->shrinked = source->shrinked;
	return (copy);
}

void free_token_list(t_token *tokens)
{
	t_token *current;
	t_token *next;

	current = tokens;
	while (current)
	{
		next = current->next;
		if (current->value)
			free(current->value);
		free(current);
		current = next;
	}
}