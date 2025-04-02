/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:14:04 by cgelgon           #+#    #+#             */
/*   Updated: 2025/04/02 17:52:50 by lmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static const char	*error_messages[] = {[MNSHL_SUCCESS] = "Success",
		[MNSHL_ERR_MEMORY] = ERR_MSG_MEMORY, [MNSHL_ERR_ARGS] = ERR_MSG_ARGS,
		[MNSHL_ERR_ENV] = ERR_MSG_ENV, [MNSHL_ERR_CWD] = ERR_MSG_CWD,
		[MNSHL_ERR_PIPE] = ERR_MSG_PIPE, [MNSHL_ERR_FORK] = ERR_MSG_FORK,
		[MNSHL_ERR_EXEC] = ERR_MSG_EXEC, [MNSHL_ERR_SYNTAX] = ERR_MSG_SYNTAX};

void	handle_error(t_error_num code, const char *custom_message)
{
	const char	*error_msg = "Unknown error";

	if (code >= 0 && code < MNSHL_ERR_MAX)
	{
		error_msg = error_messages[code];
	}
	if (custom_message)
		printf("Erreur : %s\n", custom_message);
	else
		printf("Erreur : %s\n", error_msg);
}

bool	print_test(char *test_name, bool test_result)
{
	if (test_result)
		printf("%-20s: \033[0;32mOK\033[0m\n", test_name);
	else
		printf("%-20s: \033[0;31mKO\033[0m\n", test_name);
	return (test_result);
}
