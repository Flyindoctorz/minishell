/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakchouc <zakchouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 18:22:31 by zakchouc          #+#    #+#             */
/*   Updated: 2024/12/02 22:31:55 by zakchouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_lstlast.c
 * @author Ziyad A. Dev (zakchouc@student.42.fr)
 * @brief		Returns the last node of the list.
 * @param lst	The beginning of the list.
 * @return		Last node of the list
 * @version 0.1
 * @date 2023-12-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last_node;

	if (!lst)
		return (NULL);
	last_node = lst;
	while (last_node->next)
	{
		last_node = last_node->next;
	}
	return (last_node);
}

// #include "ft_lstadd_front.c"
// #include "ft_lstnew.c"
// #include "ft_lstsize.c"
// int	main(void)
// {
// 	t_list	*my_list = ft_lstnew((void *)67);
// 	ft_lstadd_front(&my_list, ft_lstnew((void *)33));
// 	ft_lstadd_front(&my_list, ft_lstnew((void *)21));
//
// 	printf("lst size : %d\n", ft_lstsize(my_list));
//
// 	printf("last node : %p\n", ft_lstlast(my_list));
//
// 	return (0);
// }
