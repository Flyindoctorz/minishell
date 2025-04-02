/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:39:31 by lmokhtar          #+#    #+#             */
/*   Updated: 2025/04/02 19:09:14 by lmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"

char	*get_value(char *str)
{
	int		i;
	int		j;
	char	*value;

	i = 0;
	while (str[i] != '=')
		i++;
	i++;
	value = malloc(sizeof(char) * (ft_strlen(str) - i) + 1);
	if (!value)
		return (NULL);
	j = 0;
	while (str[i])
		value[j++] = str[i++];
	value[j] = 0;
	return (value);
}

bool	ft_isalpha1(char c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

bool	ft_isalnum1(char c)
{
	return (ft_isalpha(c) || (c >= '0' && c <= '9'));
}

bool	ft_isnum(char c)
{
	return ((c >= '0' && c <= '9'));
}

bool	is_env_valid(char c, bool start)
{
	if (start)
		return (ft_isalpha(c) || c == '_');
	else
		return (ft_isalnum(c) || c == '_');
}
