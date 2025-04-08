/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 11:57:17 by cgelgon           #+#    #+#             */
/*   Updated: 2025/04/08 13:35:00 by cgelgon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool	is_redir_token(t_token_type type)
{
	return (type == TOKEN_REDIR_IN || type == TOKEN_REDIR_OUT
		|| type == TOKEN_APPEND || type == TOKEN_HEREDOC);
}

void	free_av_array(char **av, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		free(av[i]);
		i++;
	}
	free(av);
}

int     count_cmd_args(t_token *tokens)
{
    int     count;
    t_token *current;

    count = 0;
    current = tokens;
    while (current)
    {
        if (current->toktype == TOKEN_WORD)
            count++;
        else if (is_redir_token(current->toktype) && current->next)
            current = current->next;
        current = current->next;
    }
    return (count);
}

bool	prepare_command_io(t_cmd_list *cmd, t_data *data)
{
	bool	success;

	if (!cmd)
		return (false);
	success = true;
	if (cmd->heredoc && cmd->delimiter)
	{
		success = handle_heredoc(cmd, cmd->delimiter, data);
		if (!success)
		{
			handle_error(MNSHL_ERR_MEMORY, "Failed to setup heredoc");
			return (false);
		}
	}
	else
	{
		success = setup_redir(cmd);
		if (!success)
		{
			handle_error(MNSHL_ERR_EXEC, "Failed to setup redirections");
			return (false);
		}
	}
	return (success);
}

void	print_command_list(t_cmd_list *cmd_list)
{
	t_cmd_list	*curr;
	int			cmd_num;
	int			i;

	cmd_num = 1;
	curr = cmd_list;
	while (curr)
	{
		printf("Command %d: %s\n", cmd_num++, curr->cmd ? curr->cmd : "NULL");
		printf("  Arguments: ");
		i = 0;
		while (curr->av && curr->av[i])
			printf("%s ", curr->av[i++]);
		printf("\n");
		printf("  Input: %s\n", curr->input_file ? curr->input_file : "stdin");
		printf("  Output: %s\n", curr->output_file ? curr->output_file : "stdout");
		printf("  Append: %s\n", curr->append ? "true" : "false");
		printf("  Heredoc: %s\n", curr->heredoc ? "true" : "false");
		printf("  Delimiter: %s\n", curr->delimiter ? curr->delimiter : "NULL");
		printf("  Pipe: %s\n", curr->is_pipe ? "true" : "false");
		curr = curr->next;
	}
}
