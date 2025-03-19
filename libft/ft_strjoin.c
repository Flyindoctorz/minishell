/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakchouc <zakchouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:13:26 by zakchouc          #+#    #+#             */
/*   Updated: 2024/12/02 22:36:49 by zakchouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strjoin.c
 * @author Ziyad A. Dev (zakchouc@student.42.fr)
 * @brief		Allocates (with malloc(3)) and returns a new string, which
 * 				is the result of the concatenation of ’s1’ and ’s2’.
 * 				Allowed funciton(s) : malloc
 * @param s1	The prefix string.
 * @param s2	The suffix string.
 * 
 * @return		The new string. NULL if the allocation fails.
 * @version 0.1
 * @date 2023-12-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		s1_len;
	int		s2_len;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	i = 0;
	str = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!str)
		return (NULL);
	while (*s1)
		str[i++] = *s1++;
	while (*s2)
		str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}

// int	main(void)
// {
// 	char	*s1 = "salam";
// 	char	*s2 = "hellosalut";
// 	size_t	i;
// 	char	*joined;
//
// 	i = 0;
// 	joined = ft_strjoin(s1, s2);
// 	printf("\nstrjoin : %s\n\n", joined);
// 	while (i < (ft_strlen(joined) + 5))
// 		printf("char : %d\n", joined[i++]);
// 	free(joined);
// 	return (0);
// }
