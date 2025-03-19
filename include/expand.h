/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 13:56:47 by cgelgon           #+#    #+#             */
/*   Updated: 2025/03/18 14:23:52 by cgelgon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

typedef struct s_expand
{
    char *content;                // Contenu original
    char *expanded;               // Contenu après expansion
    int exit_code;                // Dernier code de sortie pour $?
} t_expand;