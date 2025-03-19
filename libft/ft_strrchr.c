/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakchouc <zakchouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:49:53 by zakchouc          #+#    #+#             */
/*   Updated: 2024/12/02 22:34:17 by zakchouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strrchr.c
 * @author Ziyad A. Dev (zakchouc@student.42.fr)
 * @brief 
 * @version 0.1
 * @date 2023-12-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str_ptr;
	int		len;

	str_ptr = (char *) s;
	len = ft_strlen(str_ptr);
	while (len >= 0)
	{
		if (str_ptr[len] == (char) c)
			return (&str_ptr[len]);
		len--;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char	data[] = "salamhellosalut";
//
// 	printf("\nstrrchr       m  : %s", ft_strrchr(data, 'm'));
// 	printf("\nstrrchr   ori m  : %s\n", strrchr(data, 'm'));
// 	printf("\nstrrchr       s  : %s", ft_strrchr(data, 's'));
// 	printf("\nstrrchr   ori s  : %s\n", strrchr(data, 's'));
// 	printf("\nstrrchr       a  : %s", ft_strrchr(data, 'a'));
// 	printf("\nstrrchr   ori a  : %s\n", strrchr(data, 'a'));
// 	printf("\nstrrchr       l  : %s", ft_strrchr(data, 'l'));
// 	printf("\nstrrchr   ori l  : %s\n", strrchr(data, 'l'));
// 	printf("\nstrrchr       .  : %s", ft_strrchr(data, '.'));
// 	printf("\nstrrchr   ori .  : %s\n", strrchr(data, '.'));
// 	printf("\nstrrchr      \\0 : %s", ft_strrchr(data, '\0'));
// 	printf("\nstrrchr  ori \\0 : %s\n", strrchr(data, '\0'));
//
// 	return (0);
// }
