/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakchouc <zakchouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 08:45:06 by zakchouc          #+#    #+#             */
/*   Updated: 2024/12/02 22:41:58 by zakchouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_lstclear.c
 * @author Ziyad A. Dev (zakchouc@student.42.fr)
 * @brief		Deletes and frees the given node and every successor of that
 * 				node, using the function ’del’ and free(3).
 * 				Finally, the pointer to the list must be set to NULL.
 * 				Allowed function(s) : free
 * @param lst: The address of a pointer to a node.
 * @param del: The address of the function used to delete the content of
 * 				the node.
 * @version 0.1
 * @date 2023-12-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node_to_delete;

	if (!del || !lst || !*lst)
		return ;
	while (lst && *lst)
	{
		node_to_delete = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = node_to_delete;
	}
}

// static int	nb_free_done;
//
// static void			ft_delelem(void *content)
// {
// 	free(content);
// 	nb_free_done++;
// }
//
// #include "ft_lstadd_back.c"
// #include "ft_lstadd_front.c"
// #include "ft_lstdelone.c"
// #include "ft_lstlast.c"
// #include "ft_lstnew.c"
// #include "ft_lstsize.c"
// int	main(void)
// {
// 	t_list	*my_list = ft_lstnew((void *)67);
// 	t_list	*my_node;
//
// 	my_node = ft_lstnew((void *)7332);
//
// 	ft_lstadd_front(&my_list, my_node);
// 	ft_lstadd_front(&my_list, ft_lstnew((void *)33));
// 	ft_lstadd_front(&my_list, ft_lstnew((void *)21));
//
// 	printf("lst size : %d\n", ft_lstsize(my_list));
//
// 	printf("last node : %p\n", ft_lstlast(my_list));
//
// 	ft_lstadd_back(&my_list, ft_lstnew((void *)890));
// 	ft_lstadd_back(&my_list, ft_lstnew((void *)8210));
//
// 	printf("lst size after add back : %d\n", ft_lstsize(my_list));
//
// 	printf("last node after add back: %p\n", ft_lstlast(my_list));
//
// 	nb_free_done = 0;
// 	ft_lstclear(&my_node, &ft_delelem);
// 	printf("lst size after lstclear : %d\n", ft_lstsize(my_list));
// 	printf("number of free done : %d\n", nb_free_done);
// 	return (0);
// }
