NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f

# Library paths
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# Include paths
INCLUDE_DIR = include
INCLUDES = -I$(INCLUDE_DIR) -I$(LIBFT_DIR)

# Main components
DATA_DIR = parsing/data_structure
LEXER_DIR = parsing/lexer
PARSER_DIR = parsing/parser
READLINE_DIR = parsing/readline

# Source files by component
DATA_SRC = $(DATA_DIR)/exit_free.c \
           $(DATA_DIR)/init_base.c \
           $(DATA_DIR)/init_environment.c

LEXER_SRC = $(LEXER_DIR)/expand_utils.c \
            $(LEXER_DIR)/init_lexer.c \
            $(LEXER_DIR)/lexer_main.c \
            $(LEXER_DIR)/quotes_utils.c \
            $(LEXER_DIR)/read_expand.c \
            $(LEXER_DIR)/read_operator.c \
            $(LEXER_DIR)/read_quotes.c \
            $(LEXER_DIR)/read_word.c \
            $(LEXER_DIR)/shrinker.c \
            $(LEXER_DIR)/shrinker_two.c \
            $(LEXER_DIR)/shrinker_three.c \
            $(LEXER_DIR)/utils_lexer.c

READLINE_SRC = $(READLINE_DIR)/readline_interface.c \
               $(READLINE_DIR)/readline_main.c \
               $(READLINE_DIR)/readline_prompter.c \
               $(READLINE_DIR)/readline_prompt_utils.c.c

# Include error handling
COMMON_SRC = $(INCLUDE_DIR)/error.c

# Main source
MAIN_SRC = parsing_main.c

# All source files combined
SRC = $(DATA_SRC) $(LEXER_SRC) $(READLINE_SRC) $(COMMON_SRC) $(MAIN_SRC)

# Object files
OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

# Create object file directories
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Rules to create object files from source files
$(OBJ_DIR)/%.o: $(DATA_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: $(LEXER_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: $(PARSER_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: $(READLINE_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: $(INCLUDE_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Main build rules
all: $(NAME)

$(LIBFT):
	@echo "Building libft..."
	@make -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJ)
	@echo "Linking $(NAME)..."
	$(CC) $(OBJ) -o $(NAME) -L$(LIBFT_DIR) -lft -lreadline
	@echo "$(NAME) successfully built!"

# Testing rules
test: test-data test-lexer

test-data:
	@echo "Running data structure tests..."
	@make -C tests/data_test

test-lexer:
	@echo "Running lexer tests..."
	@make -C tests/lexer_test

# Cleaning rules
clean:
	@echo "Cleaning object files..."
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean
	@make -C tests/data_test clean
	@make -C tests/lexer_test clean

fclean: clean
	@echo "Cleaning executables..."
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@make -C tests/data_test fclean
	@make -C tests/lexer_test fclean

re: fclean all

.PHONY: all clean fclean re test test-data test-lexer