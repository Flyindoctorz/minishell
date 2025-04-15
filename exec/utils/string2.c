/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:43:28 by lmokhtar          #+#    #+#             */
/*   Updated: 2025/04/15 15:57:30 by lmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_strncat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	if (!src)
		return ;
	i = ft_strlen(dst);
	j = 0;
	while (src[j] && j < size)
		dst[i++] = src[j++];
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)(s + i) = (unsigned char)c;
		i++;
	}
	return (s);
}

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
		write(fd, &str[i++], 1);
}

int	process_char(char *str, int *i, int *quote_index, t_data *minishell)
{
	int	len;

	if (str[*i] == '$' && *quote_index != 1)
	{
		len = get_env_size(str, i, minishell);
		return (len);
	}
	(*i)++;
	return (1);
}

char	*handle_special_expand_cases(char *str)
{
	if (str && str[0] == '$' && str[1] == '\0')
		return (ft_strdup("$"));
	return (NULL);
}
