/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_test.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:58:26 by cgelgon           #+#    #+#             */
/*   Updated: 2025/04/03 14:44:52 by lmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_TEST_H
# define DATA_TEST_H


# include "minishell.h"

// code a tester
t_data	*init_data(int ac, char **av, char **envp);
void	free_data(t_data *data);

// env simple
char	*create_env_var(int num);
char	**create_test_env(void);

// env large
char	*create_long_env_var(int index);
int		fill_large_env(char **large_env, int size);
char	**create_large_env(void);
int		verify_large_env(char **env);

// tests
int		test_env(char **original_env, char **dupl_env);
int		test_system_env(int ac, char **av, char **envp);
int		test_null_env(int ac, char **av);
int		test_custom_env(int ac, char **av);
int		test_large_env(int ac, char **av);

// run
int		run_test_env_null_cases(void);
int		run_test_env_valid_cases(void);
int		run_init_test_suite(int ac, char **av, char **envp);

// main
int		main(int ac, char **av, char **envp);

// cleaner
void	clean_test_env(char **env);

#endif