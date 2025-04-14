/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:33:09 by lmokhtar          #+#    #+#             */
/*   Updated: 2025/04/14 17:04:32 by lmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	change_quote(char quote, int i)
{
	if (i == 0)
	{
		if (quote == '\'')
			return (1);
		else if (quote == '"')
			return (2);
	}
	else if ((i == 1 && quote == '\'') || (i == 2 && quote == '"'))
	{
		return (0);
	}
	return (i);
}

int	get_value_len(char *key, t_env *env)
{
	if (!key)
		return (0);
	while (env)
	{
		if (!ft_strcmp(key, env->key))
			return (ft_strlen(env->value));
		env = env->next;
	}
	return (0);
}

char	*get_value_env(char *key, t_env *env)
{
	if (!key)
		return (0);
	while (env)
	{
		if (!ft_strcmp(key, env->key))
			return (env->value);
		env = env->next;
	}
	return (NULL);
}

int	get_env_size(char *str, int *i, t_data *minishell)
{
	char	c;
	int		start;
	int		len;
	char	*ibaby;

	if (str[*i + 1] == '?')
	{
		ibaby = ft_itoa(minishell->state);
		len = ft_strlen(ibaby);
		(*i) += 2;
		return (free(ibaby), len);
	}
	if (!is_env_valid(str[(*i) + 1], 1))
		return ((*i)++, 1);
	start = ++(*i);
	while (is_env_valid(str[*i], 0))
	{
		(*i)++;
	}
	c = str[*i];
	str[*i] = 0;
	len = get_value_len(str + start, minishell->env);
	str[*i] = c;
	return (len);
}

int	get_expanded_len(char *str, t_data *minishell)
{
	int	len;
	int	i;
	int	quote_index;

	len = 0;
	i = 0;
	quote_index = 0;

	// Add extra space for quotes if needed
	if (str[0] == '\'' && ft_strchr(str + 1, '$'))
		len += 2;  // Add space for the opening and closing quotes

	while (str[i])
	{
		if (str[i] == '\'' && quote_index != 2)
			quote_index = change_quote(str[i++], quote_index);
		else if (str[i] == '"' && quote_index != 1)
			quote_index = change_quote(str[i++], quote_index);
		else
		{
			if (str[i] == '$' && quote_index != 1)
				len += get_env_size(str, &i, minishell);
			else
			{
				i++;
				len++;
			}
		}
	}

	// Add a safety margin to prevent buffer overflows
	return (len + 10);  // Add extra space to be safe
}
