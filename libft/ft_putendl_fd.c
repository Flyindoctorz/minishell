/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakchouc <zakchouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 08:38:03 by zakchouc          #+#    #+#             */
/*   Updated: 2024/12/02 22:42:55 by zakchouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_putendl_fd.c
 * @author Ziyad A. Dev (zakchouc@student.42.fr)
 * @brief		Outputs the string ’s’ to the given file descriptor
 * 				followed by a newline.
 * 				Allowed function(s) : write
 * @param s		The string to output.
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

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
	ft_putchar_fd('\n', fd);
}

// int	main(void)
// {
// 	ft_putendl_fd("salut", 1);
// 	return (0);
// }
