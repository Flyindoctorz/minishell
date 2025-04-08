/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 11:45:52 by cgelgon           #+#    #+#             */
/*   Updated: 2025/04/08 14:14:19 by lmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool	is_heredoc_token(t_token *token)
{
	if (!token || token->toktype != TOKEN_HEREDOC)
		return (false);
	return (true);
}

bool	is_valid_heredoc_delimiter(char *delimiter)
{
	if (!delimiter || ((!ft_strlen(delimiter)) == 0))
		return (false);
	if (ft_strchr(delimiter, ' ') || ft_strchr(delimiter, '\t')
		|| ft_strchr(delimiter, '\n') || ft_strchr(delimiter, '<')
		|| ft_strchr(delimiter, '>') || ft_strchr(delimiter, '|'))
		return (false);
	return (true);
}

char	*extract_heredoc_delim(t_token *token)
{
	if (!token || token->toktype != TOKEN_HEREDOC)
		return (NULL);
	if (token->shrinked == TOKEN_WORD && token->value)
		return (ft_strdup(token->value));
	if (!token->next || token->next->toktype != TOKEN_WORD)
		return (NULL);
	return (ft_strdup(token->next->value));
}

bool	process_heredoc_tok(t_cmd_list *cmd, t_token *token, t_data *data)
{
	char	*delimiter;
	bool	res;

	if (!cmd || !token || !data)
	{
		handle_error(MNSHL_ERR_ARGS, "process_heredoc_tok");
		return (false);
	}
	delimiter = extract_heredoc_delim(token);
	if (!delimiter)
	{
		handle_error(MNSHL_ERR_MEMORY, "process_heredoc_tok");
		return (false);
	}
	if (!is_valid_heredoc_delimiter(delimiter))
	{
		handle_error(MNSHL_ERR_SYNTAX, "invalid delimiter");
		free(delimiter);
		return (false);
	}
	res = handle_heredoc(cmd, delimiter, data);
	free(delimiter);
	return (res);
}

bool	process_all_heredocs(t_cmd_list *cmd, t_token *token, t_data *data)
{
	t_token		*curr;
	t_cmd_list	*current_cmd;

	if (!cmd || !token || !data)
		return (false);
	curr = token;
	current_cmd = cmd;
	while (curr)
	{
		if (curr->toktype == TOKEN_PIPE && curr->next)
		{
			if (!current_cmd->next)
				return (false);
			current_cmd = current_cmd->next;
		}
		else if (is_heredoc_token(curr))
		{
			if (!process_heredoc_tok(current_cmd, curr, data))
				return (false);
		}
		curr = curr->next;
	}
	return (true);
}
