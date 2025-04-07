/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:05:49 by cgelgon           #+#    #+#             */
/*   Updated: 2025/04/07 16:14:05 by lmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READLINE_H
# define READLINE_H

# include <structure.h>

// gestion du signal
int		get_signal_status(void);
void	setup_signal(void);
void	reset_sig_to_default(void);
// prompt utils
char	*get_current_directory(t_data *data, int *needs_free);
char	*get_username(void);
char	*create_prompt_base(char *username);
char	*add_path_to_prompt(char *prompt, char *cwd);
char	*create_prompt_prefix(t_data *data);
// prompter
char	*add_prompt_suffix(char *prefix);
char	*get_prompt(t_data *data);
char	*read_input(t_data *data);
void	clear_readline_history(void);
// main
// void	run_shell(t_data *data);
int		main(int ac, char **av, char **env);

#endif