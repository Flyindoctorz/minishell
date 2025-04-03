/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 00:06:29 by zakchouc          #+#    #+#             */
/*   Updated: 2025/04/03 14:36:19 by cgelgon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include "data.h"
# include "exec.h"
# include "lexer.h"
# include "readline.h"
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <linux/limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <strings.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

/* ************************************************************************** */
/*                             ENUMÉRATIONS                                   */
/* ************************************************************************** */

// code ERRATUM
typedef enum e_error_num
{
	MNSHL_SUCCESS = 0,
	MNSHL_ERR_MEMORY, // 1
	MNSHL_ERR_ARGS,   // 2
	MNSHL_ERR_ENV,    // 3
	MNSHL_ERR_CWD,    // 4
	MNSHL_ERR_PIPE,   // 5
	MNSHL_ERR_FORK,   // 6
	MNSHL_ERR_EXEC,   // 7
	MNSHL_ERR_SYNTAX, // 8
	MNSHL_ERR_MAX     //
}							t_error_num;

// Types de tokens pour l'analyse lexicale
typedef enum e_token_type
{
	TOKEN_WORD,      //(words)
	TOKEN_REDIR_IN,  // <
	TOKEN_REDIR_OUT, // >
	TOKEN_APPEND,    // >>
	TOKEN_HEREDOC,   // <<
	TOKEN_PIPE,      // |
	TOKEN_DOLLAR,    //  $
	TOKEN_QUOTES,    // ''
	TOKEN_DQUOTES,   // ""
	TOKEN_EXPAND,    // $VAR
	TOKEN_EOF,       // calcule fin de l'input
	TOKEN_ERROR,     // gestion d'err + debug
}							t_token_type;

/* ************************************************************************** */
/*                          DÉCLARATIONS ANTICIPÉES                           */
/* ************************************************************************** */

/*// Déclarations anticipées des structures
struct s_data;
struct s_lexer;
struct s_token;
struct s_parsing;
struct s_expand;
struct s_cmd_list;
struct s_env;
struct s_heredoc;
*/
/* ************************************************************************** */
/*                          DÉFINITIONS DES STRUCTURES                        */
/* ************************************************************************** */

// Structure pour l'environnement
typedef struct s_env
{
	char					*key;
	char					*value;
	struct s_env			*next;
}							t_env;

// Structure principale pour les données du shell
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
}							t_data;

// Structure pour les tokens lexicaux
typedef struct s_token
{
	t_token_type toktype;  // Nature du token
	char *value;           // texte du TOK quel qu'il soit
	int position;          // Position dans l'input
	struct s_token *next;  // pointe vers next tok pour chainer
	t_token_type shrinked; // utile pour shrink des tokens
}							t_token;

// Structure pour l'analyseur lexical
typedef struct s_lexer
{
	char *input;       // chaine a analyser. conserve dans memoire
	size_t input_len;  // evite de strlen en boucle
	int pos;           // index dans input
	int read_pos;      // pos +1
	char curr_char;    // carac en court de lexique. 1 char
	t_data *data;      // env + donnes globales, cwd
	t_token *tokens;   // parcourt tout les token
	t_token *curr_tok; // token en court de manip
	int token_count;   // nombre de token
}							t_lexer;

// Structure pour les commandes
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
}							t_cmd_list;

// Structure pour les heredocs
typedef struct s_heredoc
{
	char *delimiter;        // Délimiteur
	int fd;                 // Descripteur de fichier
	char **content;         // Contenu collecté
	bool expand;            // Si l'expansion doit être effectuée
	t_token_type type;      // Type de redirection
	struct s_heredoc *next; // Prochain heredoc
}							t_heredoc;

// Structure pour l'expansion des variables
typedef struct s_expand
{
	char *content;  // Contenu original
	char *expanded; // Contenu après expansion
	int exit_code;  // Dernier code de sortie pour $?
}							t_expand;

// Structure pour le parsing (à compléter selon vos besoins)
typedef struct s_parsing
{
	// Ajoutez les champs nécessaires pour l'analyse syntaxique
	int dummy; // Placeholder
}							t_parsing;

/* ************************************************************************** */
/*                       TYPEDEFS DES STRUCTURES                              */
/* ************************************************************************** */

typedef struct s_data		t_data;
typedef struct s_lexer		t_lexer;
typedef struct s_token		t_token;
typedef struct s_parsing	t_parsing;
typedef struct s_expand		t_expand;
typedef struct s_cmd_list	t_cmd_list;
typedef struct s_env		t_env;
typedef struct s_heredoc	t_heredoc;

/* ************************************************************************** */
/*                       PROTOTYPES DE FONCTIONS GÉNÉRIQUES                   */
/* ************************************************************************** */

// Gestion des erreurs
void						handle_error(t_error_num code,
								const char *custom_message);
bool						print_test(char *test_name, bool test_result);

/* ************************************************************************** */
/*                       DÉFINITIONS DES MACROS                               */
/* ************************************************************************** */

// Messages d'erreur
# define ERR_MSG_MEMORY "Memory allocation failed"
# define ERR_MSG_ARGS "Invalid arguments"
# define ERR_MSG_ENV "Environment error"
# define ERR_MSG_CWD "Cannot access current working directory"
# define ERR_MSG_PIPE "Pipe creation failed"
# define ERR_MSG_FORK "Process creation failed"
# define ERR_MSG_EXEC "Command execution failed"
# define ERR_MSG_SYNTAX "Syntax error"
# define ERR_MSG_PIPE_SYNTAX "Syntax error : missing command after pipe"
# define ERR_MSG_REDIR_SYNTAX "Syntax error : missing file after redirection"
# define ERR_MSG_QUOTE_SYNTAX "Syntax error : unterminated quote"
# define ERR_MSG_CONSEC_SYNTAX "Syntax error : consecutive operators"

#endif