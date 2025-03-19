# Chemins de base
ROOT_DIR = ../..
INCLUDE_DIR = $(ROOT_DIR)/include
LEXER_DIR = $(ROOT_DIR)/parsing/lexer
DATA_DIR = $(ROOT_DIR)/parsing/data_structure
LIBFT_DIR = $(ROOT_DIR)/libft

# Configuration du compilateur
NAME = lexer_tester
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I$(LIBFT_DIR) \
           -I$(INCLUDE_DIR)

LIBFT = $(LIBFT_DIR)/libft.a
LDFLAGS = -L$(LIBFT_DIR) -lft

# Sources des tests organisées par sous-dossiers
DATA_TEST_SRCS = data_test/data_env.c \
                 data_test/data_large_env.c \
                 data_test/data_run.c \
                 data_test/data_test.c \
                 data_test/data_utils.c
SETUP_TEST_SRCS = setup_test/before_init_lexer.c \
                  setup_test/init_lexer_test.c \
                  setup_test/delimiter_test.c \
                  setup_test/lexer_run.c

LEXER_TEST_SRCS = lexer_test/lexer_utils_test.c \
                  lexer_test/whitespace_test.c \
                  lexer_test/read_word_test.c \
                  lexer_test/read_word_test_utils.c \
                  lexer_test/syntax_test.c \
                  lexer_test/quotes_test.c

EXPAND_TEST_SRCS = expand_test/expand_test_utils.c \
                   expand_test/expand_test_basic.c \
                   expand_test/expand_test_edge.c

SHRINKER_TEST_SRCS = shrinker_test/shrinker_test_basic.c \
                     shrinker_test/shrinker_test_simple.c \
                     shrinker_test/shrinker_test_multiple.c \
                     shrinker_test/shrinker_test_mixed.c \
                     shrinker_test/shrinker_test_utils.c \
                     shrinker_test/shrinker_test_run.c


# Fichier principal
MAIN_SRC = main.c

# Regroupement de tous les tests
TEST_SRCS = $(MAIN_SRC) \
			$(DATA_TEST_SRCS) \
            $(SETUP_TEST_SRCS) \
            $(LEXER_TEST_SRCS) \
            $(EXPAND_TEST_SRCS) \
			$(SHRINKER_TEST_SRCS)

# Fichiers source du projet
PROJ_SRCS = $(LEXER_DIR)/init_lexer.c \
            $(LEXER_DIR)/utils_lexer.c \
            $(LEXER_DIR)/read_word.c \
            $(LEXER_DIR)/quotes_utils.c \
            $(LEXER_DIR)/read_quotes.c \
            $(LEXER_DIR)/read_operator.c \
            $(LEXER_DIR)/read_expand.c \
            $(LEXER_DIR)/expand_utils.c \
			$(LEXER_DIR)/shrinker.c \
			$(LEXER_DIR)/shrinker_three.c \
			$(LEXER_DIR)/shrinker_two.c \
			$(DATA_DIR)/init_base.c \
            $(DATA_DIR)/exit_free.c \
            $(DATA_DIR)/init_environment.c \
			$(LEXER_DIR)/lexer_main.c \
			$(INCLUDE_DIR)/error.c \


# Configuration des objets
OBJ_DIR = obj

# Pour le fichier principal
MAIN_OBJ = $(OBJ_DIR)/main.o

SETUP_TEST_OBJS = $(notdir $(SETUP_TEST_SRCS:.c=.o))
SETUP_TEST_OBJS := $(addprefix $(OBJ_DIR)/setup_test_, $(SETUP_TEST_OBJS))

LEXER_TEST_OBJS = $(notdir $(LEXER_TEST_SRCS:.c=.o))
LEXER_TEST_OBJS := $(addprefix $(OBJ_DIR)/lexer_test_, $(LEXER_TEST_OBJS))

EXPAND_TEST_OBJS = $(notdir $(EXPAND_TEST_SRCS:.c=.o))
EXPAND_TEST_OBJS := $(addprefix $(OBJ_DIR)/expand_test_, $(EXPAND_TEST_OBJS))

SHRINKER_TEST_OBJS = $(notdir $(SHRINKER_TEST_SRCS:.c=.o))
SHRINKER_TEST_OBJS := $(addprefix $(OBJ_DIR)/shrinker_test_, $(SHRINKER_TEST_OBJS))

# Pour les fichiers du projet
PROJ_OBJS = $(notdir $(PROJ_SRCS:.c=.o))
PROJ_OBJS := $(addprefix $(OBJ_DIR)/, $(PROJ_OBJS))

# Combinaison de tous les objets
ALL_TEST_OBJS = $(MAIN_OBJ) $(SETUP_TEST_OBJS) $(LEXER_TEST_OBJS) $(EXPAND_TEST_OBJS) $(SHRINKER_TEST_OBJS)

OBJS = $(ALL_TEST_OBJS) $(PROJ_OBJS)

# Règles principales
all: $(NAME)

# Création du répertoire des objets
$(OBJ_DIR):
	@mkdir -p $@

# Règle pour main.c à la racine
$(OBJ_DIR)/main.o: main.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Règles pour les fichiers dans les sous-dossiers
$(OBJ_DIR)/setup_test_%.o: setup_test/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/lexer_test_%.o: lexer_test/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/expand_test_%.o: expand_test/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/shrinker_test_%.o: shrinker_test/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Règles pour les fichiers du projet
$(OBJ_DIR)/%.o: $(LEXER_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: $(DATA_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: $(INCLUDE_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $@

# Règles de nettoyage
clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@if [ -d "$(NAME)" ]; then rm -rf $(NAME); fi
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re