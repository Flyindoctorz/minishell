# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmokhtar <lmokhtar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/31 19:10:00 by lmokhtar           #+#    #+#              #
#    Updated: 2025/03/31 19:10:00 by lmokhtar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
BLUE = \033[0;34m
GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[0;33m
RESET = \033[0m
BOLD = \033[1m

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./include -I./libft/include
LDFLAGS = -L./libft -lft -lreadline

# Directories
SRC_DIR = .
EXEC_DIR = exec/exec
BUILTINS_DIR = exec/exec/built-ins
UTILS_DIR = exec/utils
LEXER_DIR = parsing/lexer
OBJ_DIR = obj

# Source files
SRCS = main.c
EXEC_SRCS = exec.c exec_builtins.c pipex.c signals.c redir_utils.c
BUILTINS_SRCS = cd.c echo.c env.c exit.c export.c pwd.c unset.c
UTILS_SRCS = command.c env.c env_utils.c expand.c redir.c string.c string2.c \
	string3.c string4.c tab.c token.c
LEXER_SRCS = expand_utils.c init_lexer.c lexer_main.c quotes_utils.c \
	read_expand.c read_operator.c read_quotes.c read_word.c shrinker.c \
	shrinker_three.c shrinker_two.c utils_lexer.c

# Object files
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
EXEC_OBJS = $(addprefix $(OBJ_DIR)/, $(EXEC_SRCS:.c=.o))
BUILTINS_OBJS = $(addprefix $(OBJ_DIR)/, $(BUILTINS_SRCS:.c=.o))
UTILS_OBJS = $(addprefix $(OBJ_DIR)/, $(UTILS_SRCS:.c=.o))
LEXER_OBJS = $(addprefix $(OBJ_DIR)/, $(LEXER_SRCS:.c=.o))

# Target
NAME = minishell

# Rules
all: $(NAME)

$(NAME): $(OBJS) $(EXEC_OBJS) $(BUILTINS_OBJS) $(UTILS_OBJS) $(LEXER_OBJS)
	@echo "$(BLUE)Building libft...$(RESET)"
	@make -C libft
	@echo "$(BLUE)Linking $(NAME)...$(RESET)"
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)
	@echo "$(GREEN)✨ $(NAME) is ready!$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@echo "$(YELLOW)Compiling: $<$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(EXEC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@echo "$(YELLOW)Compiling: $<$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(BUILTINS_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@echo "$(YELLOW)Compiling: $<$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(UTILS_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@echo "$(YELLOW)Compiling: $<$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(LEXER_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@echo "$(YELLOW)Compiling: $<$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@make clean -C libft
	rm -rf $(OBJ_DIR)
	@echo "$(GREEN)✨ Cleaned!$(RESET)"

fclean: clean
	@echo "$(RED)Removing $(NAME)...$(RESET)"
	@make fclean -C libft
	rm -f $(NAME)
	@echo "$(GREEN)✨ Everything cleaned!$(RESET)"

leak : all
	@valgrind --leak-check=full --show-below-main=no --show-leak-kinds=all --track-fds=yes    --trace-children=yes  ./minishell

re: fclean all

.PHONY: all clean fclean re