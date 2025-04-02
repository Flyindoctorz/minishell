/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 13:56:47 by cgelgon           #+#    #+#             */
/*   Updated: 2025/04/02 17:52:12 by lmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_H
# define EXPAND_H
# include "minishell.h"

typedef struct s_expand
{
	char *content;  // Contenu original
	char *expanded; // Contenu après expansion
	int exit_code;  // Dernier code de sortie pour $?
}	t_expand;

#endif