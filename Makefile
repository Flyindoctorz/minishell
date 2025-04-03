# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/31 19:10:00 by lmokhtar          #+#    #+#              #
#    Updated: 2025/04/03 14:17:16 by cgelgon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
BLUE = \033[0;34m
GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[0;33m
RESET = \033[0m
BOLD = \033[1m

# Chemins de base
ROOT_DIR = .
INCLUDE_DIR = $(ROOT_DIR)/include
LIBFT_DIR = $(ROOT_DIR)/libft

# Configuration du compilateur
NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I$(INCLUDE_DIR) -I$(LIBFT_DIR)
LDFLAGS = -L$(LIBFT_DIR) -lft -lreadline

# Répertoires des sources
EXEC_DIR = exec/exec
BUILTINS_DIR = exec/exec/built-ins
UTILS_DIR = exec/utils
LEXER_DIR = parsing/lexer
DATA_DIR = parsing/data_structure
READLINE_DIR = parsing/readline
PARSER_DIR = parsing/parser

# Structure des sources
SRC_FILES = main.c
EXEC_FILES = exec.c exec_builtins.c pipex.c signals.c redir_utils.c
BUILTINS_FILES = cd.c echo.c env.c exit.c exit2.c export.c pwd.c unset.c
UTILS_FILES = command.c env.c env_utils.c expand.c expand2.c redir.c string.c string2.c \
	string3.c string4.c tab.c token.c unset.c
LEXER_FILES = expand_utils.c init_lexer.c lexer_main.c quotes_utils.c \
	read_expand.c read_operator.c read_quotes.c read_word.c shrinker.c \
	shrinker_three.c shrinker_two.c utils_lexer.c
DATA_FILES = init_base.c exit_free.c init_environment.c
READLINE_FILES = readline_main.c readline_prompter.c readline_prompt_utils.c readline_interface.c
PARSER_FILES = parsing_main.c

# Préfixage des chemins complets
SRCS = $(addprefix $(ROOT_DIR)/, $(SRC_FILES))
EXEC_SRCS = $(addprefix $(EXEC_DIR)/, $(EXEC_FILES))
BUILTINS_SRCS = $(addprefix $(BUILTINS_DIR)/, $(BUILTINS_FILES))
UTILS_SRCS = $(addprefix $(UTILS_DIR)/, $(UTILS_FILES))
LEXER_SRCS = $(addprefix $(LEXER_DIR)/, $(LEXER_FILES))
DATA_SRCS = $(addprefix $(DATA_DIR)/, $(DATA_FILES))
READLINE_SRCS = $(addprefix $(READLINE_DIR)/, $(READLINE_FILES))
PARSER_SRCS = $(addprefix $(PARSER_DIR)/, $(PARSER_FILES))
ERROR_SRCS = $(INCLUDE_DIR)/error.c

# Regroupement de toutes les sources
ALL_SRCS = $(SRCS) $(EXEC_SRCS) $(BUILTINS_SRCS) $(UTILS_SRCS) $(LEXER_SRCS) \
           $(DATA_SRCS) $(READLINE_SRCS) $(PARSER_SRCS) $(ERROR_SRCS)

# Configuration des objets
OBJ_DIR = obj
OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(notdir $(ALL_SRCS)))

# Bibliothèque statique libft
LIBFT = $(LIBFT_DIR)/libft.a

# Règles principales
all: $(NAME)

# Construction de la bibliothèque libft
$(LIBFT):
	@echo "$(BLUE)Building libft...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR)

# Création du répertoire des objets
$(OBJ_DIR):
	@mkdir -p $@

# Compilation du programme principal
$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJS)
	@echo "$(BLUE)Linking $(NAME)...$(RESET)"
	$(CC) $(OBJS) $(LDFLAGS) -o $@
	@echo "$(GREEN)✨ $(NAME) is ready!$(RESET)"

# Règles pour la compilation des fichiers source
$(OBJ_DIR)/%.o: $(ROOT_DIR)/%.c | $(OBJ_DIR)
	@echo "$(YELLOW)Compiling: $<$(RESET)"
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: $(EXEC_DIR)/%.c | $(OBJ_DIR)
	@echo "$(YELLOW)Compiling: $<$(RESET)"
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: $(BUILTINS_DIR)/%.c | $(OBJ_DIR)
	@echo "$(YELLOW)Compiling: $<$(RESET)"
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: $(UTILS_DIR)/%.c | $(OBJ_DIR)
	@echo "$(YELLOW)Compiling: $<$(RESET)"
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: $(LEXER_DIR)/%.c | $(OBJ_DIR)
	@echo "$(YELLOW)Compiling: $<$(RESET)"
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: $(DATA_DIR)/%.c | $(OBJ_DIR)
	@echo "$(YELLOW)Compiling: $<$(RESET)"
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: $(READLINE_DIR)/%.c | $(OBJ_DIR)
	@echo "$(YELLOW)Compiling: $<$(RESET)"
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: $(PARSER_DIR)/%.c | $(OBJ_DIR)
	@echo "$(YELLOW)Compiling: $<$(RESET)"
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: $(INCLUDE_DIR)/%.c | $(OBJ_DIR)
	@echo "$(YELLOW)Compiling: $<$(RESET)"
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Règles de nettoyage
clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR)
	@echo "$(GREEN)✨ Cleaned!$(RESET)"

fclean: clean
	@echo "$(RED)Removing $(NAME)...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)
	@echo "$(GREEN)✨ Everything cleaned!$(RESET)"

# Vérification des fuites de mémoire
leak: all
	@echo "$(BLUE)Running valgrind leak check...$(RESET)"
	@valgrind --leak-check=full --show-below-main=no --show-leak-kinds=all \
		--track-fds=yes --trace-children=yes ./$(NAME)

re: fclean all

.PHONY: all clean fclean re leak