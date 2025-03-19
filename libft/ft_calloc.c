/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakchouc <zakchouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:36:03 by zakchouc          #+#    #+#             */
/*   Updated: 2024/12/02 22:33:43 by zakchouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_calloc.c
 * @author Ziyad A. Dev (zakchouc@student.42.fr)
 * @brief  Allocate NMEMB elements of SIZE bytes each, all initialized to 0.
 * @version 0.1
 * @date 2023-11-23
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*calloc_space;
	size_t	bytes;

	if (!nmemb || !size)
		return (malloc(0));
	bytes = nmemb * size;
	if ((bytes / size) != nmemb)
		return (NULL);
	calloc_space = malloc(bytes);
	if (!calloc_space)
		return (NULL);
	ft_bzero(calloc_space, (bytes));
	return (calloc_space);
}

// int main() {
//     int	i;
//     int * pointer = (int *) ft_calloc( 10, sizeof(int) );
//
//     /* Un petit test sur le bon fonctionnement de calloc */
//     assert(pointer != NULL);
//
//     /* Le dernier élément du tableau ne sera pas affecté par la */
//     /* boucle mais n'oubliez pas que calloc initialise de toute */
//     /* façon à 0 chaque octet. */
//     for (i = 0; i < 10 - 1; i += 2)
// 	{
//         pointer[i] = i;
//     }
//
//     /* On affiche le contenu du tableau d'entier */
//     /* Ce qui donne : 0 1 2 3 4 5 6 7 8 0 */
//     for (i = 0; i < 10; i++)
// 	{
//         printf("%d ", pointer[i]);
//     }
//     printf("\n");
//
//     /* On libère le bloc de mémoire alloué dynamiquement */
//     free(pointer);
//     return 0;
// }
