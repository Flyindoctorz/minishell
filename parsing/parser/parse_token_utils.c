/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_token_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:15:56 by cgelgon           #+#    #+#             */
/*   Updated: 2025/04/15 18:24:41 by cgelgon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_token	*process_redir(t_cmd_list *curr_cmd, t_token *curr_token, t_data *data)
{
	if (is_redir_token(curr_token->toktype))
	{
		handle_redir(curr_cmd, curr_token, data);
		curr_token = curr_token->next;
	}
	return (curr_token);
}

void	process_token_word(t_cmd_list *curr_cmd, t_token *curr_token)
{
	if (curr_token->toktype == TOKEN_WORD || curr_token->toktype == TOKEN_QUOTES
		|| curr_token->toktype == TOKEN_DQUOTES
		|| curr_token->toktype == TOKEN_DOLLAR)
	{
		add_word_to_cmd(curr_cmd, curr_token->value);
	}
}

static bool	is_valid_next_token(t_token *token)
{
	return (token && (token->toktype == TOKEN_WORD
			|| token->toktype == TOKEN_QUOTES
			|| token->toktype == TOKEN_DQUOTES));
}

t_token	*process_heredoc_token(t_cmd_list *curr_cmd, t_token *curr_token,
		t_data *data)
{
	if (curr_token->toktype != TOKEN_HEREDOC)
		return (curr_token);
	if (is_valid_next_token(curr_token->next))
	{
		if (!curr_cmd->cmd)
		{
			curr_cmd->heredoc = true;
			curr_cmd->delimiter = curr_token->next->value;
		}
		else
			handle_heredoc(curr_cmd, curr_token->next->value, data);
	}
	if (curr_token->next)
		curr_token = curr_token->next;
	return (curr_token);
}
