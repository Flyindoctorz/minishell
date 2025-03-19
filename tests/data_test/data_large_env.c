/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_large_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:09:29 by cgelgon           #+#    #+#             */
/*   Updated: 2025/01/30 13:46:27 by cgelgon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/data_test.h"

// Crée une variable d'environnement longue
// before_x correspond a la longueur du prefix
char	*create_long_env_var(int index)
{
	char	*long_value;
	char	*num_str;
	size_t	before_x;

	num_str = ft_itoa(index);
	if (!num_str)
		return (NULL);
	long_value = malloc(200);
	if (!long_value)
	{
		free(num_str);
		return (NULL);
	}
	ft_strcpy(long_value, "LONG_VAR_");
	ft_strcat(long_value, num_str);
	ft_strcat(long_value, "=");
	before_x = ft_strlen(long_value);
	ft_memset(long_value + ft_strlen(long_value), 'X', 199 - before_x);
	long_value[199] = '\0';
	free(num_str);
	return (long_value);
}

// Initialise un tableau d'environnement de grande taille
char	**init_large_env(int size)
{
	char	**large_env;

	size = 50;
	large_env = malloc(sizeof(char *) * (size + 1));
	if (!large_env)
		return (NULL);
	large_env[size] = NULL;
	return (large_env);
}

// Remplit le tableau d'environnement avec des variables
int	fill_large_env(char **large_env, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		large_env[i] = create_long_env_var(i);
		if (!large_env[i])
			return (0);
		i++;
	}
	return (1);
}

// Crée l'environnement complet de grande taille
char	**create_large_env(void)
{
	char	**large_env;
	int		env_size;

	env_size = 50;
	large_env = init_large_env(env_size);
	if (!large_env)
		return (NULL);
	if (!fill_large_env(large_env, env_size))
	{
		clean_test_env(large_env);
		return (NULL);
	}
	return (large_env);
}

// Vérifie la validité de l'environnement créé
int	verify_large_env(char **env)
{
	int	i;

	if (!env)
		return (0);
	i = 0;
	while (env[i])
	{
		if (ft_strlen(env[i]) != 199)
			return (0);
		i++;
	}
	return (1);
}
