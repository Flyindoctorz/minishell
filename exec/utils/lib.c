/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:43:36 by lmokhtar          #+#    #+#             */
/*   Updated: 2025/04/15 18:14:56 by lmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*ft_strjoin3(char *s1, char *s2, char *s3)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	s3_len;
	char	*ret;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	s3_len = ft_strlen(s3);
	ret = malloc(s1_len + s2_len + s3_len + 1);
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, s1, s1_len + 1);
	ft_strlcpy(ret + s1_len, s2, s2_len + 1);
	ft_strlcpy(ret + s1_len + s2_len, s3, s3_len + 1);
	return (ret);
}

static int	word_count(char const *s, char c)
{
	int	count;
	int	on_word;

	count = 0;
	on_word = 0;
	while (*s)
	{
		if (*s == c)
		{
			if (on_word)
			{
				count++;
				on_word = 0;
			}
		}
		else
			on_word = 1;
		s++;
	}
	return (count + on_word);
}

static char	*copy_next_word(char const *s, char c, int *i)
{
	char	*word;
	int		tmp;
	int		j;

	while (s[*i] && s[*i] == c)
		(*i)++;
	tmp = *i;
	while (s[*i] && s[*i] != c)
		(*i)++;
	word = malloc((*i - tmp + 1) * sizeof(char));
	if (!word)
		return (NULL);
	j = 0;
	while (j < *i - tmp)
	{
		word[j] = s[tmp + j];
		j++;
	}
	word[j] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		words;
	int		word;
	int		i;

	if (!s)
		return (NULL);
	words = word_count(s, c);
	split = malloc((words + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	i = 0;
	word = 0;
	while (word < words)
	{
		split[word] = copy_next_word(s, c, &i);
		if (!split[word])
			return (free_tab(split), NULL);
		word++;
	}
	split[words] = NULL;
	return (split);
}

bool	is_in_int_range(char *str)
{
	long long	value;
	int			sign;
	int			i;

	value = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (ft_isnum(str[i]))
	{
		if (value > INT_MAX / 10)
			return (false);
		value = value * 10 + (str[i] - '0');
		if ((sign == 1 && value > INT_MAX) || (sign == -1 && value
				* sign < INT_MIN))
			return (false);
		i++;
	}
	return (true);
}
