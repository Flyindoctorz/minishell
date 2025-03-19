/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakchouc <zakchouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:37:32 by zakchouc          #+#    #+#             */
/*   Updated: 2024/12/02 22:33:51 by zakchouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_memcpy.c
 * @author Ziyad A. Dev (zakchouc@student.42.fr)
 * @brief 
 * @version 0.1
 * @date 2023-12-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	unsigned char		*dest_tmp;
	unsigned const char	*src_tmp;

	if (!dest && !src)
		return (NULL);
	dest_tmp = (unsigned char *)dest;
	src_tmp = (unsigned const char *)src;
	while (size--)
		*dest_tmp++ = *src_tmp++;
	return (dest);
}

// int	main(void)
// {
// 	char my_src[] = "salam";
// 	char my_dest[100];
// 	int	i;
//
// 	i = 0;
// 	printf("\nmy src : ");
// 	while (i < (int)sizeof(my_src))
// 	{
// 		printf("%c", my_src[i++]);
// 	}
// 	printf("\n");
// 	i = 0;
// 	printf("\nmy dest : ");
// 	while (i < (int)sizeof(my_dest))
// 	{
// 		printf("%c", my_dest[i++]);
// 	}
// 	ft_memcpy((void *)(0), (void *)(0), 3);
// 	memcpy((void *)(0), (void *)(0), 3);
// 	printf("\n\n-----ft memcpy ---------\n");
// 	i = 0;
// 	printf("\nmy src : ");
// 	while (i < (int)sizeof(my_src))
// 	{
// 		printf("%c", my_src[i++]);
// 	}
// 	printf("\n");
// 	i = 0;
// 	printf("\nmy dest : ");
// 	while (i < (int)sizeof(my_dest))
// 	{
// 		printf("%c", my_dest[i++]);
// 	}
//
// 	return (0);
// }
