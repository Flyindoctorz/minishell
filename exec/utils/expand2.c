/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:34:07 by lmokhtar          #+#    #+#             */
/*   Updated: 2025/04/14 16:25:06 by lmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	get_env_value(char *str, char *expanded, int *i, t_data *minishell)
{
	char	c;
	char	*value;
	int		start;

	if (str[*i + 1] == '?')
	{
		if_expand(minishell, expanded, i);
		return ;
	}
	if (!is_env_valid(str[*i + 1], 1))
	{
		ft_strncat(expanded, str + (*i)++, 1);
		return ;
	}
	start = ++(*i);
	while (is_env_valid(str[*i], 0))
		(*i)++;
	c = str[*i];
	str[*i] = 0;
	value = get_value_env(str + start, minishell->env);
	if (!value)
		return ;
	ft_strncat(expanded, value, ft_strlen(value));
	str[*i] = c;
	return ;
}

void	if_expand(t_data *minishell, char *expanded, int *i)
{
	char	*st;

	st = NULL;
	st = ft_itoa(minishell->state);
	if (!st)
	{
		ft_end(minishell);
		exit(EXIT_FAILURE);
	}
	*i += 2;
	ft_strncat(expanded, st, ft_strlen(st));
	free(st);
}

char	*while_expand(char *str, char *expanded, t_data *minishell)
{
	int	i;
	int	quote_index;

	i = 0;
	quote_index = 0;
	while (str[i])
	{
		if (str[i] == '\'' && quote_index != 2)
			quote_index = change_quote(str[i++], quote_index);
		else if (str[i] == '"' && quote_index != 1)
			quote_index = change_quote(str[i++], quote_index);
		else
		{
			if (str[i] == '$' && quote_index != 1)
				get_env_value(str, expanded, &i, minishell);
			else
				ft_strncat(expanded, str + i++, 1);
		}
	}
	return (expanded);
}

char	*expand(char *str, t_data *minishell)
{
	char	*expanded;
	int		len;

	len = get_expanded_len(str, minishell);
	expanded = malloc(len + 1);
	if (!expanded)
		return (NULL);
	ft_memset(expanded, 0, len + 1);
	expanded = while_expand(str, expanded, minishell);
	return (expanded);
}
