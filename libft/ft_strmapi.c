/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakchouc <zakchouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:38:44 by zakchouc          #+#    #+#             */
/*   Updated: 2024/12/02 22:34:11 by zakchouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strmapi.c
 * @author Ziyad A. Dev (zakchouc@student.42.fr)
 * @brief	Applies the function ’f’ to each character of the string ’s’,
 * 			and passing its index as first argument to create a new string
 * 			(with malloc(3)) resulting from successive applications of ’f’.
 * 			Allowed funct. : malloc
 * @param s	The string on which to iterate.
 * @param f	The function to apply to each character.
 * @return	The string created from the successive applications of ’f’.
 * 			Returns NULL if the allocation fails.
 * @version 0.1
 * @date 2023-11-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	len;
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

// static char	ft_test(unsigned int i, char str)
// {
// 	(void)i;
// 	str = ';';
// 	return (str);
// }
//
// #include "ft_memset.c"
// #include "ft_strlen.c"
// int	main(void)
// {
// 	// char	(*f)(unsigned int, char);
// 	char	*str = "salut";
// 	char	*strmapi;
//
// 	strmapi = malloc(sizeof(char) * 10);
// 	if (!strmapi)
// 		return (0);
// 	ft_memset(strmapi, 'd', 10);
// 	// Assign address of ft_test function to "f"
// 	// f = &ft_test;
// 	printf("\nstrmapi before : %s\n", strmapi);
// 	for (size_t i = 0; i < 12; i++)
// 		printf(" %c", strmapi[i]);
// 	strmapi = ft_strmapi(str, &ft_test);
// 	printf("\nstrmapi after  : %s\n", strmapi);
// 	for (size_t i = 0; i < 12; i++)
// 		printf(" %c", strmapi[i]);
// 	return (0);
// }
