/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:53:16 by cgelgon           #+#    #+#             */
/*   Updated: 2025/04/14 19:00:14 by cgelgon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include "structure.h"

int		init_environment(t_data *data, char **envp);
int		init_working_directory(t_data *data);
t_data	*init_data(int ac, char **av, char **envp);
char	**dup_env(char **envp);
char	*init_cwd(void);
// cleanup functions
void	free_env(char **env);
void	free_data(t_data *data);
bool	create_default_env_entries(t_data *minishell);

#endif
