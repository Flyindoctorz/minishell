/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:20:00 by lmokhtar          #+#    #+#             */
/*   Updated: 2025/03/31 18:17:53 by lmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_UTILS_H
# define ENV_UTILS_H

# include "minishell.h"

// Environment validation
bool	is_env_valid(char c, bool start);

// Environment key/value operations
char	*get_key(char *str);
char	*get_value_env(char *key, t_env *env);

// Environment printing
void	env_print(t_env *env);
void	export_print(t_env *env);

#endif 