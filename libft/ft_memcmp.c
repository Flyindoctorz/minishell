/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakchouc <zakchouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:59:18 by zakchouc          #+#    #+#             */
/*   Updated: 2024/12/02 22:42:34 by zakchouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_memcmp.c
 * @author Ziyad A. Dev (zakchouc@student.42.fr)
 * @brief 
 * @version 0.1
 * @date 2023-12-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_ptr;
	unsigned char	*s2_ptr;
	int				pos;

	pos = 0;
	s1_ptr = (unsigned char *)s1;
	s2_ptr = (unsigned char *)s2;
	if (!n)
		return (0);
	while (n--)
	{
		if (s1_ptr[pos] > s2_ptr[pos])
			return (1);
		else if (s2_ptr[pos] > s1_ptr[pos])
			return (-1);
		pos++;
	}
	return (0);
}

// int	main(void)
// {
// 	printf("memcmp :  %d|", ft_memcmp("salam", "salam", 3));
// 	printf("%d  : memcmp ori\n", memcmp("salam", "salam", 3));
// 	printf("memcmp :  %d|", ft_memcmp("salam", "Salam", 3));
// 	printf("%d  : memcmp ori\n", memcmp("salam", "Salam", 3));
// 	printf("memcmp : %d|", ft_memcmp("Salam", "salam", 3));
// 	printf("%d : memcmp ori\n", memcmp("Salam", "salam", 3));
// 	printf("memcmp :  %d|", ft_memcmp("salAm", "salam", 3));
// 	printf("%d  : memcmp ori\n", memcmp("salAm", "salam", 3));
// 	printf("memcmp :  %d|", ft_memcmp("salam", "salAm", 5));
// 	printf("%d  : memcmp ori\n", memcmp("salam", "salAm", 5));
// 	printf("memcmp :  %d|", ft_memcmp("t\200", "t\0", 2));
// 	printf("%d  : memcmp ori\n", memcmp("t\200", "t\0", 2));
// 	return (0);
// }
