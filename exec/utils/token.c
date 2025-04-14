/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:44:05 by lmokhtar          #+#    #+#             */
/*   Updated: 2025/04/14 16:25:15 by lmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_tokenaddback(t_token **head, t_token *new)
{
	if (!head)
		return ;
	if (*head)
		ft_tokenlast(*head)->next = new;
	else
		*head = new;
}

t_token	*ft_tokennew(char *str, t_token_type type)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->value = str;
	token->toktype = type;
	token->next = NULL;
	return (token);
}

t_token	*ft_tokenlast(t_token *head)
{
	while (head->next)
		head = head->next;
	return (head);
}

void	ft_tokenclear(t_token **token)
{
	t_token	*tmp;

	while (*token)
	{
		tmp = (*token)->next;
		if ((*token)->toktype != TOKEN_PIPE)
			free((*token)->value);
		free((*token));
		(*token) = tmp;
	}
}

void	ft_end(t_data *minishell)
{
	ft_tokenclear(&minishell->token);
	ft_commandclear(&minishell->command);
	ft_envclear(&minishell->env);
	if (minishell->envp != NULL)
	{
		free_tab(minishell->envp);
		minishell->envp = NULL;
	}
	if (minishell->cwd)
		free(minishell->cwd);
	free(minishell);
}
