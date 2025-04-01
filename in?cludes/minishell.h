/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 02:22:04 by lmokhtar          #+#    #+#             */
/*   Updated: 2025/03/31 18:17:53 by lmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <dirent.h>
# include <fcntl.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <termios.h>
# include <unistd.h>

# include "string_utils.h"
# include "env_utils.h"
# include "data.h"
# include "lexer.h"
# include "readline.h"

// token
extern volatile sig_atomic_t	g_signal;

typedef enum e_token_type
{
	WORD,
	REDIR,
	PIPE,
}								t_token_type;

typedef struct s_token
{
	char						*str;
	t_token_type				type;
	struct s_token				*next;
}								t_token;

// command

typedef enum e_redir_type
{
	IN,
	OUT,
	HEREDOC,
	APPEND,
}								t_redir_type;

typedef struct s_redir
{
	char						*file;
	t_redir_type				type;
	char						**heredoc_content;
	struct s_redir				*next;
}								t_redir;

typedef struct s_command
{
	char						**arguments;
	t_redir						*redir;
	struct s_command			*next;
	int							pid;
}								t_command;

// env

typedef struct s_env
{
	char						*key;
	char						*value;
	struct s_env				*next;
}								t_env;

// minishell

typedef struct s_data
{
	t_env						*env;
	t_token						*token;
	t_command					*command;
	char						**envp;
	int							state;
}								t_data;

// exec

bool							is_a_builtin(char **arg);

bool							exec(t_command *cmd, t_data *minishell);

int								builtins(t_data *minishell, t_command *cmd);

int								open_redirections(t_command *cmd,
									t_data *minishell);

int								ft_cd(t_data *minishell, char **arg);

int								ft_echo(t_data *minishell, char **arg);

int								good_flag(const char *str);

int								ft_env(t_data *minishell, char **arg);

int								ft_exit(t_data *minishell, char **arg);

int								ft_export(t_data *minishell, char **arg);

void							export_create(t_data *minishell, char *arg);

int								ft_pwd(t_data *minishell, char **arg);

int								ft_unset(t_data *minishell, char **arg);

void							ft_end(t_data *minishell);

// pipe

void							excute(char **cmd, char **env,
									t_data *minishell);

void							ft_tabupdate(t_data *minishell);

void							error_msg(char *path, char **cmd,
									t_data *minishell);

char							*cmd_finder(char **cmd, char **env);

// utils

void							ft_signal(void);

bool							print_test(char *test_name, bool test_result);

#endif