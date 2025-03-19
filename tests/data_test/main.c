/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:54:14 by cgelgon           #+#    #+#             */
/*   Updated: 2025/01/30 14:19:37 by cgelgon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/data_test.h"

int	main(int ac, char **av, char **envp)
{
	printf("=== DÉBUT DES TESTS ===\n");
	if (!run_test_env_null_cases())
	{
		printf("\nÉchec des tests NULL de test_env. Arrêt.\n");
		return (1);
	}
	if (!run_test_env_valid_cases())
	{
		printf("\nÉchec des tests de copies de test_env. Arrêt.\n");
		return (1);
	}
	if (!run_init_test_suite(ac, av, envp))
	{
		printf("\nÉchec des tests d'initialisation. Arrêt.\n");
		return (1);
	}
	printf("\n=== TOUT LES TESTS ONT RÉUSSI ===\n");
	return (0);
}
