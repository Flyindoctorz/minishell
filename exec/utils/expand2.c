/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:34:07 by lmokhtar          #+#    #+#             */
/*   Updated: 2025/04/15 15:54:14 by lmokhtar         ###   ########.fr       */
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
	if (str[0] == '\'' && ft_strchr(str + 1, '$'))
		return (process_quoted_expansion(str, expanded, minishell));
	while (str[i])
	{
		if (str[i] == '\'' && quote_index != 2)
			quote_index = change_quote(str[i++], quote_index);
		else if (str[i] == '"' && quote_index != 1)
			quote_index = change_quote(str[i++], quote_index);
		else if (str[i] == '$' && quote_index != 1)
			get_env_value(str, expanded, &i, minishell);
		else
			ft_strncat(expanded, str + i++, 1);
	}
	return (expanded);
}

char	*process_single_quote_expansion(char *str, t_data *minishell)
{
	int		end_pos;
	char	*inner_content;
	char	*temp;
	char	*expanded_content;
	char	*result;

	end_pos = 1;
	while (str[end_pos] && str[end_pos] != '\'')
		end_pos++;
	inner_content = ft_substr(str, 1, end_pos - 1);
	if (!inner_content)
		return (NULL);
	temp = malloc(ft_strlen(inner_content) * 4 + 10);
	if (!temp)
	{
		free(inner_content);
		return (NULL);
	}
	ft_memset(temp, 0, ft_strlen(inner_content) * 4 + 10);
	expanded_content = while_expand(inner_content, temp, minishell);
	free(inner_content);
	result = ft_strjoin3("'", expanded_content, "'");
	free(temp);
	return (result);
}

char	*expand(char *str, t_data *minishell)
{
	char	*expanded;
	char	*special_case;
	int		len;

	special_case = handle_special_expand_cases(str);
	if (special_case)
		return (special_case);
	if (str[0] == '\'' && ft_strchr(str, '$'))
		return (process_single_quote_expansion(str, minishell));
	len = get_expanded_len(str, minishell);
	expanded = malloc(len + 10);
	if (!expanded)
		return (NULL);
	ft_memset(expanded, 0, len + 10);
	return (while_expand(str, expanded, minishell));
}
