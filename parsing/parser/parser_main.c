/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 13:59:42 by cgelgon           #+#    #+#             */
/*   Updated: 2025/04/15 14:00:11 by cgelgon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void process_word_token(t_cmd_list *curr_cmd, t_token *curr_token)
{
    if (curr_token->toktype == TOKEN_WORD
        || curr_token->toktype == TOKEN_QUOTES
        || curr_token->toktype == TOKEN_DQUOTES
        || curr_token->toktype == TOKEN_DOLLAR)
        add_word_to_cmd(curr_cmd, curr_token->value);
}

void process_redir_token(t_cmd_list *curr_cmd, t_token **curr_token, 
    t_data *data)
{
    if ((*curr_token)->toktype == TOKEN_HEREDOC)
    {
        if (!curr_cmd->cmd)
        {
            curr_cmd->heredoc = true;
            curr_cmd->delimiter = (*curr_token)->next->value;
        }
        else
            handle_heredoc(curr_cmd, (*curr_token)->next->value, data);
        *curr_token = (*curr_token)->next;
    }
    else if (is_redir_token((*curr_token)->toktype))
    {
        handle_redir(curr_cmd, *curr_token, data);
        *curr_token = (*curr_token)->next;
    }
}

t_cmd_list *parse_token(t_token *tokens, t_data *data)
{
    t_cmd_list *cmd_list;
    t_cmd_list *curr_cmd;
    t_token *curr_token;

    if (!tokens || !validate_syntax(tokens))
        return (NULL);
    cmd_list = init_cmd_list();
    curr_token = tokens;
    curr_cmd = cmd_list;
    while (curr_token && curr_token->toktype != TOKEN_EOF)
    {
        process_word_token(curr_cmd, curr_token);
        if (curr_token->toktype == TOKEN_PIPE)
            curr_cmd = handle_pipe(curr_cmd);
        else if (is_redir_token(curr_token->toktype) 
                || curr_token->toktype == TOKEN_HEREDOC)
            process_redir_token(curr_cmd, &curr_token, data);
        else if (curr_token->toktype == TOKEN_EOF)
            break;
        curr_token = curr_token->next;
    }
    return (finalize_parsing(cmd_list, tokens, data));
}
