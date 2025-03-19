/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakchouc <zakchouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 20:06:26 by zakchouc          #+#    #+#             */
/*   Updated: 2024/12/02 22:39:27 by zakchouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strnjoin.c
 * @author Ziyad A. Dev (zakchouc@student.42.fr)
 * @brief		Allocates (with malloc(3)) and returns a new string, which
 * 				is the result of the concatenation of ’s1’ and ’s2’.
 * 				Allowed funciton(s) : malloc
 * @param s1	The prefix string.
 * @param s2	The suffix string.
 * @param n		The lenght of s2.
 * 
 * @return		The new string. NULL if the allocation fails.
 * @version 0.1
 * @date 2024-03-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "libft.h"

char	*ft_strnjoin(char *s1, char *s2, size_t n)
{
	char	*joined;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	if (n)
		s2_len = n;
	else
		s2_len = ft_strlen(s2);
	joined = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!joined)
		return (NULL);
	joined[s1_len + s2_len] = '\0';
	while (s2_len--)
		joined[s1_len + s2_len] = s2[s2_len];
	while (s1_len--)
		joined[s1_len] = s1[s1_len];
	return (joined);
}

// int	main(void)
// {
// 	char	*s1 = "salam";
// 	char	*s2 = "hellosalut";
// 	size_t	i;
// 	char	*joined;
//
// 	i = 0;
// 	joined = ft_strnjoin(s1, s2, 5);
// 	printf("\nstrnjoin : %s\n\n", joined);
// 	while (i < (ft_strlen(joined) + 5))
// 		printf("char : %d\n", joined[i++]);
// 	free(joined);
// 	return (0);
// }
