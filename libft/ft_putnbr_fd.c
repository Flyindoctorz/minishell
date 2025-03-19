/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakchouc <zakchouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 08:52:14 by zakchouc          #+#    #+#             */
/*   Updated: 2024/12/02 22:43:00 by zakchouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_putnbr_fd.c
 * @author Ziyad A. Dev (zakchouc@student.42.fr)
 * @brief	Outputs the integer ’n’ to the given file descriptor.
 * 			Allowed function(s) : write
 * @param n		The integer to output.
 * @param fd	The file descriptor on which to write.
 * 
 * @return	None
 * @version 0.1
 * @date 2023-11-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(n *= -1, fd);
	}
	else if (n >= 0 && n < 10)
		ft_putchar_fd(n + 48, fd);
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n %= 10, fd);
	}
}

// #include "ft_putstr_fd.c"
// #include "ft_putchar_fd.c"
// int	main(void)
// {
// 	int	i;
//
// 	i = -20;
// 	while (i < 20)
// 	{
// 		ft_putnbr_fd(i, 1);
// 		ft_putchar_fd('\n', 1);
// 		i++;
// 	}
// 	return (0);
// }
