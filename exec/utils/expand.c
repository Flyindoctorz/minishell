/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:33:09 by lmokhtar          #+#    #+#             */
/*   Updated: 2025/04/15 15:57:56 by lmokhtar         ###   ########.fr       */
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
