/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakchouc <zakchouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 21:22:11 by zakchouc          #+#    #+#             */
/*   Updated: 2024/12/02 22:41:43 by zakchouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_itoa.c
 * @author Ziyad A. Dev (zakchouc@student.42.fr)
 * @brief	Allocates (with malloc(3)) and returns a string representing the
 * 			integer received as an argument. Negative numbers must be handled.
 * 			Allowed function(s) : malloc
 * @param n	The integer to convert
 * @return	The string representing the integer. NULL if the allocation fails.
 * @version 0.1
 * @date 2023-11-28
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "libft.h"

static int	ft_count_digits(int n)
{
	int	digits;

	digits = 0;
	if (n == 0)
		return (++digits);
	else if (n < 0)
	{
		n *= -1;
		digits++;
	}
	while (n != 0)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

static void	ft_putnbr_to_str(int n, char *dst, int *i)
{
	if (n == -2147483648)
		ft_strlcpy(dst, "-2147483648", 12);
	else if ((n >= 0) && (n < 10))
	{
		dst[*i] = (n + 48);
		(*i)++;
	}
	else if (n < 0)
	{
		dst[*i] = '-';
		(*i)++;
		ft_putnbr_to_str(n *= -1, dst, i);
	}
	else if (n >= 10)
	{
		ft_putnbr_to_str(n / 10, dst, i);
		ft_putnbr_to_str(n % 10, dst, i);
	}
}

char	*ft_itoa(int n)
{
	char			*str;
	int				digits;
	int				i;

	digits = ft_count_digits(n);
	str = malloc(sizeof(*str) * digits + 1);
	if (!str)
		return (0);
	i = 0;
	ft_putnbr_to_str(n, str, &i);
	str[digits] = '\0';
	return (str);
}

// #include <limits.h>
// int	main(void)
// {
// 	char	*itoa_result;
// 	int		my_int;
//
// 	my_int = -2147483648;
//
// 	// int  : 4294967296
// 	// uint : 2147483648
// 	// printf("\n1234 %% 100 : %d\n", (1234 / 1000));
// 	// printf("digits : %d\n", ft_count_digits(9));
// 	// ft_my_putnbr_to_str(-45365);
// 	// ft_my_putnbr_to_str(my_int, str, &i);
// 	itoa_result = ft_itoa(my_int);
// 	printf("INT_MIN : %d\n", INT_MIN);
// 	printf("itoa    : %s\n", itoa_result);
//
// 	for (size_t i = 0; i < 20; i++)
// 	{
// 		printf(" %c", itoa_result[i]);
// 	}
// 	free(itoa_result);
// 	return (0);
// }
