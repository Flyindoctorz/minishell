#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"

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
extern volatile sig_atomic_t g_signal;

#endif
