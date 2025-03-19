/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:18:45 by cgelgon           #+#    #+#             */
/*   Updated: 2025/01/30 14:16:37 by cgelgon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/data_test.h"

/* 1 si valid, 0 else.
verifie cas NULL, fais de vraies copies des chaines /
preserve leurs elements, termine correctement l'env
errr si content different
error si meme adresse memoire
check s'ils finissent en meme temps */
int	test_env(char **original_env, char **dupl_env)
{
	int	i;

	if (!original_env && !dupl_env)
		return (1);
	if (!original_env || !dupl_env)
		return (0);
	i = 0;
	while (original_env[i] && dupl_env[i])
	{
		if (ft_strcmp(original_env[i], dupl_env[i]) != 0)
			return (0);
		if (original_env[i] == dupl_env[i])
			return (0);
		i++;
	}
	return (!original_env[i] && !dupl_env[i]);
}

// Test l'initialisation avec l'environnement système
int	test_system_env(int ac, char **av, char **envp)
{
	t_data	*data;
	int		success;

	printf("\n=== Tests avec environnement système ===\n");
	data = init_data(ac, av, envp);
	if (!data)
	{
		printf("Erreur : échec de l'allocation initiale\n");
		return (0);
	}
	print_test("Arguments count", data->ac == ac);
	print_test("Arguments vector", data->av == av);
	print_test("Environment", test_env(envp, data->envp));
	print_test("Working directory", data->cwd != NULL);
	print_test("Exit status", data->exit == 0);
	print_test("Node number", data->nodenb == 0);
	print_test("Previous pipe", data->prev_pipe_read_end == -1);
	success = (data != NULL);
	free_data(data);
	return (success);
}

// Test l'initialisation avec un environnement NULL
int	test_null_env(int ac, char **av)
{
	t_data	*data;
	int		success;

	printf("\n=== Tests avec environnement NULL ===\n");
	data = init_data(ac, av, NULL);
	if (!data)
	{
		printf("Erreur : échec avec NULL\n");
		return (0);
	}
	print_test("Arguments count", data->ac == ac);
	print_test("Arguments vector", data->av == av);
	print_test("Empty environment created", data->envp != NULL);
	print_test("Working directory", data->cwd != NULL);
	print_test("Exit status", data->exit == 0);
	print_test("Node number", data->nodenb == 0);
	print_test("Previous pipe", data->prev_pipe_read_end == -1);
	success = (data->envp != NULL);
	free_data(data);
	return (success);
}

// Test l'initialisation avec un environnement personnalisé
int	test_custom_env(int ac, char **av)
{
	t_data	*data;
	char	**custom_env;
	int		success;

	printf("\n=== Tests avec environnement personnalisé ===\n");
	custom_env = create_test_env();
	if (!custom_env)
		return (0);
	data = init_data(ac, av, custom_env);
	if (!data)
	{
		clean_test_env(custom_env);
		return (0);
	}
	print_test("Arguments count", data->ac == ac);
	print_test("Arguments vector", data->av == av);
	print_test("Custom environment", test_env(custom_env, data->envp));
	print_test("Working directory", data->cwd != NULL);
	print_test("Exit status", data->exit == 0);
	print_test("Node number", data->nodenb == 0);
	print_test("Previous pipe", data->prev_pipe_read_end == -1);
	success = test_env(custom_env, data->envp);
	free_data(data);
	clean_test_env(custom_env);
	return (success);
}

// Exécute les tests sur l'environnement large
int	test_large_env(int ac, char **av)
{
	t_data	*data;
	char	**large_env;
	int		success;

	printf("\n=== Tests avec environnement très large ===\n");
	large_env = create_large_env();
	if (!large_env || !verify_large_env(large_env))
	{
		clean_test_env(large_env);
		return (0);
	}
	data = init_data(ac, av, large_env);
	success = (data != NULL && test_env(large_env, data->envp));
	print_test("Test grand environnement", success);
	free_data(data);
	clean_test_env(large_env);
	return (success);
}
