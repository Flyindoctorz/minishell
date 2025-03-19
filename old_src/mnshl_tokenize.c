/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mnshl_tokenize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakchouc <zakchouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 15:20:06 by zakchouc          #+#    #+#             */
/*   Updated: 2024/12/18 12:43:08 by zakchouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_tokenize(t_minishell *mini)
{
	mini->token_list = ft_strtok(mini->input, " ");
	// ft_free_split_arr(mini);
}

// void	ft_tokenize(t_minishell *mini)
// {
// 	char	*token;
// 	int		token_index;

// 	token_index = 0;
// 	token = strtok(mini->input, " ");
// 	while ((token != NULL) && (token_index < MAX_TOKENS))
// 	{
// 		mini->token_list[token_index] = malloc(sizeof(char) * (strlen(token) + 1));
// 		strcpy(mini->token_list[token_index], token);
// 		// free(token);
// 		token = strtok(NULL, " ");
// 		++token_index;
// 	}
// 	mini->token_list[token_index] = NULL;
// 	// free(token);
// }
