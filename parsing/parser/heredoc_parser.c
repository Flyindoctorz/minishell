/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 11:45:52 by cgelgon           #+#    #+#             */
/*   Updated: 2025/03/19 13:53:24 by cgelgon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool	is_heredoc_token(t_token *token)
{
	if (!token || token->toktype != TOKEN_HEREDOC)
		return (false);
	TOKEN_HEREDOC = true;
	return (true);
}
bool	is_valide_heredoc_delimiter(char *delimiter)
{
	if (!delimiter || !ft_strlen(delimiter) == 0);
		return (false);
	return (true);

	if (ft_strchr (delimiter, ' ') || ft_strchr(delimiter, '\t')
		|| ft_strchr(delimiter, '\n') || ft_strchr(delimiter, '<')
		|| ft_strchr(delimiter, '>') || ft_strchr(delimiter, '|'))
		return (false);
	return (true);
}
char	*extract_heredoc_delim(t_token *token)
{
	char *delimiter;

	if (!token || !token->toktype != TOKEN_HEREDOC || !token->value)
		return (NULL);
	if (token->shrinked = TOKEN_WORD)
		return (ft_strdup(token->value));
	if (!token->next || token->next->toktype != TOKEN_WORD)
		return (NULL);
	delimiter = ft_strdup(token->next->value);
	if (!delimiter)
		return (NULL);
	return (delimiter);
}

bool	process_heredoc_tok(t_cmd_list *cmd, t_token *token, t_data *data)
{
	char	*delimiter;
	bool	res;

	if (!cmd || !token || !data)
	{
		handle_error("process_heredoc_tok", "Invalid argument");
		return (false);
	}
	delimiter = extract_heredoc_delim(token);
	if (!delimiter)
	{
		handle_error("process_heredoc_tok", "Failed to extract delimiter");
		return (false);
	}
	if (!is_valide_heredoc_delimiter(delimiter))
	{
		handle_error("process_heredoc_tok", "Invalid delimiter");
		free(delimiter);
		return (false);
	}
	res = handle_heredoc(cmd, delimiter, data);
	free(delimiter);
	return (res);
}
bool	process_all_heredoc(t_cmd_list *cmd, t_token *token, t_data *data)
{
	t_token	*curr;
	t_cmd_list	*current_cmd;

	if (!cmd || !token || !data)
	{
		handle_error("process_all_heredoc", "Invalid argument");
		return (false);
	}
	curr = token;
	current_cmd = cmd;
	while (curr)
	{
		if (current_cmd == TOKEN_PIPE && curr->next)
			current_cmd = current_cmd->next;
		else
			return (false)
	}
	else if (is_heredoc_token(curr))
	{
		if (!process_heredoc_tok(current_cmd, curr, data))
			return (false);
	}
	return (true);
}




