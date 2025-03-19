/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakchouc <zakchouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:26:48 by zakchouc          #+#    #+#             */
/*   Updated: 2024/12/02 22:43:21 by zakchouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_striteri.c
 * @author Ziyad A. Dev (zakchouc@student.42.fr)
 * @brief	Applies the function ’f’ on each character of the string passed
 * 			as argument, passing its index as first argument. Each character
 * 			is passed by address to ’f’ to be modified if necessary.
 * @param s	The string on which to iterate.
 * @param f	The function to apply to each character.
 * 
 * @return	None
 * 
 * @version 0.1
 * @date 2023-11-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		f(i, &s[i]);
		i++;
	}
}

// void	ft_test(unsigned int i, char *c)
// {
// 	printf("ft_test char : %c\ni : %d\n", *c, i);
// 	*c = (i + 48);
// }
// #include "ft_strlen.c"
// int	main(void)
// {
// 	char	*str = "salut";
//
// 	printf("str before : %s\n", str);
// 	ft_striteri(str, ft_test);
// 	printf("str after : %s\n", str);
// 	return (0);
// }
