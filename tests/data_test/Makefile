# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/13 10:00:00 by cgelgon           #+#    #+#              #
#    Updated: 2025/03/12 15:47:55 by cgelgon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Définition des chemins de base
ROOT_DIR = ../..
INCLUDE_DIR = $(ROOT_DIR)/include
DATA_DIR = $(ROOT_DIR)/parsing/data_structure
LIBFT_DIR = $(ROOT_DIR)/libft

# Configuration du compilateur
NAME = data_tester
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I$(LIBFT_DIR) -I$(INCLUDE_DIR)

LIBFT = $(LIBFT_DIR)/libft.a
LDFLAGS = -L$(LIBFT_DIR) -lft

# Sources
TEST_SRCS = data_env.c \
            data_large_env.c \
            data_test.c \
            data_run.c \
            data_utils.c \
            main.c

PROJ_SRCS = $(DATA_DIR)/init_base.c \
            $(DATA_DIR)/exit_free.c \
            $(DATA_DIR)/init_environment.c \
            $(INCLUDE_DIR)/error.c

OBJ_DIR = obj
TEST_OBJS = $(TEST_SRCS:%.c=$(OBJ_DIR)/%.o)
PROJ_OBJS = $(notdir $(PROJ_SRCS:%.c=%.o))
PROJ_OBJS := $(addprefix $(OBJ_DIR)/, $(PROJ_OBJS))
OBJS = $(TEST_OBJS) $(PROJ_OBJS)

# Main rules
all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: $(DATA_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: $(INCLUDE_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

# Run test after build
test: $(NAME)
	@echo "\n=== Running data structure tests ===\n"
	./$(NAME)

# Cleaning rules
clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re test