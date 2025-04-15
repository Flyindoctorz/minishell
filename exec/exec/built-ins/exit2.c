/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:49:39 by lmokhtar          #+#    #+#             */
/*   Updated: 2025/04/15 13:38:09 by cgelgon          ###   ########.fr       */
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

bool is_in_int_range(char *str)
{
	long long 	value = 0;
    int 		sign = 1;
    int 		i = 0;
    
    if (str[i] == '-') {
        sign = -1;
        i++;
    } else if (str[i] == '+') {
        i++;
    }
    while (ft_isnum(str[i])) {
        if (value > INT_MAX / 10)
            return false;
            
        value = value * 10 + (str[i] - '0');
        if ((sign == 1 && value > INT_MAX) || 
            (sign == -1 && value * sign < INT_MIN))
            return false;
            
        i++;
    }
    
    return true;
}
