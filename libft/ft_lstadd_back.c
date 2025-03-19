/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakchouc <zakchouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 18:35:05 by zakchouc          #+#    #+#             */
/*   Updated: 2024/12/02 22:41:51 by zakchouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_lstadd_back.c
 * @author Ziyad A. Dev (zakchouc@student.42.fr)
 * @brief		Adds the node ’new’ at the end of the list.
 * @param lst	The address of a pointer to the first link of a list.
 * @param new	The address of a pointer to the node to be added to the list.
 * @return 		None
 * @version 0.1
 * @date 2023-12-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_node;

	if (lst)
	{
		if (*lst)
		{
			last_node = ft_lstlast(*lst);
			last_node->next = new;
		}
		else
			*lst = new;
	}
}

// #include "ft_lstadd_front.c"
// #include "ft_lstnew.c"
// #include "ft_lstsize.c"
// #include "ft_lstlast.c"
// int	main(void)
// {
// 	t_list	*my_list = ft_lstnew((void *)67);
// 	// ft_lstadd_front(&my_list, ft_lstnew((void *)33));
// 	// ft_lstadd_front(&my_list, ft_lstnew((void *)21));
//
// 	printf("lst size : %d\n", ft_lstsize(my_list));
//
// 	printf("last node : %p\n", ft_lstlast(my_list));
//
// 	ft_lstadd_back(&my_list, ft_lstnew((void *)890));
//
// 	printf("lst size after add back : %d\n", ft_lstsize(my_list));
//
// 	printf("last node after add back: %p\n", ft_lstlast(my_list));
//
// 	return (0);
// }
