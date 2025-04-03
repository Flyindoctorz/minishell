/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:13:41 by cgelgon           #+#    #+#             */
/*   Updated: 2025/04/03 14:27:48 by cgelgon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool	is_expand_char(char c)
{
	return (c == '$');
}

// Calcule la longueur du nom de variable après le symbole $
int	get_var_name_len(t_lexer *lexer)
{
	int	len;
	int	curr_pos;

	len = 0;
	curr_pos = lexer->pos;
	while (lexer->curr_char && (ft_isalnum(lexer->curr_char)
			|| lexer->curr_char == '_'))
	{
		advance_lexer(lexer);
		len++;
	}
	lexer->pos = curr_pos;
	lexer->curr_char = lexer->input[curr_pos];
	lexer->read_pos = curr_pos + 1;
	return (len);
}

// Crée un token littéral pour un $ simple
t_token	*create_dollar_token(int start_pos)
{
	t_token	*token;

	token = create_token(TOKEN_DOLLAR, "$");
	if (!token)
	{
		handle_error(MNSHL_ERR_MEMORY,
			"create_dollar_token : token creation failed");
		return (NULL);
	}
	token->position = start_pos;
	return (token);
}

// Crée un token d'expansion pour une variable ($VAR)
t_token	*create_expand_token(t_lexer *lexer, int start_pos)
{
	int		var_len;
	char	*var_name;
	t_token	*token;

	var_len = get_var_name_len(lexer);
	var_name = ft_substr(lexer->input, lexer->pos, var_len);
	if (!var_name)
	{
		handle_error(MNSHL_ERR_MEMORY,
			"create_expand_token : ft_substr failed");
		return (NULL);
	}
	token = create_token(TOKEN_EXPAND, var_name);
	free(var_name);
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

// Avance la position du lexer après avoir lu une variable
void	advance_var_position(t_lexer *lexer, int var_len)
{
	int i;

	i = 0;
	while (i < var_len)
	{
		advance_lexer(lexer);
		i++;
	}
}