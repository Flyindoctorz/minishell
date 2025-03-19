/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakchouc <zakchouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 08:58:10 by zakchouc          #+#    #+#             */
/*   Updated: 2024/12/02 22:44:10 by zakchouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strncmp.c
 * @author Ziyad A. Dev (zakchouc@student.42.fr)
 * @brief	The strncmp() function compares at most n bytes of the two
 * 			strings s1 and s2. The locale is not taken into account
 * 			(for a locale-aware comparison, see strcoll(3)).
 * 			The comparison is done using unsigned characters.
 * 			strncmp() returns an integer indicating the result of the
 * 			comparison, as follows:
 * 			- 0, if the s1 and s2 are equal;
 * 			- a negative value if s1 is less than s2;
 *			- a positive value if s1 is greater than s2.
 * @param s1	Pointer to the first string to be compared
 * @param s2	Pointer to the second string to be compared
 * @param n		Number of bytes to be compared
 * @return		The strncmp() function return an integer less
 * 				than, equal to, or greater than zero if s1
 * 				(or the first n bytes thereof) is found, respectively,
 * 				to be less than, to match, or be greater than s2.
 * @version 0.1
 * @date 2023-11-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int					pos;
	unsigned const char	*s1_tmp;
	unsigned const char	*s2_tmp;

	s1_tmp = (unsigned const char *)s1;
	s2_tmp = (unsigned const char *)s2;
	pos = 0;
	while (n-- && (s1_tmp[pos] || s2_tmp[pos]))
	{
		if (s1_tmp[pos] > s2_tmp[pos])
			return ((pos + 1) * 1);
		else if (s2_tmp[pos] > s1_tmp[pos])
			return ((pos + 1) * -1);
		pos++;
	}
	return (0);
}

// int	main(void)
// {
// 	printf("strncmp ft  : %d\n", ft_strncmp("Salam", "Salam", 3));
// 	printf("strncmp ori : %d\n\n", strncmp("Salam", "Salam", 3));
// 	printf("strncmp ft  : %d\n", ft_strncmp("Salam", "Sallam", 3));
// 	printf("strncmp ori : %d\n\n", strncmp("Salam", "Sallam", 3));
// 	printf("strncmp ft  : %d\n", ft_strncmp("Salam", "Sallam", 4));
// 	printf("strncmp ori : %d\n\n", strncmp("Salam", "Sallam", 4));
// 	printf("strncmp ft  : %d\n", ft_strncmp("Saalam", "Salam", 2));
// 	printf("strncmp ori : %d\n\n", strncmp("Saalam", "Salam", 2));
// 	printf("strncmp ft  : %d\n", ft_strncmp("Saalam", "Salam", 5));
// 	printf("strncmp ori : %d\n\n", strncmp("Saalam", "Salam", 5));
// 	printf("strncmp ft  : %d\n", ft_strncmp("Salam", "Saalam", 5));
// 	printf("strncmp ori : %d\n\n", strncmp("Salam", "Saalam", 5));
// 	printf("strncmp ft  : %d\n", ft_strncmp("Salam", "Saalam", 7));
// 	printf("strncmp ori : %d\n\n", strncmp("Salam", "Saalam", 7));
// 	printf("strncmp ft  : %d\n", ft_strncmp("Salam\200", "Salam\0", 7));
// 	printf("strncmp ori : %d\n\n", strncmp("Salam\200", "Salam\0", 7));
// 	printf("strncmp ft  : %d\n", ft_strncmp("", "Salam", 7));
// 	printf("strncmp ori : %d\n\n", strncmp("", "Salam", 7));
// 	printf("strncmp ft  : %d\n", ft_strncmp("Salam", "", 7));
// 	printf("strncmp ori : %d\n\n", strncmp("Salam", "", 7));
//
// 	printf("strncmp ft  : %d\n", ft_strncmp("Salam", "", 7));
// 	printf("strncmp ori : %d\n\n", strncmp("Salam", "", 7));
// 	return (0);
// }
