/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:00:38 by lmokhtar          #+#    #+#             */
/*   Updated: 2025/04/15 17:04:02 by lmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	save_lexer_state(t_lexer *lexer, int saved_state[3])
{
	saved_state[0] = lexer->pos;
	saved_state[1] = lexer->read_pos;
	saved_state[2] = lexer->curr_char;
}

void	restore_lexer_state(t_lexer *lexer, int saved_state[3])
{
	lexer->pos = saved_state[0];
	lexer->read_pos = saved_state[1];
	lexer->curr_char = saved_state[2];
}

bool	find_closing_quote(t_lexer *lexer, char quote)
{
	advance_lexer(lexer);
	while (lexer->curr_char != '\0')
	{
		if (lexer->curr_char == quote)
			return (true);
		advance_lexer(lexer);
	}
	return (false);
}
