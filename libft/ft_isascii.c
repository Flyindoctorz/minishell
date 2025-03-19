/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakchouc <zakchouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:00:59 by zakchouc          #+#    #+#             */
/*   Updated: 2024/12/02 22:41:29 by zakchouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_isascii.c
 * @author Ziyad A. Dev (zakchouc@student.42.fr)
 * @brief 
 * @version 0.1
 * @date 2023-12-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "libft.h"

int	ft_isascii(int c)
{
	if ((c >= 0) && (c <= 127))
		return (1);
	else
		return (0);
}

// int	main(void)
// {
// 	printf("isascii %c : %d\n", 'w', ft_isascii('w'));
// 	printf("isascii %c : %d\n", ' ', ft_isascii(' '));
// 	// printf("isascii %c : \n", '£'); //, ft_isascii("£"));
// 	// printf("isascii %c : \n", 'í'); //, ft_isascii("í"));
// 	// printf("isascii %c : \n", 'é'); //, ft_isascii("é"));
// 	printf("isascii %c : %d\n", '/', ft_isascii('/'));
// 	printf("isascii %c : %d\n", '@', ft_isascii('@'));
// 	return (0);
// }
