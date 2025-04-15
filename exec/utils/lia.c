/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lia.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:43:22 by lmokhtar          #+#    #+#             */
/*   Updated: 2025/04/15 18:14:26 by lmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_redirclear(t_heredoc *redir)
{
	t_heredoc	*tmp;

	while (redir)
	{
		tmp = redir->next;
		free(redir->delimiter);
		free_tab(redir->content);
		free(redir);
		redir = tmp;
	}
}

char	*process_quoted_expansion(char *str, char *expanded, t_data *minishell)
{
	int		end_quote;
	char	*inner_content;
	char	*expanded_var;

	end_quote = 1;
	while (str[end_quote] && str[end_quote] != '\'')
		end_quote++;
	if (end_quote > 1)
		inner_content = ft_substr(str, 1, end_quote - 1);
	else
		inner_content = ft_substr(str, 1, 0);
	if (!inner_content)
		return (expanded);
	expanded_var = expand(inner_content, minishell);
	free(inner_content);
	if (!expanded_var)
		return (expanded);
	return (append_expanded_content(expanded_var, expanded, str, end_quote));
}

char	*append_expanded_content(char *expanded_var, char *expanded, char *str,
		int end_quote)
{
	int	i;

	ft_strncat(expanded, "'", 1);
	ft_strncat(expanded, expanded_var, ft_strlen(expanded_var));
	if (str[end_quote] == '\'')
		ft_strncat(expanded, "'", 1);
	free(expanded_var);
	i = end_quote;
	if (str[end_quote] == '\'')
		i = end_quote + 1;
	while (str[i])
	{
		ft_strncat(expanded, str + i, 1);
		i++;
	}
	return (expanded);
}

int	process_quotes(char *str, int *i, int *quote_index)
{
	if ((str[*i] == '\'' && *quote_index != 2) || (str[*i] == '"'
			&& *quote_index != 1))
	{
		*quote_index = change_quote(str[(*i)++], *quote_index);
		return (0);
	}
	return (1);
}

int	get_expanded_len(char *str, t_data *minishell)
{
	int	len;
	int	i;
	int	quote_index;

	len = 0;
	i = 0;
	quote_index = 0;
	if (str[0] == '\'' && ft_strchr(str + 1, '$'))
		len += 2;
	while (str[i])
	{
		if (!process_quotes(str, &i, &quote_index))
			continue ;
		len += process_char(str, &i, &quote_index, minishell);
	}
	return (len + 10);
}
