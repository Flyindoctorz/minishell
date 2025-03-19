/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mnshl_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakchouc <zakchouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 10:34:48 by zakchouc          #+#    #+#             */
/*   Updated: 2024/12/17 23:09:05 by zakchouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_exit_minishell(t_minishell *mini)
{
	ft_free_everything(mini);
	printf("quitting minishell ...\n");
	exit(EXIT_SUCCESS);
}
