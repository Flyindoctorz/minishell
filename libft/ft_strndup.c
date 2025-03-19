/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakchouc <zakchouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 22:18:32 by zakchouc          #+#    #+#             */
/*   Updated: 2024/03/04 22:19:56 by zakchouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strndup.c
 * @author Ziyad A. Dev (zakchouc@student.42.fr)
 * @brief	Returns a pointer to a new string which is a duplicate
 * 			of the string s.
 * @version 0.1
 * @date 2024-03-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*dup;
	size_t	i;

	if (!s)
		return (NULL);
	if (n > ft_strlen(s))
		i = ft_strlen(s);
	else
		i = n;
	dup = malloc(sizeof(char) * i + 1);
	if (!dup)
		return (0);
	i = 0;
	while (s[i] && (i < n))
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

// int	main(void)
// {
// 	char	my_str[] = "salam";
// 	char	*new_address = ft_strndup(my_str, 8);
// 	size_t	i;
//
// 	i = 0;
// 	printf("string  : %s\n", new_address);
// 	printf("address : %p\n\n", new_address);
// 	while (i < (ft_strlen(new_address) + 5))
// 		printf("char : %c\n", new_address[i++]);
// 	free (new_address);
// 	printf("string after free  : %s\n", new_address);
// 	printf("address after free : %p\n", new_address);
// 	i = 0;
// 	while (i < (ft_strlen(new_address) + 5))
// 		printf("char : %c\n", new_address[i++]);
// 	return (0);
// }
