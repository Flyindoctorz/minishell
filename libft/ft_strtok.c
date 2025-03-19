/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakchouc <zakchouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 20:42:32 by zakchouc          #+#    #+#             */
/*   Updated: 2024/12/14 21:32:52 by zakchouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strtok.c
 * @author	Ziyad A. Dev (zakchouc@student.42.fr)
 * @brief 	Allocates (with malloc(3)) and returns an array of strings
 * 			obtained by splitting 's' using the characters 'delimiters' as
 * 			delimiters. The array must end with a NULL pointer.
 * @param str 		 :	The string to be split
 * @param delimiters :	The delimiters used to split the string
 * @return			 :	The array of new strings resulting from the split.
 * 						NULL if the allocation fails.
 * @version 0.1
 * @date 2024-12-14
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "libft.h"

static unsigned int	ft_count_elements(const char *str, const char *delims)
{
	unsigned int	i;
	unsigned int	elements;

	i = 0;
	elements = 0;
	while (str[i])
	{
		while (ft_strchr(delims, str[i]))
			++i;
		if (str[i])
			++elements;
		while (str[i] && !ft_strchr(delims, str[i]))
			++i;
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

static void	ft_free_arr(char *arr[], int nb_elmts)
{
	while (nb_elmts >= 0)
		free(arr[nb_elmts--]);
	free(arr);
}

char	**ft_strtok(const char *str, const char *delilmiters)
{
	char			**token_arr;
	unsigned int	tokens;
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = 0;
	k = 0;
	tokens = ft_count_elements(str, delilmiters);
	token_arr = ft_calloc(tokens + 1, sizeof(char *));
	if (!token_arr)
		return (NULL);
	while (k < tokens)
	{
		while (str[i] && (ft_strchr(delilmiters, str[i])))
			++i;
		j = i;
		while (str[i] && (!ft_strchr(delilmiters, str[i])))
			++i;
		token_arr[k] = ft_strndup_split(&str[j], i - j);
		if (!token_arr[k])
			return (ft_free_arr(token_arr, k), NULL);
		++k;
	}
	return (token_arr[k] = NULL, token_arr);
}
