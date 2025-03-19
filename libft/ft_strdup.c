/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakchouc <zakchouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 08:19:02 by zakchouc          #+#    #+#             */
/*   Updated: 2024/12/02 22:36:28 by zakchouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strdup.c
 * @author Ziyad A. Dev (zakchouc@student.42.fr)
 * @brief 
 * @version 0.1
 * @date 2023-11-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	int		len;

	len = ft_strlen(s);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (*s)
		*str++ = *s++;
	*str = '\0';
	return (str - len);
}

// int	main(void)
// {
// 	char	my_str[] = "salam";
// 	char	*new_address = ft_strdup(my_str);
// 	size_t	i;
//
// 	i = 0;
// 	printf("string  : %s\n", new_address);
// 	printf("address : %p\n\n", new_address);
// 	while (i < (ft_strlen(new_address) + 5))
// 		printf("char : %d\n", new_address[i++]);
// 	free (new_address);
// 	printf("string after free  : %s\n", new_address);
// 	printf("address after free : %p\n", new_address);
// 	i = 0;
// 	while (i < (ft_strlen(new_address) + 5))
// 		printf("char : %d\n", new_address[i++]);
// 	return (0);
// }
