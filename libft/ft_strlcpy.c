/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakchouc <zakchouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:52:40 by zakchouc          #+#    #+#             */
/*   Updated: 2024/12/02 22:43:33 by zakchouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strlcpy.c
 * @author Ziyad A. Dev (zakchouc@student.42.fr)
 * @brief	The strlcpy() function copy strings. They are designed to be
 * 			safer, more consistent, and less error prone replacements
 * 			for strncpy(3).
 * 			Unlike this function, strlcpy() take the full size of the
 * 			buffer (not just the length) and guarantee to NUL-terminate
 * 			the result (as long as size is larger than 0).
 * 			Note that a byte for the NUL should be included in size.
 * 			Also note that strlcpy() and strlcat() only operate on
 * 			true “C” strings. This means that for strlcpy() src must be
 * 			NUL-terminated.
 * 			The strlcpy() function copies up to size - 1 characters from
 * 			the NUL-terminated string src to dst, NUL-terminating the result.
 * 
 * @param	dst		Pointer to which the copy operates
 * @param	src		Pointer from which the copy operates
 * @param	size	Amount of character that need to be copied
 * 
 * @return	The strlcpy() function return the total length of the string
 * 			they tried to create. For strlcpy() that means the length of src.
 * 
 * @version 0.1
 * @date 2023-11-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;

	len = 0;
	if (!size)
		return (ft_strlen(src));
	while (src[len] && --size)
	{
		dst[len] = src[len];
		len++;
	}
	dst[len] = '\0';
	while (src[len])
		len++;
	return (len);
}

// #include "ft_strlen.c"
// #define DEST_BUF 100
//
// int	main(void)
// {
// 	size_t	size;
// 	char	destBuffer[DEST_BUF];
// 	char	srcBuffer[256];
// 	char	data_src[] = "salam";
// 	char	data_dest[6];
//
// 	char	data_src_ori[] = "salam";
// 	char	data_dest_ori[6];
// 	char	c;
// 	int		i;
// 	int		j;
//
// 	size = 6;
// 	i = 0;
// 	j = 0;
//
// 	while (j < 10)
// 	{
// 		// Clean src buffer
// 		while (i < 256)
// 			srcBuffer[i++] = 0;
// 		i = 0;
// 		// Put '/' in dest buffer
// 		while (i < DEST_BUF)
// 			destBuffer[i++] = '/';
// 		i = 0;
// 		// Fill-in random string in src buffer
// 		while ((c = rand()%27+97) != 123)
// 			srcBuffer[i++] = c;
// 		printf("\n\nsrc buffer         : %s\n", srcBuffer);
// 		printf("src len            : %zu\n", ft_strlen(srcBuffer));
// 		printf("dest buffer before : %s\n", destBuffer);
//
// 		ft_strlcpy(destBuffer, srcBuffer, DEST_BUF);
// 		printf("dest buffer after  : %s\n------------------>  ", destBuffer);
// 		for (size_t i = 0; i < DEST_BUF+2; i++)
// 			printf(" %d",destBuffer[i]);
// 		j++;
// 	}
//
// 	i = 6;
// 	printf("\ndata_src_ft   : %s\n", data_src);
// 	printf("data_src_ori  : %s\n\n", data_src_ori);
//
// 	printf("data_dest_ft  : %s\n", data_dest);
// 	printf("data_dest_ori : %s\n\n", data_dest_ori);
//
// 	printf("ft_strlcpy    : %zu\n", ft_strlcpy(
// 											data_dest,
// 											data_src,
// 											size));
// 	printf("strlcpy ori   : %zu\n\n", strlcpy(
// 											data_dest_ori,
// 											data_src_ori, size));
//
// 	printf("data_src_ft   : %s\n", data_src);
// 	printf("data_src_ori  : %s\n\n", data_src_ori);
//
// 	printf("data_dest_ft  : %s\n", data_dest);
// 	printf("data_dest_ori : %s\n\n", data_dest_ori);
//
// 	printf("data_dest_ft  : ");
// 	for (size_t i = 0; i < 10; i++)
// 		printf(" %d", data_dest[i]);
// 	printf("\ndata_dest_ori : ");
// 	for (size_t i = 0; i < 10; i++)
// 		printf(" %d", data_dest_ori[i]);
//
// 	printf("\n-");
// 	return (0);
// }
