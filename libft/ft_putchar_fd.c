/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakchouc <zakchouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:30:43 by zakchouc          #+#    #+#             */
/*   Updated: 2024/12/02 22:35:21 by zakchouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_putchar_fd.c
 * @author Ziyad A. Dev (zakchouc@student.42.fr)
 * @brief	Outputs the character ’c’ to the given file descriptor.
 * 			Allowed function(s) : write
 * @param c		The character to output.
 * @param fd	The file descriptor on which to write.
 * 
 * @return	None
 * @version 0.1
 * @date 2023-11-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// int	main (void)
// {
// 	ft_putchar_fd('\0', 1);
// 	return (0);
// }
