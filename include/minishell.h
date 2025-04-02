/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 00:06:29 by zakchouc          #+#    #+#             */
/*   Updated: 2025/04/02 15:04:50 by cgelgon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

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
# include "../libft/libft.h"

typedef struct s_env {
    char *key;
    char *value;
    struct s_env *next;
} t_env;

struct					s_data;
struct						s_lexer;
struct						s_token;
struct						s_parsing;
struct						s_expand;
struct						s_cmd_list;
struct						s_env;
struct						s_heredoc;

typedef struct s_data		t_data;
typedef struct s_lexer		t_lexer;
typedef struct s_token		t_token;
typedef struct s_parsing	t_parsing;
typedef struct s_expand		t_expand;
typedef struct s_cmd_list	t_cmd_list;
typedef struct s_env		t_env;
typedef struct s_heredoc	t_heredoc;

typedef enum e_redir_type
{
    IN,
    OUT,
    HEREDOC,
    APPEND,
} t_redir_type;

typedef struct s_redir
{
    char            *file;
    t_redir_type    type;
    char            **heredoc_content;
    struct s_redir  *next;
} t_redir;

//code ERRATUM
typedef enum e_error_num
{
    MNSHL_SUCCESS = 0,  
    MNSHL_ERR_MEMORY,   // 1
    MNSHL_ERR_ARGS,     // 2
    MNSHL_ERR_ENV,      // 3
    MNSHL_ERR_CWD,      // 4
    MNSHL_ERR_PIPE,     // 5
    MNSHL_ERR_FORK,     // 6
    MNSHL_ERR_EXEC,     // 7
	MNSHL_ERR_SYNTAX,   // 8
    MNSHL_ERR_MAX       //
} t_error_num;

//Messages d'erreur
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

void    handle_error(t_error_num, const char *custom_msg);
bool	print_test(char *test_name, bool test_result);
char	*expand(char *str, t_data *minishell);
void    ft_envaddback(t_env **head, t_env *new);
t_env   *ft_envnew(char *key, char *value);
t_env   *ft_envlast(t_env *head);
void    ft_envclear(t_env **env);
# include "data.h"
# include "lexer.h"
# include "readline.h"
# include "parser.h"


#endif
