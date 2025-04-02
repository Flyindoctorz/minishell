/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 00:06:29 by zakchouc          #+#    #+#             */
/*   Updated: 2025/04/02 19:26:03 by lmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
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

struct s_data;
struct s_lexer;
struct s_token;
struct s_parsing;
struct s_expand;
struct s_cmd_list;
struct s_env;
struct s_heredoc;

typedef struct s_data		t_data;
typedef struct s_lexer		t_lexer;
typedef struct s_token		t_token;
typedef struct s_parsing	t_parsing;
typedef struct s_expand		t_expand;
typedef struct s_cmd_list	t_cmd_list;
typedef struct s_heredoc	t_heredoc;

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

typedef enum token_type
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

# include "data.h"
# include "exec.h"
# include "lexer.h"
# include "readline.h"

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
