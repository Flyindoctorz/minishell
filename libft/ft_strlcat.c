/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakchouc <zakchouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:39:16 by zakchouc          #+#    #+#             */
/*   Updated: 2024/12/02 22:43:28 by zakchouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strlcat.c
 * @author Ziyad A. Dev (zakchouc@student.42.fr)
 * @brief	The strlcat() function concatenate strings. It is designed to be
 * 			safer, more consistent, and less error prone replacements
 * 			for strncat(3). Unlike this function, strlcat() take the full
 * 			size of the buffer (not just the length) and guarantee to
 * 			NUL-terminate the result (as long as there is at least one byte
 * 			free in dst). Note that a byte for the NUL should be included in
 * 			size. Also note that strlcat() only operate on true “C” strings.
 * 			This means that for strlcat() both src and dst must be
 * 			NUL-terminated.
 * 			The strlcat() function appends the NUL-terminated string src to
 * 			the end of dst.
 * 			It will append at most size - strlen(dst) - 1 bytes,
 * 			NUL-terminating the result.
 * @param dst	Destination pointer to which the append will operates
 * @param src	Source pointer from which the append will operates
 * @param size	Number of chars to append NUL-terminated included
 * @return  The strlcat() function return the total length of the string
 * 			they tried to create. For strlcat() that means the initial length
 * 			of dst plus the length of src. While this may seem somewhat
 * 			confusing, it was done to make truncation detection simple.
 * 
 * 			Note, however, that if strlcat() traverses size characters
 * 			without finding a NUL, the length of the string is considered to
 * 			be size and the destination string will not be NUL-terminated
 * 			(since there was no space for the NUL). This keeps strlcat() from
 * 			running off the end of a string.  In practice this should not
 * 			happen (as it means that either size is incorrect or that dst is
 * 			not a proper “C” string). The check exists to prevent potential
 * 			security problems in incorrect code.
 * @version 0.1
 * @date 2023-11-28
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	k;
	size_t	src_len;

	dst_len = 0;
	k = 0;
	src_len = ft_strlen(src);
	if (((!dst) || (!src)) && !size)
		return (src_len);
	while (dst[dst_len] && dst_len < size)
		dst_len++;
	while ((src[k]) && ((dst_len + k + 1) < size))
	{
		dst[dst_len + k] = src[k];
		k++;
	}
	if (dst_len != size)
		dst[dst_len + k] = '\0';
	return (dst_len + src_len);
}

// int	main(void)
// {
// 	size_t size;
// 	char	data_src[20] = "-anta";
// 	char	data_dest[20] = "salam--";
// 	char	data_src_ori[20] = "-anta";
// 	char	data_dest_ori[20] = "salam--";
// 	// int	i;
// 	size = 3;
// 	// i = 3;
// 	printf("\n");
// 	printf("     data_src : %s\n", data_src);
// 	printf(" data_src_ori : %s\n\n", data_src_ori);
// 	printf("    data_dest : %s\n", data_dest);
// 	printf("data_dest_ori : %s\n\n", data_dest_ori);
// 	printf("   ft_strlcat : %lu\n", ft_strlcat(data_dest,
// 												data_src, size));
// 	printf("  strlcat ori : %zu\n\n", strlcat(data_dest_ori,
// 												data_src_ori, size));
// 	printf("     data_src : %s\n", data_src);
// 	printf(" data_src_ori : %s\n\n", data_src_ori);
// 	printf("    data_dest : %s\n", data_dest);
// 	printf("data_dest_ori : %s\n\n", data_dest_ori);
// 	return (0);
// }
//
// #define DEST_BUF 100
//
// int	main(void)
// {
// 	size_t	size;
// 	char	destBuffer_ft[DEST_BUF];
// 	char	srcBuffer_ft[256];
// 	char	destBuffer_ori[DEST_BUF];
// 	char	srcBuffer_ori[256];
// 	char	data_src[] = "my";
// 	char	data_dest[10] = "string";
// 	char	b[0xF] = "nyan !";
//
// 	char	data_src_ori[] = "my";
// 	char	data_dest_ori[10] = "string";
// 	char	c;
// 	int		i;
// 	int		j;
//
// 	size = 2;
// 	i = 0;
// 	j = 0;
// 	while (j < 10)
// 	{
// 		// Put '/' in dest buffer
// 		while (i < 6)
// 			destBuffer_ft[i++] = '/';
// 		i = 0;
// 		// Put '/' in dest buffer
// 		while (i < 6)
// 			destBuffer_ori[i++] = '/';
// 		i = 0;
// 		// Clean ft src buffer
// 		while (i < 256)
// 			srcBuffer_ft[i++] = 0;
// 		i = 0;
// 		// Clean ori src buffer
// 		while (i < 256)
// 			srcBuffer_ori[i++] = 0;
// 		i = 0;
// 		// Fill-in random string in ft src buffer
// 		while ((c = rand()%27+97) != 123)
// 			srcBuffer_ft[i++] = c;
// 		// Fill-in random string in ori src buffer
// 		while ((c = rand()%27+97) != 123)
// 			srcBuffer_ori[i++] = c;
// 		printf("\n\n\nsrc ft buffer         : %s\n", srcBuffer_ft);
// 		printf("src ft len            : %zu\n",
//				ft_strlen(srcBuffer_ft));
// 		printf("dest ft buffer before : %s\n", destBuffer_ft);
//
// 		printf("\n\nsrc ori buffer         : %s\n", srcBuffer_ori);
// 		printf("src ori len            : %zu\n",
//				ft_strlen(srcBuffer_ori));
// 		printf("dest ori buffer before : %s\n", destBuffer_ori);
//
//		ft_strlcat(destBuffer_ft, srcBuffer_ft, DEST_BUF);
//		printf("dest ft buffer after   : %s\n------------------>  ",
//				destBuffer_ft);
//		for (size_t i = 0; i < DEST_BUF+2; i++)
//			printf(" %c",destBuffer_ft[i]);
//
//		strlcat(destBuffer_ori, srcBuffer_ori, DEST_BUF);
//		printf("\ndest ori buffer after  : %s\n------------------>  ",
//				destBuffer_ori);
//		for (size_t i = 0; i < DEST_BUF+2; i++)
//			printf(" %c",destBuffer_ori[i]);
// 		j++;
// 	}
// 	i = 6;
// 	printf("\n\ndata_src_ft   : %s\n", data_src);
// 	printf("data_src_ori  : %s\n\n", data_src_ori);
//
// 	printf("data_dest_ft  : %s\n", data_dest);
// 	printf("data_dest_ori : %s\n\n", data_dest_ori);
//
// 	printf("ft_strlcat    : %zu\n", ft_strlcat(
// 											NULL,
// 											b,
// 											size));
// 	printf("strlcat ori   : %zu\n\n", strlcat(
// 											NULL,
// 											b,
// 											size));
//
// 	printf("data_src_ft   : %s\n", data_src);
// 	printf("data_src_ori  : %s\n\n", data_src_ori);
//
// 	printf("data_dest_ft  : %s\n", data_dest);
// 	printf("data_dest_ori : %s\n\n", data_dest_ori);
//
// 	printf("data_dest_ft  : ");
// 	for (size_t i = 0; i < 13; i++)
// 		printf(" %c", data_dest[i]);
// 	printf("\ndata_dest_ori : ");
// 	for (size_t i = 0; i < 13; i++)
// 		printf(" %c", data_dest_ori[i]);
//
// 	printf("\n-");
// 	return (0);
// }
//
// int	main(void)
// {
// 	char	*dest_ft;
// 	char	*dest_ori;
// 	int		dest_len;
//
// 	alarm(5);
// 	dest_len = 15;
// 	if (!(dest_ft = (char *)malloc(sizeof(*dest_ft) * dest_len)))
// 		return (0);
// 	if (!(dest_ori = (char *)malloc(sizeof(*dest_ori) * dest_len)))
// 		return (0);
// 	memset(dest_ft, 0, dest_len);
// 	memset(dest_ft, 'r', 6);
//
// 	memset(dest_ori, 0, dest_len);
// 	memset(dest_ori, 'r', 6);
// 	dest_ft[14] = 'a';
// 	ft_strlcat(dest_ft, "lorem ipsum dolor sit amet", 15);
// 	strlcat(dest_ori, "lorem ipsum dolor sit amet", 15);
//
// 	write(1, "\nft  : ", 7);
// 	write(1, dest_ft, dest_len);
// 	write(1, "\nori : ", 7);
// 	write(1, dest_ori, dest_len);
// 	return (0);
// }
