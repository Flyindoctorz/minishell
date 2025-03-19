# Your Makefile must at least contain the rules $(NAME), all, clean, fclean and re
# $(NAME) : 
# all : 
# clean : used to remove bin & obj files
# fclean : 
# re : 

# All source files you need to compile your project must be explicitly named in your Makefile.

# Special variables
# $@ : target name
# $< : first prerequisite name
# $^ : prerequisite list
# $? : updated prerequisite name list
# $* : filename without extension

# Program name libft.a
# Turn in files Makefile, libft.h, ft_*.c
# Makefile NAME, all, clean, fclean, re

# You must use the command ar to create your library. Using the libtool command is forbidden.

# gcc -c	compile source files to object files without linking

CFLAGS	=	-Wall -Werror -Wextra -g3

# SRC			=	ft_atoi.c				\
# 				ft_bzero.c				\
# 				ft_calloc.c				\
# 				ft_isalnum.c			\
# 				ft_isalpha.c			\
# 				ft_isascii.c			\
# 				ft_isdigit.c			\
# 				ft_isprint.c			\
# 				ft_itoa.c				\
# 				ft_memchr.c				\
# 				ft_memcmp.c				\
# 				ft_memcpy.c				\
# 				ft_memmove.c			\
# 				ft_memset.c				\
# 				ft_putchar_fd.c			\
# 				ft_putendl_fd.c			\
# 				ft_putnbr_fd.c			\
# 				ft_putnbr_printf_fd.c	\
# 				ft_putstr_fd.c			\
# 				ft_split.c				\
#				ft_strcat.c
# 				ft_strchr.c				\
#				ft_strcmp.c				\
#				ft_strcpy.c				\
# 				ft_strdup.c				\
# 				ft_striteri.c			\
# 				ft_strjoin.c			\
# 				ft_strlcat.c			\
# 				ft_strlcpy.c			\
# 				ft_strlen.c				\
# 				ft_strmapi.c			\
# 				ft_strncmp.c			\
# 				ft_strnstr.c			\
# 				ft_strrchr.c			\
# 				ft_strtrim.c			\
# 				ft_substr.c				\
# 				ft_tolower.c			\
# 				ft_toupper.c

# BONUS		=	ft_lstadd_back.c	\
# 				ft_lstadd_front.c	\
# 				ft_lstsize.c		\
# 				ft_lstlast.c		\
# 				ft_lstnew.c			\
# 				ft_lstdelone.c		\
# 				ft_lstclear.c		\
# 				ft_lstiter.c		\
# 				ft_lstmap.c

SRC			= $(shell ls *.c)

OBJ			=	$(SRC:.c=.o)


BONUS_OBJ	=	$(BONUS:.c=.o)

NAME		=	libft.a

all: $(NAME)

# Generate ".a" archive which is used in conjunction with the .h file
$(NAME): $(OBJ)
	ar -crs $(NAME) $(OBJ)

# Clean generated objects
clean:
	$(RM) $(OBJ) $(BONUS_OBJ)

# Clean all generated files
fclean: clean
	$(RM) $(NAME)

# redo compilation
re: fclean $(NAME)

norme:
	norminette

bonus: $(OBJ) $(BONUS_OBJ)
	ar -crs $(NAME) $(OBJ) $(BONUS_OBJ)

.PHONY: all clean fclean re bonus

# so:
# 	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)
# 	gcc -nostartfiles -shared -o libft.so $(OBJ)
