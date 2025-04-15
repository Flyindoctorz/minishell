/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:57:04 by lmokhtar          #+#    #+#             */
/*   Updated: 2025/04/15 16:21:48 by lmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "structure.h"

int			exec_builtins(t_data *minishell, char **arg);
int			builtins(t_data *minishell, t_cmd_list *cmd);
bool		is_a_builtin(char **arg);
void		execut_me(t_cmd_list *cmd, t_data *shell, int save[2], int fd[2]);
int			all_cmd(t_data *minishell, int save[2], t_cmd_list *cmd);
void		check_signal_exec(t_data *minishell);
void		waiter(t_cmd_list *cmd, t_data *minishell);
bool		exec(t_cmd_list *cmd, t_data *minishell);

void		excute(char **cmd, char **env, t_data *minishell);
char		*cmd_finder(char **cmd, char **env);
void		error_msg(char *path, char **cmd, t_data *minishell);
void		end_exec(char *path, char **cmd, char **env, t_data *minishell);

void		open_input(t_heredoc *redir, t_data *minishell);
void		open_output(t_heredoc *redir, t_data *minishell);
void		open_heredoc(t_heredoc *redir, t_data *minishell);
void		free_all_heredoc(t_cmd_list *cmd);
int			open_redirections(t_cmd_list *cmd, t_data *minishell);
char		*process_quoted_expansion(char *str, char *expanded,
				t_data *minishell);
char		*append_expanded_content(char *expanded_var, char *expanded,
				char *str, int end_quote);
char		*handle_special_expand_cases(char *str);
int			get_expanded_len(char *str, t_data *minishell);
int			process_char(char *str, int *i, int *quote_index,
				t_data *minishell);
bool		is_in_int_range(char *str);
void		fill_envp_array(t_data *minishell);
void		update_envp_array(t_data *minishell);
char		*create_env_string(t_env *env);
void		setup_heredoc_signals(void);
void		restore_default_signals(void);

void		set_signal_child(void);
int			sig_event(void);
void		signal_handler(int sig);
void		ft_signal(void);
void		handle_heredoc_signal(int sig);
void		setup_heredoc_signals(void);
void		restore_default_signals(void);

int			ft_cd(t_data *minishell, char **arg);
int			ft_echo(t_data *minishell, char **arg);
int			ft_env(t_data *minishell, char **arg);
int			ft_export(t_data *minishell, char **arg);
int			ft_pwd(t_data *minishell, char **arg);
int			ft_unset(t_data *minishell, char **arg);
char		*trim_spaces(char *str);
int			ft_exit(t_data *minishell, char **arg);
void		ft_tabupdate(t_data *minishell);
int			ft_colon(t_data *minishell, char **arg);
int			ft_negate(t_data *minishell, char **arg);

void		ft_commandaddback(t_cmd_list **head, t_cmd_list *new);
t_cmd_list	*ft_commandnew(char **tab, t_heredoc *redir);
t_cmd_list	*ft_commandlast(t_cmd_list *head);
void		ft_commandclear(t_cmd_list **cmd);

char		*get_value(char *str);
// bool							ft_isalpha1(char c);
// bool							ft_isalnum(char c);
bool		ft_isnum(char c);
bool		is_env_valid(char c, bool start);

void		ft_envaddback(t_env **head, t_env *new);
t_env		*ft_envnew(char *key, char *value);
t_env		*ft_envlast(t_env *head);
void		ft_envclear(t_env **env);
bool		init_env(char **env, t_data *minishell);

int			search_env(t_env *env, char *key);
void		export_print(t_env *env);
void		modify_value(t_env *env, char *key, char *value);
char		*get_key(char *str);

int			get_heredoc(t_heredoc *redir, t_data *minishell);
void		ft_rediraddback(t_heredoc **head, t_heredoc *new);
t_heredoc	*ft_redirnew(char *str, t_token_type type, t_data *minishell);
t_heredoc	*ft_redirlast(t_heredoc *head);
void		ft_redirclear(t_heredoc *redir);

void		ft_strncat(char *dst, const char *src, size_t size);
void		*ft_memset(void *s, int c, size_t n);
void		ft_putstr_fd(char *str, int fd);
char		*ft_strjoin3(char *s1, char *s2, char *s3);
char		**ft_split(char const *s, char c);

int			ft_isspace(char c);
void		*ft_calloc(size_t n, size_t s);
char		*ft_itoa(int n);
void		ft_putendl_fd(char *s, int fd);

void		free_tab(char **tab);
void		print_tab(char **tab);
int			tab_len(char **tab);
char		**add_argument(char **tab, char *arg);

void		ft_tokenaddback(t_token **head, t_token *new);
// t_token							*ft_tokennew(char *str, t_token_type type);
t_token		*ft_tokenlast(t_token *head);
void		ft_tokenclear(t_token **token);
void		ft_end(t_data *minishell);

void		remove_first(t_env **env);
void		remove_last(t_env *env);
void		remove_node(t_env *env, char *to_delete);
void		free_node(t_env *env);
int			count_env(t_env *env);

int			change_quote(char quote, int i);
int			get_value_len(char *key, t_env *env);
char		*get_value_env(char *key, t_env *env);
int			get_env_size(char *str, int *i, t_data *minishell);
int			get_expanded_len(char *str, t_data *minishell);
void		get_env_value(char *str, char *expanded, int *i, t_data *minishell);
void		if_expand(t_data *minishell, char *expanded, int *i);
char		*while_expand(char *str, char *expanded, t_data *minishell);
char		*expand(char *str, t_data *minishell);
void		update_envp_array(t_data *minishell);

bool		is_in_int_range(char *str);
bool		is_valid_exit(char *str);

#endif