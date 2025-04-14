/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:34:07 by lmokhtar          #+#    #+#             */
/*   Updated: 2025/04/14 17:06:42 by lmokhtar         ###   ########.fr       */
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
	char	*expanded_var;
	int		i;
	int		quote_index;
	int		end_quote;
	char	*inner_content;

	i = 0;
	quote_index = 0;
	if (str[0] == '\'' && ft_strchr(str + 1, '$'))
	{
		end_quote = 1;
		while (str[end_quote] && str[end_quote] != '\'')
			end_quote++;
		inner_content = ft_substr(str, 1, end_quote > 1 ? end_quote - 1 : 0);
		if (!inner_content)
			return (expanded);
		expanded_var = expand(inner_content, minishell);
		free(inner_content);
		if (expanded_var)
		{
			ft_strncat(expanded, "'", 1);
			ft_strncat(expanded, expanded_var, ft_strlen(expanded_var));
			if (str[end_quote] == '\'')
				ft_strncat(expanded, "'", 1);
			free(expanded_var);
			i = end_quote + (str[end_quote] == '\'' ? 1 : 0);
			while (str[i])
				ft_strncat(expanded, str + i++, 1);
			return (expanded);
		}
	}
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
	expanded = malloc(len + 10);
	if (!expanded)
		return (NULL);
	ft_memset(expanded, 0, len + 10);
	expanded = while_expand(str, expanded, minishell);
	return (expanded);
}
