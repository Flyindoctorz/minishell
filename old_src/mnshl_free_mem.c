/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mnshl_free_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakchouc <zakchouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 09:15:16 by zakchouc          #+#    #+#             */
/*   Updated: 2024/12/13 19:08:44 by zakchouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_free_everything(t_minishell *mini)
{
	clear_history();
	free(mini->input);
	free(mini);
}

void	ft_free_split_arr(t_minishell *mini)
{
	int	i;

	i = 0;
	while (mini->token_list[i])
	{
		free(mini->token_list[i]);
		++i;
	}
	free(mini->token_list);
}
