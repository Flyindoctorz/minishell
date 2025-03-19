/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakchouc <zakchouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:55:21 by zakchouc          #+#    #+#             */
/*   Updated: 2024/12/02 22:42:12 by zakchouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_lstmap.c
 * @author Ziyad A. Dev (zakchouc@student.42.fr)
 * @brief		Iterates the list ’lst’ and applies the function ’f’ on the
 * 				content of each node. Creates a new list resulting of the
 * 				successive applications of the function ’f’. The ’del’
 * 				function is used to delete the content of a node if needed.
 * 				Allowed function(s) : malloc, free
 * @param lst	The address of a pointer to a node.
 * @param f		The address of the function used to iterate on the list.
 * @param del	The address of the function used to delete the content of
 * 				a node if needed.
 * @return		The new list. NULL if the allocation fails.
 * @version 0.1
 * @date 2023-12-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_result;
	t_list	*node;

	if (!lst)
		return (NULL);
	lst_result = 0;
	while (lst)
	{
		node = ft_lstnew(f(lst->content));
		if (node == NULL)
		{
			ft_lstclear(&node, del);
			return (NULL);
		}
		ft_lstadd_back(&lst_result, node);
		lst = lst->next;
	}
	return (lst_result);
}
