/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cmd_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 12:43:10 by cgelgon           #+#    #+#             */
/*   Updated: 2025/04/09 19:43:00 by lmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// Initialise une nouvelle structure de commande
t_cmd_list	*init_cmd_list(void)
{
	t_cmd_list	*cmd;

	cmd = (t_cmd_list *)malloc(sizeof(t_cmd_list));
	if (!cmd)
		return (NULL);
	cmd->cmd = NULL;
	cmd->av = NULL;
	cmd->ac = 0;
	cmd->input_file = NULL;
	cmd->output_file = NULL;
	cmd->delimiter = NULL;
	cmd->fd_in = STDIN_FILENO;
	cmd->fd_out = STDOUT_FILENO;
	cmd->is_pipe = false;
	cmd->append = false;
	cmd->heredoc = false;
	cmd->pid = 0;
	cmd->redir = NULL;
	cmd->next = NULL;
	return (cmd);
}

// Ajoute un mot (commande ou argument) à la commande
void	add_word_to_cmd(t_cmd_list *cmd, char *word)
{
	char	**new_av;
	int		i;

	if (!cmd || !word)
		return ;
	if (!cmd->cmd)
	{
		cmd->cmd = ft_strdup(word);
		if (!cmd->cmd)
			return ;
	}
	new_av = (char **)malloc(sizeof(char *) * (cmd->ac + 2));
	if (!new_av)
		return ;
	i = -1;
	while (++i < cmd->ac)
		new_av[i] = cmd->av[i];
	new_av[i] = ft_strdup(word);
	if (!new_av[i])
		return (free(new_av), (void)0);
	new_av[i + 1] = NULL;
	if (cmd->av)
		free(cmd->av);
	cmd->av = new_av;
	cmd->ac++;
}

// Gère la création d'une nouvelle commande après un pipe
t_cmd_list	*handle_pipe(t_cmd_list *cmd)
{
	t_cmd_list	*new_cmd;

	if (!cmd)
		return (NULL);
	new_cmd = init_cmd_list();
	if (!new_cmd)
		return (NULL);
	cmd->is_pipe = true;
	cmd->next = new_cmd;
	return (new_cmd);
}
