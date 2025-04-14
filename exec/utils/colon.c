/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colon.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:54:00 by cgelgon           #+#    #+#             */
/*   Updated: 2025/04/14 18:48:10 by lmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_colon(t_data *minishell, char **arg)
{
	(void)arg;
	minishell->state = 0;
	return (0);
}
