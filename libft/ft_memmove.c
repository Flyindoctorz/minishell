/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakchouc <zakchouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:11:30 by zakchouc          #+#    #+#             */
/*   Updated: 2024/12/02 22:33:52 by zakchouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_memmove.c
 * @author Ziyad A. Dev (zakchouc@student.42.fr)
 * @brief	The  memmove() function copies n bytes from memory area src to
 * 			memory area dest. The memory areas may overlap: copying takes
 * 			place as though the bytes in src are first copied into a temporary
 * 			array that does not overlap src or dest, and the bytes are then
 * 			copied from the temporary array to dest.
 * @param dest	: Destination memory area 
 * @param src	: Memory area from which to copy
 * @param n		: Number of byte to move
 * @return	Pointer to dest.
 * @version 0.1
 * @date 2023-12-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*src_tmp;
	unsigned char	*dest_tmp;
	int				i;

	if (!dest && !src)
		return (NULL);
	src_tmp = (unsigned char *)src;
	dest_tmp = (unsigned char *)dest;
	i = 0;
	if (dest > src)
	{
		while (n-- > 0)
			dest_tmp[n] = src_tmp[n];
	}
	else
	{
		while (n-- > 0)
		{
			dest_tmp[i] = src_tmp[i];
			i++;
		}
	}
	return (dest);
}

// int	main(void)
// {
// 	char data_ori[50] = "abcdef";
// 	char data_ft[50] = "abcdef";
//
// 	char dest_ft[3] = "ghi";
// 	char dest_ori[3] = "ghi";
//
// 	printf("src_ft  : %s\n", data_ft);
// 	printf("src_ori : %s\n", data_ori);
//
// 	ft_memmove(dest_ft, data_ft, 3);
// 	memmove(dest_ori, data_ori, 3);
//
// 	printf("\nmemmove ----------\n");
// 	printf("dest_ft  : %s\n", data_ft);
// 	printf("dest_ori : %s\n", data_ori);
//
// 	return(0);
// }
