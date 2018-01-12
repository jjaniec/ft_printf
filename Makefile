# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/05 18:15:37 by jjaniec           #+#    #+#              #
#    Updated: 2018/01/12 19:53:36 by jjaniec          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf

SRC_NAME = ft_char_to_str.c \
		   ft_convert_arg_no_modifiers.c \
		   ft_count_args.c \
		   ft_create_arglist.c \
		   ft_create_elem.c \
		   ft_debug_args.c \
		   ft_get_flag.c \
		   ft_long_int_to_uoctal.c \
		   ft_print_color.c \
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
		   ft_wchar_tptr_to_str.c \
		   main.c

SRC_DIR = ./srcs/

INCLUDES_DIR = includes

OBJ_DIR = ./obj/

SRC = $(addprefix $(SRC_DIR), $(SRC_NAME))

OBJ = $(addprefix $(OBJ_DIR), $(SRC_NAME:.c=.o))

CFLAGS = -Wall -Wextra -Werror

IFLAGS = -I./libft -I./$(INCLUDES_DIR)

LFLAGS = -L./libft/ -lft

all : $(NAME)

.PHONY : all clean

$(NAME) : $(OBJ)
	make -C ./libft/
	gcc $(CFLAGS) $(LFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	gcc $(CFLAGS) -c $(IFLAGS) $^ -o $@

clean:
	rm -f $(OBJ)
	rm -rf $(OBJ_DIR)
	make clean -C libft/

fclean: clean
	make fclean -C libft/
	rm -f $(NAME)

re: fclean all
