/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:10:14 by lmokhtar          #+#    #+#             */
/*   Updated: 2025/04/15 17:10:30 by lmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static t_token	*handle_status_var(t_lexer *lexer, int start_pos)
{
	t_token	*token;

	token = create_token(TOKEN_WORD, "$?");
	if (!token)
		return (NULL);
	token->position = start_pos;
	advance_lexer(lexer);
	return (token);
}

static t_token	*handle_empty_var(int start_pos)
{
	return (create_dollar_token(start_pos));
}

static char	*extract_var_name(t_lexer *lexer, int var_len)
{
	char	*var_name;
	char	*full_var_name;

	var_name = ft_substr(lexer->input, lexer->pos, var_len);
	if (!var_name)
	{
		handle_error(MNSHL_ERR_MEMORY,
			"create_expand_token : ft_substr failed");
		return (NULL);
	}
	full_var_name = ft_strjoin("$", var_name);
	free(var_name);
	if (!full_var_name)
		handle_error(MNSHL_ERR_MEMORY,
			"create_expand_token : ft_strjoin failed");
	return (full_var_name);
}

t_token	*create_expand_token(t_lexer *lexer, int start_pos)
{
	int		var_len;
	char	*full_var_name;
	t_token	*token;

	if (lexer->curr_char == '?')
		return (handle_status_var(lexer, start_pos));
	var_len = get_var_name_len(lexer);
	if (var_len == 0)
		return (handle_empty_var(start_pos));
	full_var_name = extract_var_name(lexer, var_len);
	if (!full_var_name)
		return (NULL);
	token = create_token(TOKEN_WORD, full_var_name);
	free(full_var_name);
	if (!token)
	{
		handle_error(MNSHL_ERR_MEMORY,
			"create_expand_token : token creation failed");
		return (NULL);
	}
	token->position = start_pos;
	advance_var_position(lexer, var_len);
	return (token);
}
