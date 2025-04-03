/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:43:57 by lmokhtar          #+#    #+#             */
/*   Updated: 2025/04/03 14:34:08 by cgelgon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	free_tab(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	print_tab(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	printf("ARGUMENTS = ");
	while (tab[i])
	{
		printf("%s, ", tab[i]);
		i++;
	}
}

int	tab_len(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

char	**add_argument(char **tab, char *str)
{
	char	**res;
	int		i;

	if (!str)
		return (free_tab(tab), NULL);
	if (!tab)
	{
		res = malloc(sizeof(char *) * 2);
		if (!res)
			return (0);
		res[0] = str;
		res[1] = 0;
		return (res);
	}
	i = -1;
	res = malloc(sizeof(char *) * (tab_len(tab) + 2));
	if (!res)
		return (NULL);
	while (tab[++i])
		res[i] = tab[i];
	res[i] = str;
	res[++i] = 0;
	return (free(tab), res);
}
