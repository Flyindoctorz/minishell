# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    lexique.txt                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/22 16:28:44 by cgelgon           #+#    #+#              #
#    Updated: 2025/01/22 16:28:44 by cgelgon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Permet de faire des verifications sur l'implementation de data et de l'env

data_test.h -

Contient uniquement clean_test_env
S'assure qu'on ne laisse pas de déchets en mémoire

data_env.c - 
Crée les éléments de base pour nos tests
Fabrique les variables d'environnement une par une

data_large_env_test.c -
Crée et gère des environnements très grands

data_test.c -

Contient les quatre tests essentiels :

Test normal (system_env)
Test sans environnement (null_env)
Test avec environnement personnalisé (custom_env)
Test avec grand environnement (large_env)

data_cleaner.c - Le nettoyeur