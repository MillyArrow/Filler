# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marrow <marrow@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/05 21:44:43 by marrow            #+#    #+#              #
#    Updated: 2020/10/14 21:34:50 by marrow           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# LIBNAME

NAME = libft.a

# COMPILER

CC = gcc
FLAGS = -Wall -Werror -Wextra -O3 -c

# COLORS

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

# HEADERS

HEADERS_DIRECTORY = ./includes/
INCLUDES = -I$(HEADERS_DIRECTORY)
HEADERS_LIST = \
	libft.h\
	ft_printf.h
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

# LIBFT

DIR_SRC_LIBFT = ./sources/
DIR_OBJ_LIBFT = objects/

SRC_LIBFT = \
		ft_arrdel.c \
		ft_atoi.c \
		ft_bzero.c \
		ft_create_elem.c \
		ft_copybyte.c \
		ft_isblanki.c \
		ft_islower.c \
		ft_isupper.c \
		ft_strnlen.c \
		ft_memalloc.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memdel.c \
		ft_memmove.c \
		ft_memset.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strclr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strequ.c \
		ft_isalpha.c \
		ft_isprint.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlen.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strncat.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strnequ.c \
		ft_strnew.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strstr.c \
		ft_strsub.c \
		ft_strtrim.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_strsplit.c \
		ft_itoa.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putendl.c \
		ft_putnbr.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_lstnew.c \
		ft_lstadd.c \
		ft_lstdel.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_strchri.c \
		get_next_line.c \
		ft_number_length.c \
		ft_putnbrll.c \
		ft_get_number.c

# PRINTF

DIR_PRINTF = ft_printf
DIR_SRC_PRINTF = $(DIR_PRINTF)/sources/
DIR_OBJ_PRINTF = $(DIR_PRINTF)/objects/

SRC_PRINTF = \
		ft_big_x.c \
		ft_c.c \
		ft_d.c \
		ft_e.c \
		ft_f.c \
		ft_f_func.c \
		ft_format_specifier.c \
		ft_o.c \
		ft_p.c \
		ft_pct.c \
		ft_printf.c \
		ft_s.c \
		ft_setcolor.c \
		ft_type.c \
		ft_u.c \
		ft_width.c \
		ft_x.c

# FILE PATH TO LIBFT SRC/OBJ FILES

SRCS_LIBFT = $(addprefix $(DIR_SRC_LIBFT), $(SRC_LIBFT))
OBJS_LIBFT = $(addprefix $(DIR_OBJ_LIBFT), $(SRC_LIBFT:.c=.o))

#FILE PATH TO PRINTF SRC/OBJ FILES

SRCS_PRINTF = $(addprefix $(DIR_SRC_PRINTF), $(SRC_PRINTF))
OBJS_PRINTF = $(addprefix $(DIR_OBJ_PRINTF), $(SRC_PRINTF:.c=.o))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(SRCS_LIBFT) $(OBJS_LIBFT) $(SRCS_PRINTF) $(OBJS_PRINTF) $(HEADERS)
	@ar rcs $(NAME) $(OBJS_LIBFT) $(OBJS_PRINTF)
	@echo "\n$(NAME): $(GREEN)object files were created$(RESET)"
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

$(DIR_OBJ_LIBFT)%.o: $(DIR_SRC_LIBFT)%.c
	@mkdir -p $(DIR_OBJ_LIBFT)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(GREEN).$(RESET)\c"

$(DIR_OBJ_PRINTF)%.o: $(DIR_SRC_PRINTF)%.c
	@mkdir -p $(DIR_OBJ_PRINTF)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(GREEN).$(RESET)\c"

clean:
	@rm -rf $(DIR_OBJ_LIBFT)
	@rm -rf $(DIR_OBJ_PRINTF)
	@echo "$(NAME): $(RED)$(DIR_OBJ_LIBFT) was deleted$(RESET)"
	@echo "$(NAME): $(RED)$(DIR_OBJ_PRINTF) was deleted$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

re: fclean all
