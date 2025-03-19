/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakchouc <zakchouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:52:21 by zakchouc          #+#    #+#             */
/*   Updated: 2024/12/02 22:42:27 by zakchouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_lstsize.c
 * @author Ziyad A. Dev (zakchouc@student.42.fr)
 * @brief		Counts the number of nodes in a list.
 * @param lst	The beginning of the list.
 * @return 		The length of the list
 * @version 0.1
 * @date 2023-12-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*current_node;
	int		i;

	if (!lst)
		return (0);
	current_node = lst;
	i = 0;
	while (current_node)
	{
		current_node = current_node->next;
		i++;
	}
	return (i);
}

// #include "ft_lstadd_front.c"
// #include "ft_lstnew.c"
// int	main(void)
// {
// 	t_list	*my_list = ft_lstnew((void *)67);
// 	ft_lstadd_front(&my_list, ft_lstnew((void *)33));
// 	ft_lstadd_front(&my_list, ft_lstnew((void *)21));
// 	printf("lst size : %d\n", ft_lstsize(my_list));
//
// 	printf("deletion ...\n");
//
// 	return (0);
// }
