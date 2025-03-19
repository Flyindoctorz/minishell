/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakchouc <zakchouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:31:03 by zakchouc          #+#    #+#             */
/*   Updated: 2024/12/02 22:41:38 by zakchouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_isprint.c
 * @author Ziyad A. Dev (zakchouc@student.42.fr)
 * @brief 
 * @version 0.1
 * @date 2023-12-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "libft.h"

int	ft_isprint(int c)
{
	if ((c >= 32) && (c <= 126))
		return (1);
	else
		return (0);
}

// int	main(void)
// {
// 	printf("ft_isprint %c : %d\n", 's', ft_isprint('s'));	
// 	printf("ft_isprint %c : %d\n", ' ', ft_isprint(' '));	
// 	printf("ft_isprint %c : %d\n", '\'', ft_isprint('\''));	
// 	printf("ft_isprint %c : %d\n", 12, ft_isprint(12));	
// 	printf("ft_isprint %c : %d\n", '\n', ft_isprint('\n'));	
// 	printf("ft_isprint %c : %d\n", '\t', ft_isprint('\t'));	
// 	return (0);
// }
