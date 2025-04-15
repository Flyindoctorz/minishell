/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 12:29:27 by cgelgon           #+#    #+#             */
/*   Updated: 2025/04/15 16:33:13 by lmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool	validate_syntax_part2(t_token *curr, bool *had_word)
{
	if (curr->toktype == TOKEN_PIPE)
	{
		if (!*had_word)
			return (handle_error(MNSHL_ERR_SYNTAX, ERR_MSG_PIPE_SYNTAX), false);
		if (!curr->next || curr->next->toktype == TOKEN_EOF
			|| curr->next->toktype == TOKEN_PIPE)
			return (handle_error(MNSHL_ERR_SYNTAX, ERR_MSG_PIPE_SYNTAX), false);
		*had_word = false;
	}
	else if (is_redir_token(curr->toktype))
	{
		if (!curr->next || curr->next->toktype != TOKEN_WORD)
			return (handle_error(MNSHL_ERR_SYNTAX, ERR_MSG_REDIR_SYNTAX),
				false);
	}
	return (true);
}

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
		if (!validate_syntax_part2(curr, &had_word))
			return (false);
		if (curr->toktype == TOKEN_WORD)
			had_word = true;
		curr = curr->next;
	}
	return (true);
}

static void	process_token_word(t_cmd_list *curr_cmd, t_token *curr_token)
{
	if (curr_token->toktype == TOKEN_WORD || curr_token->toktype == TOKEN_QUOTES
		|| curr_token->toktype == TOKEN_DQUOTES
		|| curr_token->toktype == TOKEN_DOLLAR)
		add_word_to_cmd(curr_cmd, curr_token->value);
}

static t_token	*process_redir_heredoc(t_cmd_list *curr_cmd,
		t_token *curr_token, t_data *data)
{
	if (is_redir_token(curr_token->toktype))
	{
		handle_redir(curr_cmd, curr_token, data);
		curr_token = curr_token->next;
	}
	else if (curr_token->toktype == TOKEN_HEREDOC)
	{
		if (!curr_cmd->cmd)
		{
			curr_cmd->heredoc = true;
			curr_cmd->delimiter = curr_token->next->value;
		}
		else
			handle_heredoc(curr_cmd, curr_token->next->value, data);
		curr_token = curr_token->next;
	}
	return (curr_token);
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
		process_token_word(curr_cmd, curr_token);
		if (curr_token->toktype == TOKEN_PIPE)
			curr_cmd = handle_pipe(curr_cmd);
		else if (is_redir_token(curr_token->toktype)
			|| curr_token->toktype == TOKEN_HEREDOC)
			curr_token = process_redir_heredoc(curr_cmd, curr_token, data);
		if (curr_token->toktype == TOKEN_EOF)
			break ;
		curr_token = curr_token->next;
	}
	return (finalize_parsing(cmd_list, tokens, data));
}
