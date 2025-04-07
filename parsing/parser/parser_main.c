/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 12:29:27 by cgelgon           #+#    #+#             */
/*   Updated: 2025/04/07 16:32:41 by lmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool	validate_syntax(t_token *tokens)
{
	t_token	*curr;
	bool	had_word;

	if (!tokens)
		return (false);
	curr = tokens;
	had_word = false;
	while (curr && curr->toktype != TOKEN_EOF)
	{
		if (curr->toktype == TOKEN_PIPE && !had_word)
			return (handle_error(MNSHL_ERR_SYNTAX, ERR_MSG_PIPE_SYNTAX), false);
		if (is_redir_token(curr->toktype))
		{
			if (!curr->next || curr->next->toktype == TOKEN_WORD)
				return (handle_error(MNSHL_ERR_SYNTAX, ERR_MSG_REDIR_SYNTAX),
					false);
		}
		if (curr->toktype == TOKEN_WORD)
			had_word = true;
		else if (curr->toktype == TOKEN_PIPE)
			had_word = false;
		curr = curr->next;
	}
	return (true);
}

t_cmd_list	*parse_token(t_token *tokens, t_data *data)
{
	t_cmd_list	*cmd_list;
	t_cmd_list	*curr_cmd;
	t_token		*curr_token;

	if (!tokens || !validate_syntax(tokens))
		return (NULL);
	cmd_list = init_cmd_list();
	curr_token = tokens;
	curr_cmd = cmd_list;
	while (curr_token && curr_token->toktype != TOKEN_EOF)
	{
		if (curr_token->toktype == TOKEN_WORD)
			add_word_to_cmd(curr_cmd, curr_token->value);
		else if (curr_token->toktype == TOKEN_PIPE)
			curr_cmd = handle_pipe(curr_cmd);
		else if (is_redir_token(curr_token->toktype))
			handle_redir(curr_cmd, curr_token, data);
		curr_token = curr_token->next;
	}
	return (cmd_list);
}
