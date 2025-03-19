# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    README_PARSING.txt                                 :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/29 09:21:02 by cgelgon           #+#    #+#              #
#    Updated: 2025/01/29 09:54:20 by cgelgon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

1. Declare les stuctures qui composent le parsing 
    (en premier pour eviter dependances circulaires)

une structure pour chaque entite unique ; 

t_data : stock variable environnement 
t_lexer :analyse lexicalement l'input puis produit des token
t_token : stock les token 1-7 (def en .h)
t_parsing : 

// stock token 1-7 et sert de base a t_cmd lis
// donnee necessaires au ftionnenement global
// stock variable environnement, 
// stock redir, args et operateurs, permet d'execute une cmd
// suivi des etats et des index, suit le deroulement d'une commande
// stock info pour gerer heredoc
// analyse lexique puis genere token, fourni token au parser

// defini les token 
// en tant que globaux et le attribue un numero en fonction type
/* Définition des types de tokens pour l'analyse lexicale */
# define TYPE_WORD 0           // Mot simple (commande ou argument)
# define TYPE_REDIR_IN 1       // Redirection entrée (<)
# define TYPE_REDIR_OUT 2      // Redirection sortie (>)
# define TYPE_REDIR_APPEND 3   // Redirection sortie en mode append (>>)
# define TYPE_HEREDOC 4        // Here-document (<<)
# define TYPE_ENV_VAR 5        // Variable d'environnement ($VAR)
# define TYPE_PIPE 6           // Pipe (|)
# define TYPE_QUOTED 7         // Texte entre guillemets
# define TYPE_DOLLAR 8        // Le caractère $ seul
# define TYPE_DQUOTE 9       // Double quote "
# define TYPE_SQUOTE 10      // Single quote '
# define TYPE_EXPANDED 11    // Token déjà expandé



/* t_lexer -> produit des t_token a partir de l'entree
   t_token -> utilise par t_parsing pour construire une t_cmd_list
   t_cmd list -> permet d'executer les cmd
   t_env -> fournit des donnes contextuelles
   t_heredoc -> parametre pendant t_parsing, permet de faire des heredoc
   t_data centralise les donnes partagees et globles au programme
   Entrée utilisateur -> t_lexer -> t_token -> t_parsing -> t_cmd_list -> Exécution */


