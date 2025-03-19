/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakchouc <zakchouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:53:37 by zakchouc          #+#    #+#             */
/*   Updated: 2024/12/02 22:41:17 by zakchouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_isalnum.c
 * @author Ziyad A. Dev (zakchouc@student.42.fr)
 * @brief 
 * @version 0.1
 * @date 2023-12-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (((c >= 'a') && (c <= 'z'))
		|| ((c >= 'A') && (c <= 'Z'))
		|| ((c >= '0') && (c <= '9')))
		return (1);
	else
		return (0);
}

// int	main(void)
// {
// 	printf("is alnum : %d\n", ft_isalnum('a'));
// 	printf("is alnum : %d\n", ft_isalnum('S'));
// 	printf("is alnum : %d\n", ft_isalnum('7'));
// 	printf("is alnum : %d\n", ft_isalnum('0'));
// 	printf("is alnum : %d\n", ft_isalnum('9'));
// 	printf("is alnum : %d\n", ft_isalnum('/'));
// 	printf("is alnum : %d\n", ft_isalnum('?'));
// 	printf("is alnum : %d\n", ft_isalnum('!'));
// 	printf("is alnum : %d\n", ft_isalnum(' '));
// 	return (0);
// }
