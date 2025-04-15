/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 02:23:04 by lmokhtar          #+#    #+#             */
/*   Updated: 2025/04/15 16:19:31 by lmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

bool	export_rule(char *str)
{
	int		i;
	char	*equals_pos;

	i = 0;
	equals_pos = ft_strchr(str, '=');
	if (!ft_isalpha(str[0]) && str[0] != '_')
		return (false);
	while (str[i] && (equals_pos == NULL || &str[i] < equals_pos))
	{
		if (!ft_isalnum(str[i]) && str[i] != '_' && str[i] != '-')
			return (false);
		i++;
	}
	return (true);
}

void	export_create(t_data *minishell, char *arg)
{
	t_env	*new;
	char	*key;
	char	*value;

	if (ft_strchr(arg, '='))
	{
		key = get_key(arg);
		value = get_value(arg);
		new = ft_envnew(key, value);
	}
	else
	{
		if (search_env(minishell->env, arg))
			return ;
		key = ft_strdup(arg);
		new = ft_envnew(key, NULL);
	}
	if (!search_env(minishell->env, key))
		ft_envaddback(&minishell->env, new);
	else
	{
		free(new);
		modify_value(minishell->env, key, value);
	}
}

static void	handle_joined_args(char **arg, int *i, char **full_arg)
{
	if (arg[*i][ft_strlen(arg[*i]) - 1] == '=' && arg[*i + 1])
	{
		*full_arg = ft_strjoin3(arg[*i], "", arg[*i + 1]);
		if (*full_arg)
			(*i)++;
	}
	else
		*full_arg = arg[*i];
}

static void	process_export_arg(t_data *minishell, char **arg, int *i)
{
	char	*full_arg;

	full_arg = NULL;
	handle_joined_args(arg, i, &full_arg);
	if (!export_rule(full_arg))
	{
		printf("bash: export: `%s': not a valid identifier\n", full_arg);
		minishell->state = 1;
	}
	else
		export_create(minishell, full_arg);
	if (full_arg != arg[*i] && full_arg != arg[*i - 1])
		free(full_arg);
	(*i)++;
}

int	ft_export(t_data *minishell, char **arg)
{
	int	i;

	minishell->state = 0;
	if (!arg[1])
	{
		export_print(minishell->env);
		return (minishell->state);
	}
	i = 1;
	while (arg[i])
		process_export_arg(minishell, arg, &i);
	update_envp_array(minishell);
	return (minishell->state);
}
