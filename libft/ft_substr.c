/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakchouc <zakchouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:44:33 by zakchouc          #+#    #+#             */
/*   Updated: 2024/12/02 22:33:20 by zakchouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_substr.c
 * @author Ziyad A. Dev (zakchouc@student.42.fr)
 * @brief		Allocates (with malloc(3)) and returns a substring from the
 * 				string  ’s’. The substring begins at index ’start’ and is of
 * 				maximum size ’len’.
 * 				Allowed function(s) : malloc
 * @param s		The string from which to create the substring.
 * @param start	The start index of the substring in the string 's'.
 * @param len	The maximum length of the substring.
 * 
 * @return		The substring. NULL if the allocation fails.
 * @version 0.1
 * @date 2023-11-23
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	int		i;

	i = 0;
	if ((start >= ft_strlen(s)))
	{
		sub_str = ft_calloc(1, 1);
		if (!sub_str)
			return (NULL);
		return (sub_str);
	}
	sub_str = malloc(sizeof(char) * (len + 1));
	if (!sub_str)
		return (NULL);
	while (len--)
		sub_str[i++] = s[start++];
	sub_str[i] = 0;
	return (sub_str);
}

// #include "ft_calloc.c"
// #include "ft_bzero.c"
// #include "ft_strlen.c"
// int	main(void)
// {
// 	char	mystr[] = "salamhellosalut";
// 	char	*mysub_str;
//
// 	mysub_str = ft_substr(mystr, 3, 7);
// 	printf("substr : %s\n", mysub_str);
// 	if (mysub_str)
// 		printf("strlen sub : %ld\n", ft_strlen(mysub_str));
// 	printf("strlen str : %ld\n", ft_strlen(mystr));
// 	free(mysub_str);
// 	return (0);
// }
