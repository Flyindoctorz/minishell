/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 13:57:40 by cgelgon           #+#    #+#             */
/*   Updated: 2025/03/19 15:09:59 by cgelgon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

typedef struct s_heredoc
{
    char *delimiter;              // Délimiteur
    int fd;                       // Descripteur de fichier
    char *content;                // Contenu collecté
    bool expand;                  // Si l'expansion doit être effectuée
} t_heredoc;

// heredoc utils/parsing
bool is_heredoc_token(t_token *token);
bool is_valid_heredoc_delimiter(char *delimiter);
char *extract_heredoc_delim(t_token *token);
bool process_heredoc_tok(t_cmd_list *cmd, t_token *token, t_data *data);
bool process_all_heredocs(t_cmd_list *cmd, t_token *token, t_data *data);
// heredoc 
bool write_content_to_pipe(int fd, char *content);
t_heredoc *init_heredoc(char *delimiter, bool expand);
void free_heredoc(t_heredoc *heredoc);




