/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakchouc <zakchouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 08:27:26 by zakchouc          #+#    #+#             */
/*   Updated: 2024/12/02 23:00:49 by zakchouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_split.c
 * @author Ziyad A. Dev (zakchouc@student.42.fr)
 * @brief	Allocates (with malloc(3)) and returns an array of strings
 * 			obtained by splitting ’s’ using the character ’c’ as a delimiter.
 * 			The array must end with a NULL pointer.
 * 			Allowed funct. : malloc, free
 * @param s	:	The string to be split
 * @param c	:	The delimiter character
 * @return	:	The array of new strings resulting from the split.
 * 				NULL if the allocation fails.
 * @version 0.1
 * @date 2023-11-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "libft.h"

static unsigned int	ft_count_elements(const char *s, const char c)
{
	unsigned int	i;
	unsigned int	elements;

	i = 0;
	elements = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			elements++;
		while (s[i] && (s[i] != c))
			i++;
	}
	return (elements);
}

static char	*ft_strndup_split(const char *s, size_t n)
{
	size_t	i;
	char	*str_dup;

	i = 0;
	str_dup = malloc(sizeof(char) * (n + 1));
	if (!str_dup)
		return (NULL);
	while (s[i] && (i < n))
	{
		str_dup[i] = s[i];
		i++;
	}
	str_dup[i] = 0;
	return (str_dup);
}

void	ft_free_arr(char *arr[], int nb_elmt)
{
	while (nb_elmt >= 0)
		free(arr[nb_elmt--]);
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	int				elmt;
	unsigned int	i;	
	unsigned int	j;
	int				k;
	char			**arr_of_elmts;

	elmt = 0;
	i = 0;
	k = ft_count_elements(s, c);
	arr_of_elmts = ft_calloc(k + 1, sizeof(char *));
	if (!arr_of_elmts)
		return (0);
	while (elmt < k)
	{
		while (s[i] && s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		arr_of_elmts[elmt] = ft_strndup_split((&s[j]), (i - j));
		if (!arr_of_elmts[elmt])
			return (ft_free_arr(arr_of_elmts, elmt), NULL);
		elmt++;
	}
	return (arr_of_elmts[elmt] = 0, arr_of_elmts);
}

// #include "ft_calloc.c"
// #include "ft_bzero.c"
// int	main(void)
// {
// 	const char	to_be_splitted_1[] = "";
// 	const char	to_be_splitted_2[] = "salut,toi";
// 	const char	to_be_splitted_3[] = ",";
// 	const char	to_be_splitted_4[] = "\0aa\0bbb";
// 	const char	to_be_splitted_5[] = "salut";
// 	const char	to_be_splitted_6[] = 
// 				 "      split       this for   me  !       ";
// 	const char	to_be_splitted_7[] = "                  ";
// 	char		**splitted;
// 	int			i;
// 	int			elmts;
//
// 	i = 0;
// 	elmts = ft_count_elements(to_be_splitted_1, ',');
//
// 	splitted = ft_split(to_be_splitted_1, ',');
// 	printf("\n--1--\nelements : %d\n", elmts);
// 	while (i <= elmts)
// 	{
// 		printf("str %d : %s\n", i, splitted[i]);
// 		i++;
// 	}
// 	free(splitted);
//
// 	i = 0;
// 	elmts = ft_count_elements(to_be_splitted_2, ',');
//
// 	splitted = ft_split(to_be_splitted_2, ',');
// 	printf("\n--2--\nelements : %d\n", elmts);
// 	while (i <= elmts)
// 	{
// 		printf("str %d : %s\n", i, splitted[i]);
// 		i++;
// 	}
// 	free(splitted);
//
// 	i = 0;
// 	elmts = ft_count_elements(to_be_splitted_3, ',');
//
// 	splitted = ft_split(to_be_splitted_3, ',');
// 	printf("\n--3--\nelements : %d\n", elmts);
// 	while (i <= elmts)
// 	{
// 		printf("str %d : %s\n", i, splitted[i]);
// 		i++;
// 	}
// 	free(splitted);
//
// 	i = 0;
// 	elmts = ft_count_elements(to_be_splitted_4, '\0');
//
// 	splitted = ft_split(to_be_splitted_4, '\0');
// 	printf("\n--4--\nelements : %d\n", elmts);
// 	while (i <= elmts)
// 	{
// 		printf("str %d : %s\n", i, splitted[i]);
// 		i++;
// 	}
// 	free(splitted);
//
// 	i = 0;
// 	elmts = ft_count_elements(to_be_splitted_5, '\0');
//
// 	splitted = ft_split(to_be_splitted_5, '\0');
// 	printf("\n--5--\nelements : %d\n", elmts);
// 	while (i <= elmts)
// 	{
// 		printf("str %d : %s\n", i, splitted[i]);
// 		i++;
// 	}
// 	free(splitted);
//
// 	i = 0;
// 	elmts = ft_count_elements(to_be_splitted_6, ' ');
//
// 	splitted = ft_split(to_be_splitted_6, ' ');
// 	printf("\n--6--\nelements : %d\n", elmts);
// 	while (i <= elmts)
// 	{
// 		printf("str %d : %s\n", i, splitted[i]);
// 		i++;
// 	}
// 	free(splitted);
//
// 	i = 0;
// 	elmts = ft_count_elements(to_be_splitted_7, ' ');
//
// 	splitted = ft_split(to_be_splitted_7, ' ');
// 	printf("\n--7--\nelements : %d\n", elmts);
// 	while (i <= elmts)
// 	{
// 		printf("str %d : %s\n", i, splitted[i]);
// 		i++;
// 	}
// 	free(splitted);
//
// 	return (0);
// }
