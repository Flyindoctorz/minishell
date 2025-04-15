/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 17:19:20 by lmokhtar          #+#    #+#             */
/*   Updated: 2025/04/15 19:00:02 by cgelgon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

# include <stdbool.h>
# include <sys/types.h>

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
}						t_error_num;

typedef enum e_token_type
{
	TOKEN_WORD,
	TOKEN_REDIR_IN,
	TOKEN_REDIR_OUT,
	TOKEN_APPEND,
	TOKEN_HEREDOC,
	TOKEN_PIPE,
	TOKEN_DOLLAR,
	TOKEN_QUOTES,
	TOKEN_DQUOTES,
	TOKEN_EXPAND,
	TOKEN_EOF,
	TOKEN_ERROR
}						t_token_type;

struct	s_data;
struct	s_lexer;
struct	s_token;
struct	s_cmd_list;
struct	s_env;
struct	s_heredoc;
struct	s_parsing;
struct	s_expand;
struct	s_quote_scan;

typedef struct s_env
{
	char				*key;
	char				*value;
	struct s_env		*next;
}						t_env;

typedef struct s_token
{
	t_token_type		toktype;
	char				*value;
	int					position;
	struct s_token		*next;
	t_token_type		shrinked;
}						t_token;

// Structure pour les heredocs
typedef struct s_heredoc
{
	char				*delimiter;
	int					fd;
	char				**content;
	bool				expand;
	t_token_type		type;
	struct s_heredoc	*next;
}						t_heredoc;

typedef struct s_cmd_list
{
	char				*cmd;
	char				**av;
	int					ac;
	char				*input_file;
	char				*output_file;
	char				*delimiter;
	int					fd_in;
	int					fd_out;
	bool				is_pipe;
	bool				append;
	bool				heredoc;
	int					pid;
	struct s_heredoc	*redir;
	struct s_cmd_list	*next;
}						t_cmd_list;

typedef struct s_lexer
{
	char				*input;
	size_t				input_len;
	int					pos;
	int					read_pos;
	char				curr_char;
	struct s_data		*data;
	struct s_token		*tokens;
	struct s_token		*curr_tok;
	int					token_count;
}						t_lexer;

typedef struct s_data
{
	int					ac;
	char				**av;
	char				**envp;
	char				*cwd;
	int					exit;
	int					nodenb;
	int					prev_pipe_read_end;
	struct s_token		*token;
	struct s_cmd_list	*command;
	struct s_env		*env;
	int					state;
	struct s_parsing	*parsing;
	char				*input;
	pid_t				pid;
	int					pipe_fd[2];
	int					last_exit_status;
	bool				is_child;
}						t_data;

typedef struct s_expand
{
	char				*content;
	char				*expanded;
	int					exit_code;
}						t_expand;

typedef struct s_parsing
{
	int					state;
	int					error_code;
}						t_parsing;

typedef struct s_quote_scan
{
	int					before_quote;
	int					inside_start_pos;
	int					len;
	char				quote_type;
}						t_quote_scan;

#endif
