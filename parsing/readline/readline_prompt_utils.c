/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_prompt_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:06:06 by cgelgon           #+#    #+#             */
/*   Updated: 2025/04/08 15:05:34 by lmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// char	*get_current_directory(t_data *data, int *needs_free)
// {
// 	char	*cwd;

// 	*needs_free = 0;
// 	cwd = data->cwd;
// 	if (!cwd)
// 	{
// 		cwd = getcwd(NULL, 0);
// 		*needs_free = 1;
// 	}
// 	return (cwd);
// }

// char	*get_username(void)
// {
// 	char	*username;

// 	username = getenv("USER");
// 	if (!username)
// 		username = "user";
// 	return (username);
// }

// char	*create_prompt_base(char *username)
// {
// 	char	*prompt;

// 	prompt = ft_strjoin(username, "@minishell:");
// 	if (!prompt)
// 		return (ft_strdup("minishell>"));
// 	return (prompt);
// }

// char	*add_path_to_prompt(char *prompt, char *cwd)
// {
// 	char	*result;

// 	if (!cwd || !prompt)
// 		return (prompt);
// 	result = ft_strjoin(prompt, cwd);
// 	free(prompt);
// 	if (!result)
// 		return (ft_strdup("minishell>"));
// 	return (result);
// }

// char	*create_prompt_prefix(t_data *data)
// {
// 	char	*cwd;
// 	char	*username;
// 	char	*prompt;
// 	int		needs_free;

// 	cwd = get_current_directory(data, &needs_free);
// 	username = get_username();
// 	prompt = create_prompt_base(username);
// 	prompt = add_path_to_prompt(prompt, cwd);
// 	if (needs_free && cwd)
// 		free(cwd);
// 	return (prompt);
// }
