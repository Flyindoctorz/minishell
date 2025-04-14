/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   negation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:31:34 by cgelgon           #+#    #+#             */
/*   Updated: 2025/04/14 18:48:17 by lmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_negate(t_data *minishell, char **arg)
{
	(void)arg;
	if (minishell->state == 0)
		minishell->state = 1;
	else
		minishell->state = 0;
	return (minishell->state);
}
