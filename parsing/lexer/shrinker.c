/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shrinker.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:07:37 by cgelgon           #+#    #+#             */
/*   Updated: 2025/03/17 13:21:52 by cgelgon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lexer.h"


// identifie les redir
bool	is_redir(t_token *token)
{
	if (!token)
		return (false);
	if (token->toktype == TOKEN_REDIR_IN
		|| token->toktype == TOKEN_REDIR_OUT
		|| token->toktype == TOKEN_APPEND
		|| token->toktype == TOKEN_HEREDOC)
		return (true);
	return (false);
}

// fusionne les redir avec leur target
t_token	*merge_redir(t_token *redir, t_token *target)
{
	t_token	*merged;

	if (!redir || !target || !target->value)
		return (NULL);
	merged = create_token(redir->toktype, target->value);
	if (!merged)
	{
		handle_error(MNSHL_ERR_MEMORY, "merge_redir : token creation failed");
		return (NULL);
	}
	merged->position = redir->position;
	merged->shrinked = target->toktype;
	return (merged);	
}


// initie le processus de shrinking
t_token	*shrink_redir_tokens(t_token *tokens)
{
    t_token	*res;
    t_token	*res_tail;
    
    res = NULL;
    res_tail = NULL;    
    if (!tokens)
        return (NULL);    
    return (process_token_list(tokens, &res, &res_tail));
}
