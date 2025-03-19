/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_printf_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakchouc <zakchouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 08:52:14 by zakchouc          #+#    #+#             */
/*   Updated: 2024/11/19 23:37:36 by zakchouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_putnbr_printf_fd.c
 * @author Ziyad A. Dev (zakchouc@student.42.fr)
 * @brief	(Custom func) Outputs the integer ’n’ to the given file descriptor.
 * 			Allowed function(s) : write
 * @param n		The integer to output.
 * @param fd	The file descriptor on which to write.
 * @param count	Address to int counter to be incremented.
 * 
 * @return	None
 * @version 0.1
 * @date 2023-11-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "libft.h"

void	ft_putnbr_printf_fd(int n, int fd, int *count)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		(*count) += 11;
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		(*count)++;
		ft_putnbr_printf_fd(n *= -1, fd, count);
	}
	else if (n >= 0 && n < 10)
	{
		ft_putchar_fd(n + 48, fd);
		(*count)++;
	}
	else if (n >= 10)
	{
		ft_putnbr_printf_fd(n / 10, fd, count);
		ft_putnbr_printf_fd(n %= 10, fd, count);
	}
}
