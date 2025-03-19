/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakchouc <zakchouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:49:13 by zakchouc          #+#    #+#             */
/*   Updated: 2024/12/02 22:43:38 by zakchouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strlen.c
 * @author Ziyad A. Dev (zakchouc@student.42.fr)
 * @brief 
 * @version 0.1
 * @date 2023-12-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

// #include <stdio.h>
// int	main(void)
// {
// 	printf("strlen : %d\n", ft_strlen(""));
// 	printf("strlen : %d\n", ft_strlen(" "));
// 	printf("strlen : %d\n", ft_strlen("dfr"));
// 	printf("strlen : %d\n", ft_strlen("tdkv "));
// 	printf("strlen : %d\n", ft_strlen("salam !"));
// 	return (0);
// }
