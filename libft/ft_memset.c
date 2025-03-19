/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakchouc <zakchouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:53:57 by zakchouc          #+#    #+#             */
/*   Updated: 2024/12/02 22:42:45 by zakchouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_memset.c
 * @author Ziyad A. Dev (zakchouc@student.42.fr)
 * @brief	The memset() function fills the first n bytes of the memory area
 * 			pointed to by s with the constant byte c.
 * @param s	Memory area to be set
 * @param c	Byte used to fill memory area
 * @param n	Number of byte to set
 * 
 * @return	The memset() function returns a pointer to the memory area s.
 * 
 * @version 0.1
 * @date 2023-11-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*tmp;

	tmp = s;
	while (n--)
		*tmp++ = c;
	return (s);
}

// int	main(void)
// {
// 	int nb[] = {36, 40, 70, 43, 35};
// 	// unsigned char str[] = "salam";
// 	int	i;
//
// 	i = 0;
// 	while (i < 5)
// 	{
// 		printf("nb dig  : %d\n", nb[i]);
// 		printf("nb char : %c\n", nb[i]);
// 		printf("nb ptr  : %p\n\n", &nb[i]);
// 		i++;
// 	}
//  	i = 0;
// 	while (i < 6)
// 	{
// 		printf("byte %d : %c\n", i, *(nb + i));
// 		i++;
// 	}
// 	printf(" ------ memset ----- \n");
//
// 	ft_memset(&nb, 42, 8);
// 	i = 0;
// 	while (i < 5)
// 	{
// 		printf("nb dig  : %d\n", nb[i]);
// 		printf("nb char : %c\n", nb[i]);
// 		printf("nb ptr  : %p\n\n", &nb[i]);
// 		i++;
// 	}
// 	i = 0;
// 	while (i < 6)
// 	{
// 		printf("byte %d : %c\n", i, *(nb + i));
// 		i++;
// 	}
// 	return (0);
// }
