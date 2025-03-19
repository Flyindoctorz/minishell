/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakchouc <zakchouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 22:38:11 by zakchouc          #+#    #+#             */
/*   Updated: 2024/12/02 22:41:54 by zakchouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_lstadd_front.c
 * @author Ziyad A. Dev (zakchouc@student.42.fr)
 * @brief	Adds the node ’new’ at the beginning of the list.
 * @param lst	The address of a pointer to the first link of a list.
 * @param new	The address of a pointer to the node to be added to the list.
 * @return	None
 * @version 0.1
 * @date 2023-12-02
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*node;

	node = new;
	node->next = *lst;
	*lst = new;
}

// int	main(void)
// {
// 	t_list	*my_lst1;
// 	t_list	*my_lst2;
// 	my_lst1 = ft_lstnew((void *)3);
// 	my_lst2 = ft_lstnew((void *)55);
// 	my_lst1->next = my_lst2;
// 	ft_lstadd_front(my_lst1, my_lst2);
// 	// printf("list : \n");
// 	return (0);
// }
