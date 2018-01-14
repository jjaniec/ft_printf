# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/05 18:15:37 by jjaniec           #+#    #+#              #
#    Updated: 2018/01/14 14:56:16 by jjaniec          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_NAME = ft_char_to_str.c \
		   ft_convert_arg_no_modifiers.c \
		   ft_count_args.c \
		   ft_create_arglist.c \
		   ft_create_elem.c \
		   ft_debug_args.c \
		   ft_get_flag.c \
		   ft_is_flag.c \
		   ft_long_int_to_uoctal.c \
		   ft_print_next_arg.c \
		   ft_printf.c \
		   ft_putwchar.c \
		   ft_putwstr.c \
		   ft_sizeof_wstr_to_char.c \
		   ft_uint_to_hex.c \
		   ft_uint_to_octal.c \
		   ft_uint_to_str.c \
		   ft_wchar_byte_to_char.c \
		   ft_wchar_masklen.c \
		   ft_wchar_t_to_str.c \
		   ft_wchar_tptr_to_str.c

OBJS_NAMES = $(OBJS_NAMES:.c=.o)
NAME = libftprintf.a
CC = gcc
C_FLAGS = -Wall -Wextra -Werror
IFLAGS = -I./libft -I./$(INCLUDES_DIR)
LFLAGS = -L./libft/ -lft
SRC_DIR = ./srcs/
OBJ_DIR = ./obj/
INCLUDES_DIR = ./includes/
SRCS = $(addprefix $(SRC_DIR), $(SRC_NAME))
OBJS = $(addprefix $(OBJ_DIR), $(SRC_NAME:.c=.o))

all : $(NAME)

$(NAME) : libft $(OBJS) 
	@ar rcs $(NAME) $(OBJS) libft/objs/*.o

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR) 2> /dev/null || true
	$(CC) $(C_FLAGS) $(IFLAGS) -c $^ -o $@

clean:
	@rm -f $(OBJ)
	@rm -rf $(OBJ_DIR)
	@make clean -C libft/

fclean: clean
	@make fclean -C libft/
	@rm -f $(NAME)

re: fclean all

libft:
	make -C ./libft/

tests: 
	@gcc $(addprefix $(SRC_DIR),main.c) libftprintf.a -o ./ft_printf

.PHONY : all clean re tests libft
