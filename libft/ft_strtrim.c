/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakchouc <zakchouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:22:53 by zakchouc          #+#    #+#             */
/*   Updated: 2024/12/02 22:34:19 by zakchouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strtrim.c
 * @author Ziyad A. Dev (zakchouc@student.42.fr)
 * @brief	Allocates (with malloc(3)) and returns a copy of ’s1’ with the
 * 			characters specified in ’set’ removed from the beginning and
 * 			the end of the string.
 * 			Allowed funct. : malloc
 * @param	s1	:	The string to be trimmed.
 * @param	set	:	The reference set of characters to trim.
 * @return	The trimmed string. NULL if the allocation fails.
 * @version 0.1
 * @date 2023-11-23
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "libft.h"

static int	ft_check_char(const char *charset, const char str_c)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == str_c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*str;
	unsigned int	len_left;
	unsigned int	str_len;

	len_left = 0;
	if (!set || !s1)
		return (NULL);
	str_len = 0;
	while (ft_check_char(set, s1[str_len++]))
		len_left++;
	if (!s1[len_left])
	{
		str = malloc(sizeof(char) * 1);
		if (!str)
			return (0);
		*str = 0;
		return (str);
	}
	str_len = ft_strlen(s1);
	while (ft_check_char(set, s1[str_len-- - 1]))
		;
	str_len -= len_left;
	str = ft_substr(s1, len_left, (str_len + 1));
	return (str);
}

// #include "ft_strlen.c"
// #include "ft_substr.c"
// int	main(void)
// {
// 	char	*trimed;
//
// 	trimed = ft_strtrim("  ", " \tshk");
// 	printf("\n------ 1 ------\n");
// 	printf("strtrim         : %s\n", trimed);
// 	printf("strtrim address : %p\n\n", trimed);
// 	free(trimed);
//
// 	trimed = ft_strtrim(" vgstrbrk ", " \tshk");
// 	printf("\n------ 2 ------\n");
// 	printf("strtrim         : %s\n", trimed);
// 	printf("strtrim address : %p\n\n", trimed);
// 	free(trimed);
//
// 	trimed = ft_strtrim(0, " \tshk");
// 	printf("\n------ 3 ------\n");
// 	printf("strtrim         : %s\n", trimed);
// 	printf("strtrim address : %p\n\n", trimed);
// 	free(trimed);
//
// 	trimed = ft_strtrim("  ", 0);
// 	printf("\n------ 4 ------\n");
// 	printf("strtrim         : %s\n", trimed);
// 	printf("strtrim address : %p\n\n", trimed);
// 	free(trimed);
//
// 	trimed = ft_strtrim(0, 0);
// 	printf("\n------ 5 ------\n");
// 	printf("strtrim         : %s\n", trimed);
// 	printf("strtrim address : %p\n\n", trimed);
// 	free(trimed);
//
// 	trimed = ft_strtrim(0, "  ");
// 	printf("\n------ 6 ------\n");
// 	printf("strtrim         : %s\n", trimed);
// 	printf("strtrim address : %p\n\n", trimed);
// 	free(trimed);
//
// 	return (0);
// }
//
//  = test_ft_strtrim =========================================
// $> cp /tmp/tmpm6uj9i87/ref/libft.a libft.a
//
// -rw-r--r-- 1 deepthought root 94862 Dec  6 11:18 libft.a
//
// Segmentation fault (core dumped)
//
// Error encountered while testing
// Grade: 0
