/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:58:19 by cgelgon           #+#    #+#             */
/*   Updated: 2025/04/03 14:58:22 by cgelgon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include <stdbool.h>
# include <sys/types.h>

// Énumérations
typedef enum e_error_num
{
    MNSHL_SUCCESS = 0,
    MNSHL_ERR_MEMORY,
    MNSHL_ERR_ARGS,
    MNSHL_ERR_ENV,
    MNSHL_ERR_CWD,
    MNSHL_ERR_PIPE,
    MNSHL_ERR_FORK,
    MNSHL_ERR_EXEC,
    MNSHL_ERR_SYNTAX,
    MNSHL_ERR_MAX
}   t_error_num;

typedef enum e_token_type
{
    TOKEN_WORD,      // Mots
    TOKEN_REDIR_IN,  // <
    TOKEN_REDIR_OUT, // >
    TOKEN_APPEND,    // >>
    TOKEN_HEREDOC,   // <<
    TOKEN_PIPE,      // |
    TOKEN_DOLLAR,    // $
    TOKEN_QUOTES,    // ''
    TOKEN_DQUOTES,   // ""
    TOKEN_EXPAND,    // $VAR
    TOKEN_EOF,       // Fin de l'input
    TOKEN_ERROR      // Gestion d'erreurs
}   t_token_type;

// Déclarations anticipées des structures
struct s_data;
struct s_lexer;
struct s_token;
struct s_cmd_list;
struct s_env;
struct s_heredoc;
struct s_parsing;
struct s_expand;

// Structure pour l'environnement
typedef struct s_env
{
    char            *key;
    char            *value;
    struct s_env    *next;
}   t_env;

// Structure pour les tokens
typedef struct s_token
{
    t_token_type    toktype;      // Nature du token
    char            *value;       // Texte du token
    int             position;     // Position dans l'input
    struct s_token  *next;        // Chaînage des tokens
    t_token_type    shrinked;     // Pour le shrinking des tokens
}   t_token;

// Structure pour les heredocs
typedef struct s_heredoc
{
    char            *delimiter;   // Délimiteur
    int             fd;           // Descripteur de fichier
    char            **content;    // Contenu collecté
    bool            expand;       // Si expansion nécessaire
    t_token_type    type;         // Type de redirection
    struct s_heredoc *next;       // Prochain heredoc
}   t_heredoc;

// Structure pour la liste de commandes
typedef struct s_cmd_list
{
    char            *cmd;         // Nom de la commande
    char            **av;         // Arguments
    int             ac;           // Nombre d'arguments
    char            *input_file;  // Fichier d'entrée
    char            *output_file; // Fichier de sortie
    char            *delimiter;   // Délimiteur heredoc
    int             fd_in;        // FD entrée
    int             fd_out;       // FD sortie
    bool            is_pipe;      // Indicateur de pipe
    bool            append;       // Indicateur append
    bool            heredoc;      // Indicateur heredoc
    int             pid;          // PID du processus
    struct s_heredoc *redir;      // Redirections
    struct s_cmd_list *next;      // Commande suivante
}   t_cmd_list;

// Structure pour le lexer
typedef struct s_lexer
{
    char            *input;       // Chaîne à analyser
    size_t          input_len;    // Évite strlen en boucle
    int             pos;          // Index dans l'input
    int             read_pos;     // pos + 1
    char            curr_char;    // Caractère courant
    struct s_data   *data;        // Données globales
    struct s_token  *tokens;      // Liste des tokens
    struct s_token  *curr_tok;    // Token courant
    int             token_count;  // Nombre de tokens
}   t_lexer;

// Structure principale des données du shell
typedef struct s_data
{
    int             ac;                 // Arguments passés au shell
    char            **av;               // Arguments
    char            **envp;             // Variables d'environnement
    char            *cwd;               // Répertoire de travail actuel
    int             exit;               // Code de sortie de la dernière commande
    int             nodenb;             // Nombre de nœuds
    int             prev_pipe_read_end; // Gestion des pipelines
    struct s_token  *token;             // Tokens d'entrée
    struct s_cmd_list *command;         // Liste de commandes parsées
    struct s_env    *env;               // Variables d'environnement (liste chaînée)
    int             state;              // État du shell
    struct s_parsing *parsing;          // État du parsing
    char            *input;             // Entrée brute
    pid_t           pid;                // ID de processus
    int             pipe_fd[2];         // Descripteurs de pipe
    int             last_exit_status;   // Dernier code de sortie
    bool            is_child;           // Indicateur de processus enfant
}   t_data;

// Structure pour l'expansion
typedef struct s_expand
{
    char            *content;     // Contenu original
    char            *expanded;    // Contenu après expansion
    int             exit_code;    // Dernier code de sortie
}   t_expand;

// Structure de parsing
typedef struct s_parsing
{
    // Détails du parsing à ajouter selon les besoins spécifiques
    int             state;        // État du parsing
    int             error_code;   // Code d'erreur de parsing
}   t_parsing;

#endif // STRUCTURES_H