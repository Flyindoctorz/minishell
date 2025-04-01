#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"

typedef struct s_redir {
    int type;
    char *file;
    char **heredoc_content;
    struct s_redir *next;
} t_redir;

typedef struct s_command {
    char **arguments;
    t_redir *redir;
    pid_t pid;
    struct s_command *next;
} t_command;

// Alias t_command as t_cmd_list for compatibility
typedef t_command t_cmd_list;

// Parser function declarations
t_cmd_list *parse_tokens(t_token *tokens, t_data *data);
void ft_tokenclear(t_token **token);
void ft_commandclear(t_cmd_list **cmd);
void ft_redirclear(t_redir *redir);
void ft_end(t_data *minishell);
void ft_signal(void);
bool exec(t_cmd_list *cmd, t_data *minishell);

// Built-in function declarations
int ft_cd(t_data *minishell, char **arg);
int ft_echo(t_data *minishell, char **arg);
int ft_env(t_data *minishell, char **arg);
int ft_export(t_data *minishell, char **arg);
int ft_pwd(t_data *minishell, char **arg);
int ft_unset(t_data *minishell, char **arg);
int ft_exit(t_data *minishell, char **arg);

// Command utilities
t_command *ft_commandnew(char **tab, t_redir *redir);
void ft_commandaddback(t_command **head, t_command *new);
t_command *ft_commandlast(t_command *head);

// Redirection utilities
int open_redirections(t_command *cmd, t_data *minishell);
void free_all_heredoc(t_command *cmd);

// Signal handling
void set_signal_child(void);
extern int g_signal;

#endif
