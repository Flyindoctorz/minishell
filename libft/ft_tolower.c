/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakchouc <zakchouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:17:28 by zakchouc          #+#    #+#             */
/*   Updated: 2024/12/02 22:44:10 by zakchouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_tolower.c
 * @author Ziyad A. Dev (zakchouc@student.42.fr)
 * @brief 
 * @version 0.1
 * @date 2023-12-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "libft.h"

int	ft_tolower(int c)
{
	if ((c >= 'A') && (c <= 'Z'))
		c += 32;
	return (c);
}

// int	main(void)
// {
// 	printf("\ntolower -> %c", ft_tolower('D'));
// 	printf("\ntolower -> %c", ft_tolower('a'));
// 	printf("\ntolower -> %c", ft_tolower('z'));
// 	printf("\ntolower -> %c", ft_tolower('A'));
// 	printf("\ntolower -> %c", ft_tolower('Z'));
// 	printf("\ntolower -> %c", ft_tolower('/'));
// 	printf("\n\ntolower -> %c", tolower('D'));
// 	printf("\ntolower -> %c", tolower('a'));
// 	printf("\ntolower -> %c", tolower('z'));
// 	printf("\ntolower -> %c", tolower('A'));
// 	printf("\ntolower -> %c", tolower('Z'));
// 	printf("\ntolower -> %c", tolower('/'));
// 	return (0);
// }
