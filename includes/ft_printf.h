/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 13:41:09 by jjaniec           #+#    #+#             */
/*   Updated: 2018/01/05 14:40:45 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_arg
{
	char		*data_converted;
	char		*flag;
	char		*precision;
}				t_arg;

int		ft_printf(const char *restrict format, ...);

int		ft_count_args(const char *restrict format);

void	ft_print_arg(const char *restrict format, va_list va_ptr,\
		int *i, char *flag);

void	ft_print_color(const char *restrict format, va_list va_ptr, int *i);

int		ft_is_flag_c(char c);

int		ft_is_modifier(char c, char c2);

char	*ft_get_flag(const char *restrict format, int pos);

char	*ft_convert_arg_no_modifiers(va_list va_arg, char *flag);

char	*ft_char_to_str(char c);

char	*ft_uint_to_str(unsigned int x);

char	*ft_uint_to_hex(unsigned int n);

char	*ft_uint_to_hex_caps(unsigned int n);

#endif

