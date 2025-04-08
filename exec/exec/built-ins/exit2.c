/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:49:39 by lmokhtar          #+#    #+#             */
/*   Updated: 2025/04/08 16:00:09 by lmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

char	*trim_spaces(char *str)
{
	char	*end;

	while (ft_isspace(*str))
		str++;
	end = str + ft_strlen(str) - 1;
	while (end > str && ft_isspace(*end))
		end--;
	end[1] = '\0';
	return (str);
}
