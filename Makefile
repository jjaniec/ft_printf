# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/05 18:15:37 by jjaniec           #+#    #+#              #
#    Updated: 2018/02/14 17:19:21 by jjaniec          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_NAME = ft_apply_attr_.c \
		   ft_apply_attributes.c \
		   ft_apply_options.c \
		   ft_apply_precision.c \
		   ft_apply_width.c \
		   ft_atoi_hex.c \
		   ft_char_to_str.c \
		   ft_convert_arg_mod_.c \
		   ft_convert_arg_mod_2.c \
		   ft_convert_arg_modifiers.c \
		   ft_convert_arg_no_modifiers.c \
		   ft_count_args.c \
		   ft_create_arglist.c \
		   ft_create_elem.c \
		   ft_debug_args.c \
		   ft_free_elem.c \
		   ft_generate_width.c \
		   ft_get_flag.c \
		   ft_is_color.c \
		   ft_imax_toa.c \
		   ft_is_conv_numeric.c \
		   ft_is_flag.c \
		   ft_parse_attributes.c \
		   ft_parse_modifiers.c \
		   ft_parse_precision.c \
		   ft_parse_width.c \
		   ft_print_color.c \
		   ft_print_color_id.c \
		   ft_print_next_arg.c \
		   ft_print_until_validconv.c \
		   ft_printf.c \
		   ft_printf_no_args.c \
		   ft_printf_percent.c \
		   ft_printf_str_arg.c \
		   ft_putchar_printf.c \
		   ft_putstr_hex.c \
		   ft_putwchar.c \
		   ft_putwstr.c \
		   ft_sizeof_wstr_to_char.c \
		   ft_strnotchr.c \
		   ft_uitoa_base.c \
		   ft_voidptr_to_hex.c \
		   ft_wchar_byte_to_char.c \
		   ft_wchar_masklen.c \
		   ft_wchar_t_to_str.c \
		   ft_wchar_tptr_to_str.c

OBJS_NAMES = $(OBJS_NAMES:.c=.o)
LIBFT_SRCS = $(shell cat libft/Makefile | grep -E '(ft_[a-z_]{1,}.c)' | cut -d '=' -f 2 | tr -d '\n' | tr -d '\t' | tr -d '\\')
LIBFT_OBJS = $(LIBFT_SRCS:.c=.o)
NAME = libftprintf.a
LIBFT = libft/libft.a
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

$(NAME) : $(LIBFT) $(OBJS)
	@ar rcs $(NAME) $(OBJS) $(addprefix libft/objs/,$(LIBFT_OBJS))

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
	@rm -rf curqui_test

re: fclean all

$(LIBFT):
	make -C ./libft/

tests:
	@gcc $(addprefix $(SRC_DIR),main.c) libftprintf.a -o ./ft_printf

curqui_test: $(NAME)
	git clone https://github.com/curquiza/curqui_test.git
	cp $(NAME) curqui_test
	sed -i.bak 's#ft_load_test(&test, \"all_02\", &bigs_all_02);##g' curqui_test/conv_bigs/a00_launcher.c
	make -C curqui_test
	./curqui_test/ft_printf_tests

.PHONY : all clean re tests libft curqui_test
