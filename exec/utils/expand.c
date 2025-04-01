/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:30:00 by lmokhtar          #+#    #+#             */
/*   Updated: 2025/04/01 14:09:13 by lmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static size_t	get_max_var_len(char **envp)
{
	size_t	i;
	size_t	max_len;
	size_t	curr_len;

	max_len = 0;
	if (!envp)
		return (max_len);
	i = 0;
	while (envp[i])
	{
		curr_len = ft_strlen(envp[i]);
		if (curr_len > max_len)
			max_len = curr_len;
		i++;
	}
	return (max_len);
}

static char	*get_env_value(char **envp, char *key)
{
	size_t	i;
	size_t	key_len;
	char	*env_entry;

	if (!envp || !key)
		return (NULL);
	key_len = ft_strlen(key);
	i = 0;
	while (envp[i])
	{
		env_entry = envp[i];
		if (ft_strncmp(env_entry, key, key_len) == 0 && env_entry[key_len] == '=')
			return (env_entry + key_len + 1);
		i++;
	}
	return (NULL);
}

static char	*handle_special_vars(char *var, t_data *minishell)
{
	if (ft_strcmp(var, "?") == 0)
		return (ft_itoa(minishell->exit));
	return (NULL);
}

static char	*expand_var(char *str, size_t *i, t_data *minishell)
{
	char	*var_name;
	char	*value;
	size_t	start;

	start = *i;
	while (str[*i] && (ft_isalnum(str[*i]) || str[*i] == '_'))
		(*i)++;
	var_name = ft_substr(str, start, *i - start);
	if (!var_name)
		return (NULL);
	value = handle_special_vars(var_name, minishell);
	if (!value)
		value = get_env_value(minishell->envp, var_name);
	free(var_name);
	return (value);
}

static void	copy_expanded_var(char *result, char *tmp, size_t *j, size_t max_size)
{
	size_t	tmp_len;

	if (tmp)
	{
		tmp_len = ft_strlen(tmp);
		if (*j + tmp_len < max_size)
		{
			ft_strcpy(result + *j, tmp);
			*j += tmp_len;
		}
	}
}

static void	handle_dollar_sign(char *str, size_t *i, char **tmp, t_data *minishell)
{
	if (str[*i] == '$' && (ft_isalpha(str[*i + 1]) || 
		str[*i + 1] == '_' || str[*i + 1] == '?'))
	{
		(*i)++;
		*tmp = expand_var(str, i, minishell);
	}
}

char	*expand(char *str, t_data *minishell)
{
	char	*result;
	char	*tmp;
	size_t	i;
	size_t	j;
	size_t	max_size;
	size_t	max_var_len;

	if (!str)
		return (NULL);
	max_var_len = get_max_var_len(minishell->envp);
	max_size = ft_strlen(str) + (max_var_len * 10) + 1; /* Allocate enough for multiple expansions */
	result = malloc(max_size);
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		tmp = NULL;
		handle_dollar_sign(str, &i, &tmp, minishell);
		if (tmp)
			copy_expanded_var(result, tmp, &j, max_size);
		else if (j < max_size - 1)
			result[j++] = str[i++];
	}
	if (j < max_size)
		result[j] = '\0';
	else if (max_size > 0)
		result[max_size - 1] = '\0';
	return (result);
}

#ifdef TEST
// Simplified test data initialization for testing only
static t_data *init_test_data(int ac, char **av, char **envp) {
    t_data *data = malloc(sizeof(t_data));
    if (!data)
        return NULL;
    data->ac = ac;
    data->av = av;
    data->envp = envp;
    data->exit = 0;
    data->cwd = NULL;
    data->nodenb = 0;
    data->prev_pipe_read_end = -1;
    data->token = NULL;
    data->command = NULL;
    data->state = 0;
    data->env = NULL;
    data->parsing = NULL;
    data->input = NULL;
    return data;
}

// Simplified cleanup for testing only
static void free_test_data(t_data *data) {
    if (!data)
        return;
    // Don't free envp as it's owned by the system
    if (data->token)
        ft_tokenclear(&data->token);
    if (data->command)
        ft_commandclear(&data->command);
    if (data->env)
        ft_envclear(&data->env);
    if (data->parsing)
        free(data->parsing);
    if (data->input)
        free(data->input);
    free(data);
}

int main(int ac, char **av, char **envp) {
    t_data *data;
    char *expanded;
    char *test_str;

    data = init_test_data(ac, av, envp);
    if (!data)
        return 1;

    // Test basic variable expansion
    test_str = "$PATH";
    expanded = expand(test_str, data);
    printf("Original: %s\nExpanded: %s\n\n", test_str, expanded);
    free(expanded);	

    // Test special variable
    test_str = "$?";
    expanded = expand(test_str, data);
    printf("Original: %s\nExpanded: %s\n\n", test_str, expanded);
    free(expanded);

    // Test mixed content
    test_str = "Hello $USER world";
    expanded = expand(test_str, data);
    printf("Original: %s\nExpanded: %s\n\n", test_str, expanded);
    free(expanded);

    free_test_data(data);
    return 0;
}
#endif


