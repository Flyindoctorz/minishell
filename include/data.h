/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:53:16 by cgelgon           #+#    #+#             */
/*   Updated: 2025/04/02 18:21:59 by lmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include "minishell.h"

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}					t_env;

typedef struct s_data
{
	int ac;                 // Gère les arguments passés au shell.
	char **av;              // Gère les arguments passés au shell.
	char **envp;            // Contient les variables d'environnement globales.
	char *cwd;              // Suit le répertoire de travail actuel.
	int exit;               // Stocke le code de sortie de la dernière commande.
	int nodenb;             // Suit le nombre de nœuds (commandes ou opérateurs)
	int prev_pipe_read_end; // Facilite la gestion des pipelines (|).
	t_token *token;         // For tokenized input
	t_cmd_list *command;    // For parsed commands
	t_env *env;             // Liste chaînée des variables d'environnement
	int state;              // For shell state
	t_parsing *parsing;     // État actuel du parsing
	char *input;            // Input brut de l'utilisateur
	pid_t pid;              // Process ID for command execution
	int pipe_fd[2];         // Pipe file descriptors
	int last_exit_status;   // Last command exit status
	bool is_child;          // Flag to indicate if current process is a child
}					t_data;

int					init_environment(t_data *data, char **envp);
int					init_working_directory(t_data *data);
t_data				*init_data(int ac, char **av, char **envp);
char				**dup_env(char **envp);
char				*init_cwd(void);
// cleanup functions
void				free_env(char **env);
void				free_data(t_data *data);

#endif
