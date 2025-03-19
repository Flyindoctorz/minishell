/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakchouc <zakchouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:24:45 by zakchouc          #+#    #+#             */
/*   Updated: 2024/12/02 22:34:06 by zakchouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strchr.c
 * @author Ziyad A. Dev (zakchouc@student.42.fr)
 * @brief	The strchr() function returns a pointer to the first
 * 			occurrence of the character c in the string s.
 * 			Here "character" means "byte"
 * 			These functions do not work with wide or multibyte characters.
 * @param s	String to be scanned
 * @param c	Character to be searched in 's'
 * @return	The strchr() function return a pointer to the matched character
 * 			or NULL if the character is not  found. The terminating null
 * 			byte is considered part of the string, so that if c is specified
 * 			as '\0', these functions return a pointer to the terminator.
 * @version 0.1
 * @date 2023-12-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str_ptr;

	str_ptr = (char *)s;
	while (*str_ptr)
	{
		if (*str_ptr == (char) c)
			return (str_ptr);
		str_ptr++;
	}
	if (*str_ptr == (char) c)
		return (str_ptr);
	return (NULL);
}

// int	main(void)
// {
// 	char	data[] = "salam";
// 	char	pattern;
//
// 	pattern = 'l';
//
// 	printf("data : %s\n", data);
//
// 	printf("ft_strchr : %s\n", ft_strchr(data, pattern));
// 	printf("strchr : %s\n", strchr(data, pattern));
//
// 	printf("data : %s\n\n", data);
//
// 	char *str_ft;
// 	char *str_ori;
//
// 	str_ft = ft_strchr("salam", 0);
// 	str_ori = strchr("salame", 0);
// 	printf("ft_strchr  : %p - %p\n", str_ft - 1, str_ft);
// 	printf("strchr ori : %p - %p\n\n", str_ori - 1, str_ori);
//
// 	printf("ft_strchr  : %s\n", ft_strchr(data, 's'));
// 	printf("strchr ori : %s\n", strchr(data, 's'));
//
// 	printf("ft_strchr  : %s\n", ft_strchr(data, '\0'));
// 	printf("strchr ori : %s\n", strchr(data, '\0'));
//
// 	return (0);
// }
