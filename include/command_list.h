/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_list.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 13:56:14 by cgelgon           #+#    #+#             */
/*   Updated: 2025/04/02 17:53:18 by lmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_LIST_H
# define COMMAND_LIST_H

# include "heredoc.h"
# include "minishell.h"

typedef struct s_cmd_list
{
	char *cmd;               // Nom de la commande
	char **av;               // Arguments (incluant la commande)
	int ac;                  // Nombre d'arguments
	char *input_file;        // Fichier d'entrée si redirection <
	char *output_file;       // Fichier de sortie si redirection >
	char *delimiter;         // Délimiteur pour heredoc si
	int fd_in;               // FD pour redirection entrée
	int fd_out;              // FD pour redirection sortie
	bool is_pipe;            // Indicateur de pipe
	bool append;             // Indicateur pour >>
	bool heredoc;            // Indicateur pour
	int pid;                 // PID du processus
	struct s_heredoc *redir; // Liste chaînée des redirections
	struct s_cmd_list *next; // Commande suivante
}	t_cmd_list;

#endif