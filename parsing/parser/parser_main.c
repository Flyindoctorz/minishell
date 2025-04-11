/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 12:29:27 by cgelgon           #+#    #+#             */
/*   Updated: 2025/04/11 18:47:48 by lmokhtar         ###   ########.fr       */
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

// Helper to check if a string was originally in single quotes
bool was_in_single_quotes(const char *arg, t_token *tokens)
{
	t_token *current = tokens;
	
	while (current)
	{
		if (current->toktype == TOKEN_QUOTES && current->value && 
			ft_strcmp(current->value, arg) == 0)
			return true;
		current = current->next;
	}
	return false;
}

bool expand_command_args(t_cmd_list *cmd, t_data *data)
{
    int i;
    char *expanded;
    t_token *token = data->token; // Get the original token list

    if (!cmd || !cmd->av)
        return (true);
    
    i = 0;
    while (cmd->av[i])
    {
        // Only expand if it contains $ AND wasn't originally in single quotes
        if (ft_strchr(cmd->av[i], '$') && !was_in_single_quotes(cmd->av[i], token))
        {
            expanded = expand(cmd->av[i], data);
            if (expanded)
            {
                free(cmd->av[i]);
                cmd->av[i] = expanded;
            }
        }
        i++;
    }
    return (true);
}

t_cmd_list	*finalize_parsing(t_cmd_list *cmd_list, t_token *tokens,
		t_data *data)
{
	t_cmd_list	*cmd;

	(void)tokens;
	if (!cmd_list || !cmd_list->av)
	{
		ft_commandclear(&cmd_list);
		return (NULL);
	}
	cmd = cmd_list;
	while (cmd)
	{
		expand_command_args(cmd, data);
		if (!setup_redir(cmd))
		{
			ft_putstr_fd("minishell: ", 2);
			if (cmd->input_file)
				perror(cmd->input_file);
			else if (cmd->output_file)
				perror(cmd->output_file);
			else
				perror("redirection");
			ft_commandclear(&cmd_list);
			return (NULL);
		}
		cmd = cmd->next;
	}
	return (cmd_list);
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
		if (curr_token->toktype == TOKEN_WORD
			|| curr_token->toktype == TOKEN_QUOTES
			|| curr_token->toktype == TOKEN_DQUOTES)
			add_word_to_cmd(curr_cmd, curr_token->value);
		else if (curr_token->toktype == TOKEN_PIPE)
			curr_cmd = handle_pipe(curr_cmd);
		else if (is_redir_token(curr_token->toktype))
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
		else if (curr_token->toktype == TOKEN_EOF)
			break ;
		else
			return (NULL);
		curr_token = curr_token->next;
	}
	return (finalize_parsing(cmd_list, tokens, data));
}
