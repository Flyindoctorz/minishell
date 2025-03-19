/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakchouc <zakchouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 09:48:12 by zakchouc          #+#    #+#             */
/*   Updated: 2024/12/02 22:34:16 by zakchouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strnstr.c
 * @author Ziyad A. Dev (zakchouc@student.42.fr)
 * @brief The strnstr() function locates the first occurrence of
 * the null-terminated string little in the string big, where not more than
 * len characters are searched through big.
 * Characters that appear after a ‘\0’ character are not searched.
 * Since the strnstr() function is a FreeBSD specific API, it should only
 * be used when portability is not a concern.
 * @param big
 * @param little
 * @param len
 * @return 	If little is an empty string, big is returned;
 * 			if little occurs nowhere in big, NULL is returned;
 * 			otherwise a pointer to the first character of the first
 * 			occurrence of little is returned.
 * @version 0.1
 * @date 2023-11-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	char		*bptr;
	char		*lptr;

	if (!*little)
		return ((char *)big);
	while (len-- && *big)
	{
		if (*big == *little)
		{
			i = len;
			bptr = (char *)big + 1;
			lptr = (char *)little + 1;
			while (i-- && *bptr && *lptr && *lptr == *bptr)
			{
				++lptr;
				++bptr;
			}
			if (*lptr == '\0')
				return ((char *)big);
		}
		++big;
	}
	return (NULL);
}

// char	*ft_strnstr(const char *big, const char *little, size_t len)
// {
// 	size_t	i;
// 	size_t	j;
//
// 	if (!*little)
// 		return ((char *)big);
// 	i = 0;
// 	while (big[i])
// 	{
// 		j = 0;
// 		while (((i + j) < len) && (big[i + j] == little[j]))
// 		{
// 			if (!big[i + j] && !little[j])
// 				return ((char *)big + i);
// 			j++;
// 		}
// 		if (!little[j])
// 			return ((char *)big + i);
// 		i++;
// 	}
// 	return (NULL);
// }
//
// int	main(int argc, char *argv[])
// {
// 	// int	len;
// 	int i;
// 	// char sub[] = "ll";
// 	// char sub[10] = argv[1];
//
// 	i = 0;
// 	// len = 4;
// 	// len = atoi(argv[1]);
// 	if (argc < 1)
// 		return (0);
// 	(void)argv; //atoi(argv[1])
//
// 	while (i++ < 15)
// 	{
// 		// printf("\nsub : \"%s\"\tlen %d\tft strnstr   : %s\n", sub, i,
// 		// 		ft1_strnstr("salamhellosalut", sub, i));
// 		// printf("sub : \"%s\"\tlen %d\tstrnstr ori  : %s\n", sub, i,
// 		// 		strnstr("salamhellosalut", sub, i));
//
// 		printf("\nsub : \"%s\"\tlen %d\tft strnstr   : %s\n", argv[1], i,
// 				ft_strnstr((NULL), argv[1], i));
// 		printf("sub : \"%s\"\tlen %d\tstrnstr ori  : %s\n", argv[1], i,
// 				strnstr((NULL), argv[1], i));
// 	}
// 	return (0);
// }
