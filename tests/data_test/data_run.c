/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_run.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:50:07 by cgelgon           #+#    #+#             */
/*   Updated: 2025/01/30 14:09:15 by cgelgon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/data_test.h"

int	run_test_env_null_cases(void)
{
	int		test_status;
	bool	test_succeded;
	char	**single_env;

	test_succeded = true;
	printf("\n=== Test de test_env : cas NULL ===\n");
	test_status = test_env(NULL, NULL);
	print_test("Deux environnements NULL", test_status == 1);
	test_succeded = (test_status == 1);
	single_env = create_test_env();
	if (!single_env)
	{
		printf("Échec création environnement test\n");
		return (false);
	}
	test_status = test_env(single_env, NULL);
	print_test("Un environnement NULL", test_status == 0);
	test_succeded = (test_succeded && (test_status == 0));
	clean_test_env(single_env);
	return (test_succeded);
}

// Vérifie que test_env valide correctement les copies d'environnement
int	run_test_env_valid_cases(void)
{
	int		test_status;
	char	**test_enviro;
	char	**dup_env;

	printf("\n=== Test de test_env : cas valides ===\n");
	test_enviro = create_test_env();
	if (!test_enviro)
	{
		printf("Échec création premier environnement\n");
		return (0);
	}
	dup_env = create_test_env();
	if (!dup_env)
	{
		printf("Échec création second environnement\n");
		clean_test_env(test_enviro);
		return (0);
	}
	test_status = test_env(test_enviro, dup_env);
	print_test("Deux copies valides", test_status == 1);
	clean_test_env(test_enviro);
	clean_test_env(dup_env);
	return (test_status);
}

// Exécution de la suite complète des tests d'initialisation
int	run_init_test_suite(int ac, char **av, char **envp)
{
	int	test_status;

	printf("\n=== Tests d'initialisation ===\n");
	test_status = test_system_env(ac, av, envp);
	if (!test_status)
		return (0);
	test_status = test_null_env(ac, av);
	if (!test_status)
		return (0);
	test_status = test_custom_env(ac, av);
	if (!test_status)
		return (0);
	test_status = test_large_env(ac, av);
	return (test_status);
}
