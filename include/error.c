/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:14:04 by cgelgon           #+#    #+#             */
/*   Updated: 2025/04/15 18:34:54 by lmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"
#include "minishell.h"

const char	*error_messages(t_error_num code)
{
	static const char	*messages[MNSHL_ERR_MAX];
	static bool			initialized;

	if (!initialized)
	{
		messages[MNSHL_SUCCESS] = "Success";
		messages[MNSHL_ERR_MEMORY] = ERR_MSG_MEMORY;
		messages[MNSHL_ERR_ARGS] = ERR_MSG_ARGS;
		messages[MNSHL_ERR_ENV] = ERR_MSG_ENV;
		messages[MNSHL_ERR_CWD] = ERR_MSG_CWD;
		messages[MNSHL_ERR_PIPE] = ERR_MSG_PIPE;
		messages[MNSHL_ERR_FORK] = ERR_MSG_FORK;
		messages[MNSHL_ERR_EXEC] = ERR_MSG_EXEC;
		messages[MNSHL_ERR_SYNTAX] = ERR_MSG_SYNTAX;
		initialized = true;
	}
	if (code >= 0 && code < MNSHL_ERR_MAX && messages[code])
		return (messages[code]);
	return ("Unknown error");
}

void	handle_error(t_error_num code, const char *custom_message)
{
	const char	*message_err = "Unknown error";

	if (code >= 0 && code < MNSHL_ERR_MAX)
	{
		message_err = error_messages(code);
	}
	if (custom_message)
		printf("Erreur : %s\n", custom_message);
	else
		printf("Erreur : %s\n", message_err);
}

bool	print_test(char *test_name, bool test_result)
{
	if (test_result)
		printf("%-20s: \033[0;32mOK\033[0m\n", test_name);
	else
		printf("%-20s: \033[0;31mKO\033[0m\n", test_name);
	return (test_result);
}
