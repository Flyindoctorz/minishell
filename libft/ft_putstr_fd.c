/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakchouc <zakchouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:44:01 by zakchouc          #+#    #+#             */
/*   Updated: 2024/12/02 22:43:06 by zakchouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_putstr_fd.c
 * @author Ziyad A. Dev (zakchouc@student.42.fr)
 * @brief	Outputs the string ’s’ to the given file descriptor.
 * 			Allowed function(s) write
 * @param s		The string to output.
 * @param fd	The file descriptor on which to write.
 * 
 * @return None
 * @version 0.1
 * @date 2023-11-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

// // #include "ft_putchar_fd.c"
// int	main(void)
// {
// 	ft_putstr_fd("salut, test", 1);
// 	return (0);
// }
