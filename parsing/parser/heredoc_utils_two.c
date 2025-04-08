/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils_two.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:32:37 by cgelgon           #+#    #+#             */
/*   Updated: 2025/04/08 13:32:51 by cgelgon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"

char    *expand_line(char *line, t_data *data)
{
    if (!line || !data)
        return (NULL);
    return (expand(line, data));
}