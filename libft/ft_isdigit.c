/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakchouc <zakchouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:47:28 by zakchouc          #+#    #+#             */
/*   Updated: 2024/12/02 22:44:58 by zakchouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_isdigit.c
 * @author Ziyad A. Dev (zakchouc@student.42.fr)
 * @brief 
 * @version 0.1
 * @date 2023-12-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "libft.h"

int	ft_isdigit(int c)
{
	if ((c >= '0') && (c <= '9'))
		return (1);
	else
		return (0);
}

// int	main(void)
// {
// 	printf("is digit : %d\n", ft_isdigit('2'));
// 	printf("is digit : %d\n", ft_isdigit('?'));
// 	printf("is digit : %d\n", ft_isdigit('0'));
// 	printf("is digit : %d\n", ft_isdigit('\''));
// 	printf("is digit : %d\n", ft_isdigit('a'));
// 	printf("is digit : %d\n", ft_isdigit(' '));
// 	printf("is digit : %d\n", ft_isdigit('9'));
// 	return (0);
// }
