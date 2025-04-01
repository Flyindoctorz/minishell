/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:20:00 by lmokhtar          #+#    #+#             */
/*   Updated: 2025/03/31 18:17:54 by lmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_UTILS_H
# define STRING_UTILS_H

# include "minishell.h"

// Use same signatures as libft to avoid conflicts
size_t ft_strlen(const char *str);
char *ft_strdup(const char *s);
char *ft_substr(const char *s, unsigned int start, size_t len);
int ft_strcmp(const char *s1, const char *s2);
int ft_strncmp(const char *first, const char *second, size_t length);
size_t ft_strlcpy(char *dst, const char *src, size_t size);
char *ft_strjoin(const char *s1, const char *s2);
char *ft_strchr(const char *s, int c);
int ft_atoi(const char *nptr);

// Additional string utilities
char **ft_split(const char *s, char c);
void free_tab(char **tab);

#endif 