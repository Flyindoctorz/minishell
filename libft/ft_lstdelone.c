/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakchouc <zakchouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 08:44:52 by zakchouc          #+#    #+#             */
/*   Updated: 2024/12/02 22:42:02 by zakchouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_lstdelone.c
 * @author Ziyad A. Dev (zakchouc@student.42.fr)
 * @brief		Takes as a parameter a node and frees the memory of the node’s
 * 				content using the function ’del’ given as a parameter and free
 * 				the node. The memory of ’next’ must not be freed.
 * 				Allowed function(s) : free
 * @param lst	The node to free.
 * @param del	The address of the function used to delete the content.
 * @return		None
 * @version 0.1
 * @date 2023-12-04
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!del)
		return ;
	if (lst)
	{
		(*del)(lst->content);
		free(lst);
	}
}

// #include "ft_lstadd_front.c"
// #include "ft_lstnew.c"
// #include "ft_lstsize.c"
// #include "ft_lstlast.c"
// int	main(void)
// {
// 	t_list	*my_list = ft_lstnew((void *)67);
// 	t_list	*my_node;
//
// 	ft_lstadd_front(&my_list, ft_lstnew((void *)33));
// 	ft_lstadd_front(&my_list, ft_lstnew((void *)21));
//
// 	my_node = ft_lstnew((void *)7332);
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
// 	printf("delone node : %p\n", ft_lstdelone(my_node));
//
// 	return (0);
// }
