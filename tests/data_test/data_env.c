/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:15:56 by cgelgon           #+#    #+#             */
/*   Updated: 2025/01/30 13:45:42 by cgelgon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/data_test.h"

// cree la variable, calcule taille requise, 
//alloue la memoire et construit la chaine
char	*create_env_var(int num)
{
	char	*var;
	char	*num_str;
	size_t	len;

	num_str = ft_itoa(num);
	if (!num_str)
		return (NULL);
	len = ft_strlen("TEST_VAR") + ft_strlen(num_str)
		+ ft_strlen("=value") + ft_strlen(num_str)
		+ ft_strlen("test") + 1;
	var = malloc(len);
	if (!var)
	{
		free(num_str);
		return (NULL);
	}
	ft_strcpy(var, "TEST_VAR");
	ft_strcat(var, num_str);
	ft_strcat(var, num_str);
	ft_strcat(var, "test");
	free(num_str);
	return (var);
}

// Cree env de test
// malloc 3 variables + NULL
char	**create_test_env(void)
{
	char	**env;
	int		i;

	env = malloc(sizeof(char *) * 4);
	if (!env)
		return (NULL);
	i = 0;
	while (i < 3)
	{
		env[i] = create_env_var(i);
		if (!env[i])
		{
			while (--i >= 0)
				free(env[i]);
			free(env);
			return (NULL);
		}
		i++;
	}
	env[3] = NULL;
	return (env);
}
