/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakchouc <zakchouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:30:15 by zakchouc          #+#    #+#             */
/*   Updated: 2024/12/02 22:41:06 by zakchouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_bzero.c
 * @author Ziyad A. Dev (zakchouc@student.42.fr)
 * @brief Erases the data in the n bytes of the memory starting at the location
 * pointed to by s, by writing zeros to that area
 * 
 * @param s Pointer to the memory to be erased
 * @param n Size of the memory space to be erased in bytes
 * 
 * @return None
 * @version 0.1
 * @date 2023-11-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*s_ptr;

	s_ptr = s;
	while (n--)
		*s_ptr++ = 0;
}

// int	main(void)
// {
// 	char mystr[] = "salam";
//
// 	printf("mystr : %s\n", mystr);
// 	ft_bzero(&mystr, 1);
// 	printf("mystr : %s\n", mystr);
//
// 	printf("my c : %c\n", mystr[0]);
// 	printf("my c : %c\n", mystr[1]);
// 	printf("my c : %c\n", mystr[2]);
// 	printf("my c : %c\n", mystr[3]);
// 	printf("my c : %c\n", mystr[4]);
// 	printf("my c : %c\n", mystr[5]);
// 	return (0);
// }
