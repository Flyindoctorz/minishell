[1mdiff --git a/parsing/parser/heredoc.c b/parsing/parser/heredoc.c[m
[1mindex 325ffdd..7c985e4 100644[m
[1m--- a/parsing/parser/heredoc.c[m
[1m+++ b/parsing/parser/heredoc.c[m
[36m@@ -6,7 +6,7 @@[m
 /*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */[m
 /*                                                +#+#+#+#+#+   +#+           */[m
 /*   Created: 2025/03/19 14:54:33 by cgelgon           #+#    #+#             */[m
[31m-/*   Updated: 2025/04/03 17:31:38 by lmokhtar         ###   ########.fr       */[m
[32m+[m[32m/*   Updated: 2025/04/07 17:51:40 by lmokhtar         ###   ########.fr       */[m
 /*                                                                            */[m
 /* ************************************************************************** */[m
 [m
[36m@@ -23,7 +23,7 @@[m [mbool	setup_heredoc_redir(t_cmd_list *cmd, t_heredoc *heredoc)[m
 	if (cmd->delimiter)[m
 	{[m
 		free(cmd->delimiter);[m
[31m-		cmd->delimiter = NULL;[m
[32m+[m		[32mcmd->delimiter = NULL;[m[41m [m
 	}[m
 	cmd->delimiter = ft_strdup(heredoc->delimiter);[m
 	if (!cmd->delimiter)[m
[1mdiff --git a/tests/READMETEST.txt b/tests/READMETEST.txt[m
[1mdeleted file mode 100644[m
[1mindex 0aa862a..0000000[m
[1m--- a/tests/READMETEST.txt[m
[1m+++ /dev/null[m
[36m@@ -1,36 +0,0 @@[m
[31m-# **************************************************************************** #[m
[31m-#                                                                              #[m
[31m-#                                                         :::      ::::::::    #[m
[31m-#    lexique.txt                                        :+:      :+:    :+:    #[m
[31m-#                                                     +:+ +:+         +:+      #[m
[31m-#    By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+         #[m
[31m-#                                                 +#+#+#+#+#+   +#+            #[m
[31m-#    Created: 2025/01/22 16:28:44 by cgelgon           #+#    #+#              #[m
[31m-#    Updated: 2025/01/22 16:28:44 by cgelgon          ###   ########.fr        #[m
[31m-#                                                                              #[m
[31m-# **************************************************************************** #[m
[31m-[m
[31m-Permet de faire des verifications sur l'implementation de data et de l'env[m
[31m-[m
[31m-data_test.h -[m
[31m-[m
[31m-Contient uniquement clean_test_env[m
[31m-S'assure qu'on ne laisse pas de déchets en mémoire[m
[31m-[m
[31m-data_env.c - [m
[31m-Crée les éléments de base pour nos tests[m
[31m-Fabrique les variables d'environnement une par une[m
[31m-[m
[31m-data_large_env_test.c -[m
[31m-Crée et gère des environnements très grands[m
[31m-[m
[31m-data_test.c -[m
[31m-[m
[31m-Contient les quatre tests essentiels :[m
[31m-[m
[31m-Test normal (system_env)[m
[31m-Test sans environnement (null_env)[m
[31m-Test avec environnement personnalisé (custom_env)[m
[31m-Test avec grand environnement (large_env)[m
[31m-[m
[31m-data_cleaner.c - Le nettoyeur[m
\ No newline at end of file[m
[1mdiff --git a/tests/data_test/Makefile b/tests/data_test/Makefile[m
[1mdeleted file mode 100644[m
[1mindex 1577ed8..0000000[m
[1m--- a/tests/data_test/Makefile[m
[1m+++ /dev/null[m
[36m@@ -1,84 +0,0 @@[m
[31m-# **************************************************************************** #[m
[31m-#                                                                              #[m
[31m-#                                                         :::      ::::::::    #[m
[31m-#    Makefile                                           :+:      :+:    :+:    #[m
[31m-#                                                     +:+ +:+         +:+      #[m
[31m-#    By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+         #[m
[31m-#                                                 +#+#+#+#+#+   +#+            #[m
[31m-#    Created: 2025/03/13 10:00:00 by cgelgon           #+#    #+#              #[m
[31m-#    Updated: 2025/03/12 15:47:55 by cgelgon          ###   ########.fr        #[m
[31m-#                                                                              #[m
[31m-# **************************************************************************** #[m
[31m-[m
[31m-# Définition des chemins de base[m
[31m-ROOT_DIR = ../..[m
[31m-INCLUDE_DIR = $(ROOT_DIR)/include[m
[31m-DATA_DIR = $(ROOT_DIR)/parsing/data_structure[m
[31m-LIBFT_DIR = $(ROOT_DIR)/libft[m
[31m-[m
[31m-# Configuration du compilateur[m
[31m-NAME = data_tester[m
[31m-CC = cc[m
[31m-CFLAGS = -Wall -Wextra -Werror -g[m
[31m-INCLUDES = -I$(LIBFT_DIR) -I$(INCLUDE_DIR)[m
[31m-[m
[31m-LIBFT = $(LIBFT_DIR)/libft.a[m
[31m-LDFLAGS = -L$(LIBFT_DIR) -lft[m
[31m-[m
[31m-# Sources[m
[31m-TEST_SRCS = data_env.c \[m
[31m-            data_large_env.c \[m
[31m-            data_test.c \[m
[31m-            data_run.c \[m
[31m-            data_utils.c \[m
[31m-            main.c[m
[31m-[m
[31m-PROJ_SRCS = $(DATA_DIR)/init_base.c \[m
[31m-            $(DATA_DIR)/exit_free.c \[m
[31m-            $(DATA_DIR)/init_environment.c \[m
[31m-            $(INCLUDE_DIR)/error.c[m
[31m-[m
[31m-OBJ_DIR = obj[m
[31m-TEST_OBJS = $(TEST_SRCS:%.c=$(OBJ_DIR)/%.o)[m
[31m-PROJ_OBJS = $(notdir $(PROJ_SRCS:%.c=%.o))[m
[31m-PROJ_OBJS := $(addprefix $(OBJ_DIR)/, $(PROJ_OBJS))[m
[31m-OBJS = $(TEST_OBJS) $(PROJ_OBJS)[m
[31m-[m
[31m-# Main rules[m
[31m-all: $(NAME)[m
[31m-[m
[31m-$(OBJ_DIR):[m
[31m-	@mkdir -p $(OBJ_DIR)[m
[31m-[m
[31m-$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)[m
[31m-	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@[m
[31m-[m
[31m-$(OBJ_DIR)/%.o: $(DATA_DIR)/%.c | $(OBJ_DIR)[m
[31m-	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@[m
[31m-[m
[31m-$(OBJ_DIR)/%.o: $(INCLUDE_DIR)/%.c | $(OBJ_DIR)[m
[31m-	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@[m
[31m-[m
[31m-$(LIBFT):[m
[31m-	@$(MAKE) -C $(LIBFT_DIR)[m
[31m-[m
[31m-$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJS)[m
[31m-	$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)[m
[31m-[m
[31m-# Run test after build[m
[31m-test: $(NAME)[m
[31m-	@echo "\n=== Running data structure tests ===\n"[m
[31m-	./$(NAME)[m
[31m-[m
[31m-# Cleaning rules[m
[31m-clean:[m
[31m-	@rm -rf $(OBJ_DIR)[m
[31m-	@$(MAKE) -C $(LIBFT_DIR) clean[m
[31m-[m
[31m-fclean: clean[m
[31m-	@rm -f $(NAME)[m
[31m-	@$(MAKE) -C $(LIBFT_DIR) fclean[m
[31m-[m
[31m-re: fclean all[m
[31m-[m
[31m-.PHONY: all clean fclean re test[m
\ No newline at end of file[m
[1mdiff --git a/tests/data_test/data_env.c b/tests/data_test/data_env.c[m
[1mdeleted file mode 100644[m
[1mindex b92b262..0000000[m
[1m--- a/tests/data_test/data_env.c[m
[1m+++ /dev/null[m
[36m@@ -1,68 +0,0 @@[m
[31m-/* ************************************************************************** */[m
[31m-/*                                                                            */[m
[31m-/*                                                        :::      ::::::::   */[m
[31m-/*   data_env.c                                         :+:      :+:    :+:   */[m
[31m-/*                                                    +:+ +:+         +:+     */[m
[31m-/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */[m
[31m-/*                                                +#+#+#+#+#+   +#+           */[m
[31m-/*   Created: 2025/01/22 13:15:56 by cgelgon           #+#    #+#             */[m
[31m-/*   Updated: 2025/01/30 13:45:42 by cgelgon          ###   ########.fr       */[m
[31m-/*                                                                            */[m
[31m-/* ************************************************************************** */[m
[31m-[m
[31m-#include "../../include/data_test.h"[m
[31m-[m
[31m-// cree la variable, calcule taille requise, [m
[31m-//alloue la memoire et construit la chaine[m
[31m-char	*create_env_var(int num)[m
[31m-{[m
[31m-	char	*var;[m
[31m-	char	*num_str;[m
[31m-	size_t	len;[m
[31m-[m
[31m-	num_str = ft_itoa(num);[m
[31m-	if (!num_str)[m
[31m-		return (NULL);[m
[31m-	len = ft_strlen("TEST_VAR") + ft_strlen(num_str)[m
[31m-		+ ft_strlen("=value") + ft_strlen(num_str)[m
[31m-		+ ft_strlen("test") + 1;[m
[31m-	var = malloc(len);[m
[31m-	if (!var)[m
[31m-	{[m
[31m-		free(num_str);[m
[31m-		return (NULL);[m
[31m-	}[m
[31m-	ft_strcpy(var, "TEST_VAR");[m
[31m-	ft_strcat(var, num_str);[m
[31m-	ft_strcat(var, num_str);[m
[31m-	ft_strcat(var, "test");[m
[31m-	free(num_str);[m
[31m-	return (var);[m
[31m-}[m
[31m-[m
[31m-// Cree env de test[m
[31m-// malloc 3 variables + NULL[m
[31m-char	**create_test_env(void)[m
[31m-{[m
[31m-	char	**env;[m
[31m-	int		i;[m
[31m-[m
[31m-	env = malloc(sizeof(char *) * 4);[m
[31m-	if (!env)[m
[31m-		return (NULL);[m
[31m-	i = 0;[m
[31m-	while (i < 3)[m
[31m-	{[m
[31m-		env[i] = create_env_var(i);[m
[31m-		if (!env[i])[m
[31m-		{[m
[31m-			while (--i >= 0)[m
[31m-				free(env[i]);[m
[31m-			free(env);[m
[31m-			return (NULL);[m
[31m-		}[m
[31m-		i++;[m
[31m-	}[m
[31m-	env[3] = NULL;[m
[31m-	return (env);[m
[31m-}[m
[1mdiff --git a/tests/data_test/data_large_env.c b/tests/data_test/data_large_env.c[m
[1mdeleted file mode 100644[m
[1mindex eba6c16..0000000[m
[1m--- a/tests/data_test/data_large_env.c[m
[1m+++ /dev/null[m
[36m@@ -1,104 +0,0 @@[m
[31m-/* ************************************************************************** */[m
[31m-/*                                                                            */[m
[31m-/*                                                        :::      ::::::::   */[m
[31m-/*   data_large_env.c                                   :+:      :+:    :+:   */[m
[31m-/*                                                    +:+ +:+         +:+     */[m
[31m-/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */[m
[31m-/*                                                +#+#+#+#+#+   +#+           */[m
[31m-/*   Created: 2025/01/22 16:09:29 by cgelgon           #+#    #+#             */[m
[31m-/*   Updated: 2025/01/30 13:46:27 by cgelgon          ###   ########.fr       */[m
[31m-/*                                                                            */[m
[31m-/* ************************************************************************** */[m
[31m-[m
[31m-#include "../../include/data_test.h"[m
[31m-[m
[31m-// Crée une variable d'environnement longue[m
[31m-// before_x correspond a la longueur du prefix[m
[31m-char	*create_long_env_var(int index)[m
[31m-{[m
[31m-	char	*long_value;[m
[31m-	char	*num_str;[m
[31m-	size_t	before_x;[m
[31m-[m
[31m-	num_str = ft_itoa(index);[m
[31m-	if (!num_str)[m
[31m-		return (NULL);[m
[31m-	long_value = malloc(200);[m
[31m-	if (!long_value)[m
[31m-	{[m
[31m-		free(num_str);[m
[31m-		return (NULL);[m
[31m-	}[m
[31m-	ft_strcpy(long_value, "LONG_VAR_");[m
[31m-	ft_strcat(long_value, num_str);[m
[31m-	ft_strcat(long_value, "=");[m
[31m-	before_x = ft_strlen(long_value);[m
[31m-	ft_memset(long_value + ft_strlen(long_value), 'X', 199 - before_x);[m
[31m-	long_value[199] = '\0';[m
[31m-	free(num_str);[m
[31m-	return (long_value);[m
[31m-}[m
[31m-[m
[31m-// Initialise un tableau d'environnement de grande taille[m
[31m-char	**init_large_env(int size)[m
[31m-{[m
[31m-	char	**large_env;[m
[31m-[m
[31m-	size = 50;[m
[31m-	large_env = malloc(sizeof(char *) * (size + 1));[m
[31m-	if (!large_env)[m
[31m-		return (NULL);[m
[31m-	large_env[size] = NULL;[m
[31m-	return (large_env);[m
[31m-}[m
[31m-[m
[31m-// Remplit le tableau d'environnement avec des variables[m
[31m-int	fill_large_env(char **large_env, int size)[m
[31m-{[m
[31m-	int	i;[m
[31m-[m
[31m-	i = 0;[m
[31m-	while (i < size)[m
[31m-	{[m
[31m-		large_env[i] = create_long_env_var(i);[m
[31m-		if (!large_env[i])[m
[31m-			return (0);[m
[31m-		i++;[m
[31m-	}[m
[31m-	return (1);[m
[31m-}[m
[31m-[m
[31m-// Crée l'environnement complet de grande taille[m
[31m-char	**create_large_env(void)[m
[31m-{[m
[31m-	char	**large_env;[m
[31m-	int		env_size;[m
[31m-[m
[31m-	env_size = 50;[m
[31m-	large_env = init_large_env(env_size);[m
[31m-	if (!large_env)[m
[31m-		return (NULL);[m
[31m-	if (!fill_large_env(large_env, env_size))[m
[31m-	{[m
[31m-		clean_test_env(large_env);[m
[31m-		return (NULL);[m
[31m-	}[m
[31m-	return (large_env);[m
[31m-}[m
[31m-[m
[31m-// Vérifie la validité de l'environnement créé[m
[31m-int	verify_large_env(char **env)[m
[31m-{[m
[31m-	int	i;[m
[31m-[m
[31m-	if (!env)[m
[31m-		return (0);[m
[31m-	i = 0;[m
[31m-	while (env[i])[m
[31m-	{[m
[31m-		if (ft_strlen(env[i]) != 199)[m
[31m-			return (0);[m
[31m-		i++;[m
[31m-	}[m
[31m-	return (1);[m
[31m-}[m
[1mdiff --git a/tests/data_test/data_run.c b/tests/data_test/data_run.c[m
[1mdeleted file mode 100644[m
[1mindex 161bbb4..0000000[m
[1m--- a/tests/data_test/data_run.c[m
[1m+++ /dev/null[m
[36m@@ -1,84 +0,0 @@[m
[31m-/* ************************************************************************** */[m
[31m-/*                                                                            */[m
[31m-/*                                                        :::      ::::::::   */[m
[31m-/*   data_run.c                                         :+:      :+:    :+:   */[m
[31m-/*                                                    +:+ +:+         +:+     */[m
[31m-/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */[m
[31m-/*                                                +#+#+#+#+#+   +#+           */[m
[31m-/*   Created: 2025/01/22 17:50:07 by cgelgon           #+#    #+#             */[m
[31m-/*   Updated: 2025/01/30 14:09:15 by cgelgon          ###   ########.fr       */[m
[31m-/*                                                                            */[m
[31m-/* ************************************************************************** */[m
[31m-[m
[31m-#include "../../include/data_test.h"[m
[31m-[m
[31m-int	run_test_env_null_cases(void)[m
[31m-{[m
[31m-	int		test_status;[m
[31m-	bool	test_succeded;[m
[31m-	char	**single_env;[m
[31m-[m
[31m-	test_succeded = true;[m
[31m-	printf("\n=== Test de test_env : cas NULL ===\n");[m
[31m-	test_status = test_env(NULL, NULL);[m
[31m-	print_test("Deux environnements NULL", test_status == 1);[m
[31m-	test_succeded = (test_status == 1);[m
[31m-	single_env = create_test_env();[m
[31m-	if (!single_env)[m
[31m-	{[m
[31m-		printf("Échec création environnement test\n");[m
[31m-		return (false);[m
[31m-	}[m
[31m-	test_status = test_env(single_env, NULL);[m
[31m-	print_test("Un environnement NULL", test_status == 0);[m
[31m-	test_succeded = (test_succeded && (test_status == 0));[m
[31m-	clean_test_env(single_env);[m
[31m-	return (test_succeded);[m
[31m-}[m
[31m-[m
[31m-// Vérifie que test_env valide correctement les copies d'environnement[m
[31m-int	run_test_env_valid_cases(void)[m
[31m-{[m
[31m-	int		test_status;[m
[31m-	char	**test_enviro;[m
[31m-	char	**dup_env;[m
[31m-[m
[31m-	printf("\n=== Test de test_env : cas valides ===\n");[m
[31m-	test_enviro = create_test_env();[m
[31m-	if (!test_enviro)[m
[31m-	{[m
[31m-		printf("Échec création premier environnement\n");[m
[31m-		return (0);[m
[31m-	}[m
[31m-	dup_env = create_test_env();[m
[31m-	if (!dup_env)[m
[31m-	{[m
[31m-		printf("Échec création second environnement\n");[m
[31m-		clean_test_env(test_enviro);[m
[31m-		return (0);[m
[31m-	}[m
[31m-	test_status = test_env(test_enviro, dup_env);[m
[31m-	print_test("Deux copies valides", test_status == 1);[m
[31m-	clean_test_env(test_enviro);[m
[31m-	clean_test_env(dup_env);[m
[31m-	return (test_status);[m
[31m-}[m
[31m-[m
[31m-// Exécution de la suite complète des tests d'initialisation[m
[31m-int	run_init_test_suite(int ac, char **av, char **envp)[m
[31m-{[m
[31m-	int	test_status;[m
[31m-[m
[31m-	printf("\n=== Tests d'initialisation ===\n");[m
[31m-	test_status = test_system_env(ac, av, envp);[m
[31m-	if (!test_status)[m
[31m-		return (0);[m
[31m-	test_status = test_null_env(ac, av);[m
[31m-	if (!test_status)[m
[31m-		return (0);[m
[31m-	test_status = test_custom_env(ac, av);[m
[31m-	if (!test_status)[m
[31m-		return (0);[m
[31m-	test_status = test_large_env(ac, av);[m
[31m-	return (test_status);[m
[31m-}[m
[1mdiff --git a/tests/data_test/data_test.c b/tests/data_test/data_test.c[m
[1mdeleted file mode 100644[m
[1mindex 2d56442..0000000[m
[1m--- a/tests/data_test/data_test.c[m
[1m+++ /dev/null[m
[36m@@ -1,141 +0,0 @@[m
[31m-/* ************************************************************************** */[m
[31m-/*                                                                            */[m
[31m-/*                                                        :::      ::::::::   */[m
[31m-/*   data_test.c                                        :+:      :+:    :+:   */[m
[31m-/*                                                    +:+ +:+         +:+     */[m
[31m-/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */[m
[31m-/*                                                +#+#+#+#+#+   +#+           */[m
[31m-/*   Created: 2025/01/22 16:18:45 by cgelgon           #+#    #+#             */[m
[31m-/*   Updated: 2025/01/30 14:16:37 by cgelgon          ###   ########.fr       */[m
[31m-/*                                                                            */[m
[31m-/* ************************************************************************** */[m
[31m-[m
[31m-#include "../../include/data_test.h"[m
[31m-[m
[31m-/* 1 si valid, 0 else.[m
[31m-verifie cas NULL, fais de vraies copies des chaines /[m
[31m-preserve leurs elements, termine correctement l'env[m
[31m-errr si content different[m
[31m-error si meme adresse memoire[m
[31m-check s'ils finissent en meme temps */[m
[31m-int	test_env(char **original_env, char **dupl_env)[m
[31m-{[m
[31m-	int	i;[m
[31m-[m
[31m-	if (!original_env && !dupl_env)[m
[31m-		return (1);[m
[31m-	if (!original_env || !dupl_env)[m
[31m-		return (0);[m
[31m-	i = 0;[m
[31m-	while (original_env[i] && dupl_env[i])[m
[31m-	{[m
[31m-		if (ft_strcmp(original_env[i], dupl_env[i]) != 0)[m
[31m-			return (0);[m
[31m-		if (original_env[i] == dupl_env[i])[m
[31m-			return (0);[m
[31m-		i++;[m
[31m-	}[m
[31m-	return (!original_env[i] && !dupl_env[i]);[m
[31m-}[m
[31m-[m
[31m-// Test l'initialisation avec l'environnement système[m
[31m-int	test_system_env(int ac, char **av, char **envp)[m
[31m-{[m
[31m-	t_data	*data;[m
[31m-	int		success;[m
[31m-[m
[31m-	printf("\n=== Tests avec environnement système ===\n");[m
[31m-	data = init_data(ac, av, envp);[m
[31m-	if (!data)[m
[31m-	{[m
[31m-		printf("Erreur : échec de l'allocation initiale\n");[m
[31m-		return (0);[m
[31m-	}[m
[31m-	print_test("Arguments count", data->ac == ac);[m
[31m-	print_test("Arguments vector", data->av == av);[m
[31m-	print_test("Environment", test_env(envp, data->envp));[m
[31m-	print_test("Working directory", data->cwd != NULL);[m
[31m-	print_test("Exit status", data->exit == 0);[m
[31m-	print_test("Node number", data->nodenb == 0);[m
[31m-	print_test("Previous pipe", data->prev_pipe_read_end == -1);[m
[31m-	success = (data != NULL);[m
[31m-	free_data(data);[m
[31m-	return (success);[m
[31m-}[m
[31m-[m
[31m-// Test l'initialisation avec un environnement NULL[m
[31m-int	test_null_env(int ac, char **av)[m
[31m-{[m
[31m-	t_data	*data;[m
[31m-	int		success;[m
[31m-[m
[31m-	printf("\n=== Tests avec environnement NULL ===\n");[m
[31m-	data = init_data(ac, av, NULL);[m
[31m-	if (!data)[m
[31m-	{[m
[31m-		printf("Erreur : échec avec NULL\n");[m
[31m-		return (0);[m
[31m-	}[m
[31m-	print_test("Arguments count", data->ac == ac);[m
[31m-	print_test("Arguments vector", data->av == av);[m
[31m-	print_test("Empty environment created", data->envp != NULL);[m
[31m-	print_test("Working directory", data->cwd != NULL);[m
[31m-	print_test("Exit status", data->exit == 0);[m
[31m-	print_test("Node number", data->nodenb == 0);[m
[31m-	print_test("Previous pipe", data->prev_pipe_read_end == -1);[m
[31m-	success = (data->envp != NULL);[m
[31m-	free_data(data);[m
[31m-	return (success);[m
[31m-}[m
[31m-[m
[31m-// Test l'initialisation avec un environnement personnalisé[m
[31m-int	test_custom_env(int ac, char **av)[m
[31m-{[m
[31m-	t_data	*data;[m
[31m-	char	**custom_env;[m
[31m-	int		success;[m
[31m-[m
[31m-	printf("\n=== Tests avec environnement personnalisé ===\n");[m
[31m-	custom_env = create_test_env();[m
[31m-	if (!custom_env)[m
[31m-		return (0);[m
[31m-	data = init_data(ac, av, custom_env);[m
[31m-	if (!data)[m
[31m-	{[m
[31m-		clean_test_env(custom_env);[m
[31m-		return (0);[m
[31m-	}[m
[31m-	print_test("Arguments count", data->ac == ac);[m
[31m-	print_test("Arguments vector", data->av == av);[m
[31m-	print_test("Custom environment", test_env(custom_env, data->envp));[m
[31m-	print_test("Working directory", data->cwd != NULL);[m
[31m-	print_test("Exit status", data->exit == 0);[m
[31m-	print_test("Node number", data->nodenb == 0);[m
[31m-	print_test("Previous pipe", data->prev_pipe_read_end == -1);[m
[31m-	success = test_env(custom_env, data->envp);[m
[31m-	free_data(data);[m
[31m-	clean_test_env(custom_env);[m
[31m-	return (success);[m
[31m-}[m
[31m-[m
[31m-// Exécute les tests sur l'environnement large[m
[31m-int	test_large_env(int ac, char **av)[m
[31m-{[m
[31m-	t_data	*data;[m
[31m-	char	**large_env;[m
[31m-	int		success;[m
[31m-[m
[31m-	printf("\n=== Tests avec environnement très large ===\n");[m
[31m-	large_env = create_large_env();[m
[31m-	if (!large_env || !verify_large_env(large_env))[m
[31m-	{[m
[31m-		clean_test_env(large_env);[m
[31m-		return (0);[m
[31m-	}[m
[31m-	data = init_data(ac, av, large_env);[m
[31m-	success = (data != NULL && test_env(large_env, data->envp));[m
[31m-	print_test("Test grand environnement", success);[m
[31m-	free_data(data);[m
[31m-	clean_test_env(large_env);[m
[31m-	return (success);[m
[31m-}[m
[1mdiff --git a/tests/data_test/data_utils.c b/tests/data_test/data_utils.c[m
[1mdeleted file mode 100644[m
[1mindex 6fa9048..0000000[m
[1m--- a/tests/data_test/data_utils.c[m
[1m+++ /dev/null[m
[36m@@ -1,25 +0,0 @@[m
[31m-/* ************************************************************************** */[m
[31m-/*                                                                            */[m
[31m-/*                                                        :::      ::::::::   */[m
[31m-/*   data_utils.c                                       :+:      :+:    :+:   */[m
[31m-/*                                                    +:+ +:+         +:+     */[m
[31m-/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */[m
[31m-/*                                                +#+#+#+#+#+   +#+           */[m
[31m-/*   Created: 2025/01/22 16:25:14 by cgelgon           #+#    #+#             */[m
[31m-/*   Updated: 2025/02/11 16:32:54 by cgelgon          ###   ########.fr       */[m
[31m-/*                                                                            */[m
[31m-/* ************************************************************************** */[m
[31m-[m
[31m-#include "../../include/data_test.h"[m
[31m-[m
[31m-void	clean_test_env(char **env)[m
[31m-{[m
[31m-	int	i;[m
[31m-[m
[31m-	if (!env)[m
[31m-		return ;[m
[31m-	i = 0;[m
[31m-	while (env[i])[m
[31m-		free(env[i++]);[m
[31m-	free(env);[m
[31m-}[m
[1mdiff --git a/tests/data_test/main.c b/tests/data_test/main.c[m
[1mdeleted file mode 100644[m
[1mindex 2134d86..0000000[m
[1m--- a/tests/data_test/main.c[m
[1m+++ /dev/null[m
[36m@@ -1,35 +0,0 @@[m
[31m-/* ************************************************************************** */[m
[31m-/*                                                                            */[m
[31m-/*                                                        :::      ::::::::   */[m
[31m-/*   main.c                                             :+:      :+:    :+:   */[m
[31m-/*                                                    +:+ +:+         +:+     */[m
[31m-/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */[m
[31m-/*                                                +#+#+#+#+#+   +#+           */[m
[31m-/*   Created: 2025/01/22 17:54:14 by cgelgon           #+#    #+#             */[m
[31m-/*   Updated: 2025/01/30 14:19:37 by cgelgon          ###   ########.fr       */[m
[31m-/*                                                                            */[m
[31m-/* ************************************************************************** */[m
[31m-[m
[31m-#include "../../include/data_test.h"[m
[31m-[m
[31m-int	main(int ac, char **av, char **envp)[m
[31m-{[m
[31m-	printf("=== DÉBUT DES TESTS ===\n");[m
[31m-	if (!run_test_env_null_cases())[m
[31m-	{[m
[31m-		printf("\nÉchec des tests NULL de test_env. Arrêt.\n");[m
[31m-		return (1);[m
[31m-	}[m
[31m-	if (!run_test_env_valid_cases())[m
[31m-	{[m
[31m-		printf("\nÉchec des tests de copies de test_env. Arrêt.\n");[m
[31m-		return (1);[m
[31m-	}[m
[31m-	if (!run_init_test_suite(ac, av, envp))[m
[31m-	{[m
[31m-		printf("\nÉchec des tests d'initialisation. Arrêt.\n");[m
[31m-		return (1);[m
[31m-	}[m
[31m-	printf("\n=== TOUT LES TESTS ONT RÉUSSI ===\n");[m
[31m-	return (0);[m
[31m-}[m
[1mdiff --git a/tests/data_test/test_large_env_full_debug.txt b/tests/data_test/test_large_env_full_debug.txt[m
[1mdeleted file mode 100644[m
[1mindex 3a45032..0000000[m
[1m--- a/tests/data_test/test_large_env_full_debug.txt[m
[1m+++ /dev/null[m
[36m@@ -1,84 +0,0 @@[m
[31m-test_large_env_full_debug.txt[m
[31m-[m
[31m-// VERSION TEST[m
[31m-int test_large_env(int ac, char **av)[m
[31m-{[m
[31m-	t_data *data;[m
[31m-	char **large_env;[m
[31m-	int success;[m
[31m-[m
[31m-	printf("\n=== Tests avec environnement très large ===\n");[m
[31m-	fflush(stdout);[m
[31m-	printf("Debug: Tentative de création de l'environnement large...\n");[m
[31m-	fflush(stdout);[m
[31m-	large_env = create_large_env();[m
[31m-	if (!large_env)[m
[31m-	{[m
[31m-		printf("Debug: Échec de create_large_env - Retourne NULL\n");[m
[31m-		fflush(stdout);[m
[31m-		return (0);[m
[31m-	}[m
[31m-	printf("Debug: Environnement large créé avec succès\n");[m
[31m-	fflush(stdout);[m
[31m-	printf("Debug: Vérification de la structure de l'environnement...\n");[m
[31m-	fflush(stdout);[m
[31m-	if (!verify_large_env(large_env))[m
[31m-	{[m
[31m-		printf("Debug: Échec de la vérification - Structure invalide\n");[m
[31m-		int i = 0;[m
[31m-		while (large_env[i])[m
[31m-		{[m
[31m-			size_t len = ft_strlen(large_env[i]);[m
[31m-			if (len != 199) // 199 est la nouvelle taille attendue[m
[31m-			{[m
[31m-				printf("Debug: Variable[%d] = '%s'\n", i, large_env[i]);[m
[31m-				printf("Debug: Longueur = %zu (attendu 199)\n", len);[m
[31m-				fflush(stdout);[m
[31m-				break;[m
[31m-			}[m
[31m-			i++;[m
[31m-		}[m
[31m-		clean_test_env(large_env);[m
[31m-		return (0);[m
[31m-	}[m
[31m-	printf("Debug: Tentative d'initialisation des données avec l'environnement...\n");[m
[31m-	fflush(stdout);[m
[31m-	data = init_data(ac, av, large_env);[m
[31m-	if (!data)[m
[31m-	{[m
[31m-		printf("Debug: Échec de init_data avec l'environnement large\n");[m
[31m-		fflush(stdout);[m
[31m-		clean_test_env(large_env);[m
[31m-		return (0);[m
[31m-	}[m
[31m-	printf("Debug: Vérification de la copie de l'environnement...\n");[m
[31m-	fflush(stdout);[m
[31m-	if (!test_env(large_env, data->envp))[m
[31m-	{[m
[31m-		printf("Debug: La copie de l'environnement n'est pas conforme\n");[m
[31m-		int i = 0;[m
[31m-		while (large_env[i] && data->envp[i])[m
[31m-		{[m
[31m-			if (ft_strcmp(large_env[i], data->envp[i]) != 0)[m
[31m-			{[m
[31m-				printf("Debug: Différence à l'index %d:\n", i);[m
[31m-				printf("Debug: Original : '%s'\n", large_env[i]);[m
[31m-				printf("Debug: Copie    : '%s'\n", data->envp[i]);[m
[31m-				fflush(stdout);[m
[31m-				break;[m
[31m-			}[m
[31m-			i++;[m
[31m-		}[m
[31m-		success = 0;[m
[31m-	}[m
[31m-	else[m
[31m-	{[m
[31m-		printf("Debug: Copie de l'environnement validée\n");[m
[31m-		fflush(stdout);[m
[31m-		success = 1;[m
[31m-	}[m
[31m-	print_test("Test grand environnement", success);[m
[31m-	free_data(data);[m
[31m-	clean_test_env(large_env);[m
[31m-	return (success);[m
[31m-}[m
[1mdiff --git a/tests/lexer_test/Makefile b/tests/lexer_test/Makefile[m
[1mdeleted file mode 100644[m
[1mindex 7ace0d4..0000000[m
[1m--- a/tests/lexer_test/Makefile[m
[1m+++ /dev/null[m
[36m@@ -1,157 +0,0 @@[m
[31m-# Chemins de base[m
[31m-ROOT_DIR = ../..[m
[31m-INCLUDE_DIR = $(ROOT_DIR)/include[m
[31m-LEXER_DIR = $(ROOT_DIR)/parsing/lexer[m
[31m-DATA_DIR = $(ROOT_DIR)/parsing/data_structure[m
[31m-LIBFT_DIR = $(ROOT_DIR)/libft[m
[31m-[m
[31m-# Configuration du compilateur[m
[31m-NAME = lexer_tester[m
[31m-CC = cc[m
[31m-CFLAGS = -Wall -Wextra -Werror -g[m
[31m-INCLUDES = -I$(LIBFT_DIR) \[m
[31m-           -I$(INCLUDE_DIR)[m
[31m-[m
[31m-LIBFT = $(LIBFT_DIR)/libft.a[m
[31m-LDFLAGS = -L$(LIBFT_DIR) -lft[m
[31m-[m
[31m-# Sources des tests organisées par sous-dossiers[m
[31m-DATA_TEST_SRCS = data_test/data_env.c \[m
[31m-                 data_test/data_large_env.c \[m
[31m-                 data_test/data_run.c \[m
[31m-                 data_test/data_test.c \[m
[31m-                 data_test/data_utils.c[m
[31m-SETUP_TEST_SRCS = setup_test/before_init_lexer.c \[m
[31m-                  setup_test/init_lexer_test.c \[m
[31m-                  setup_test/delimiter_test.c \[m
[31m-                  setup_test/lexer_run.c[m
[31m-[m
[31m-LEXER_TEST_SRCS = lexer_test/lexer_utils_test.c \[m
[31m-                  lexer_test/whitespace_test.c \[m
[31m-                  lexer_test/read_word_test.c \[m
[31m-                  lexer_test/read_word_test_utils.c \[m
[31m-                  lexer_test/syntax_test.c \[m
[31m-                  lexer_test/quotes_test.c[m
[31m-[m
[31m-EXPAND_TEST_SRCS = expand_test/expand_test_utils.c \[m
[31m-                   expand_test/expand_test_basic.c \[m
[31m-                   expand_test/expand_test_edge.c[m
[31m-[m
[31m-SHRINKER_TEST_SRCS = shrinker_test/shrinker_test_basic.c \[m
[31m-                     shrinker_test/shrinker_test_simple.c \[m
[31m-                     shrinker_test/shrinker_test_multiple.c \[m
[31m-                     shrinker_test/shrinker_test_mixed.c \[m
[31m-                     shrinker_test/shrinker_test_utils.c \[m
[31m-                     shrinker_test/shrinker_test_run.c[m
[31m-[m
[31m-[m
[31m-# Fichier principal[m
[31m-MAIN_SRC = main.c[m
[31m-[m
[31m-# Regroupement de tous les tests[m
[31m-TEST_SRCS = $(MAIN_SRC) \[m
[31m-			$(DATA_TEST_SRCS) \[m
[31m-            $(SETUP_TEST_SRCS) \[m
[31m-            $(LEXER_TEST_SRCS) \[m
[31m-            $(EXPAND_TEST_SRCS) \[m
[31m-			$(SHRINKER_TEST_SRCS)[m
[31m-[m
[31m-# Fichiers source du projet[m
[31m-PROJ_SRCS = $(LEXER_DIR)/init_lexer.c \[m
[31m-            $(LEXER_DIR)/utils_lexer.c \[m
[31m-            $(LEXER_DIR)/read_word.c \[m
[31m-            $(LEXER_DIR)/quotes_utils.c \[m
[31m-            $(LEXER_DIR)/read_quotes.c \[m
[31m-            $(LEXER_DIR)/read_operator.c \[m
[31m-            $(LEXER_DIR)/read_expand.c \[m
[31m-            $(LEXER_DIR)/expand_utils.c \[m
[31m-			$(LEXER_DIR)/shrinker.c \[m
[31m-			$(LEXER_DIR)/shrinker_three.c \[m
[31m-			$(LEXER_DIR)/shrinker_two.c \[m
[31m-			$(DATA_DIR)/init_base.c \[m
[31m-            $(DATA_DIR)/exit_free.c \[m
[31m-            $(DATA_DIR)/init_environment.c \[m
[31m-			$(LEXER_DIR)/lexer_main.c \[m
[31m-			$(IN