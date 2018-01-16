/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 13:41:09 by jjaniec           #+#    #+#             */
/*   Updated: 2018/01/16 17:28:37 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <wchar.h>
# include <locale.h>

typedef struct	s_arg
{
	char			*data_converted;
	char			*flag;
    char            *width;
	char			*precision;
    char            *attributes;
	struct s_arg	*next;
}				t_arg;

int		ft_printf(const char *restrict format, ...);

int		ft_count_args(const char *restrict format);

t_arg	*ft_create_arglist(va_list va_ptr, const char *restrict format);

t_arg	*ft_create_elem(va_list va_ptr, const char *restrict format, int pos);

void	ft_debug_args(const char *restrict format, t_arg *li);

void	ft_print_next_arg(t_arg **li, const char *restrict format, int *i);

void	ft_print_color(const char *restrict format, va_list va_ptr, int *i);

int		ft_is_flag_c(char c);

int		ft_is_modifier(char c, char c2);

char	*ft_get_flag(const char *restrict format, int pos);

char	*ft_convert_arg_no_modifiers(va_list va_arg, char *flag);

char	*ft_char_to_str(char c);

char	*ft_uint_to_str(unsigned int x);

char	*ft_uint_to_hex(unsigned int n);

char	*ft_uint_to_hex_caps(unsigned int n);

void	ft_putwchar(wchar_t c);

void	ft_putwstr(wchar_t *s);

char	ft_wchar_byte_to_char(int w_char_len, int bytepos, wchar_t c);

int		ft_wchar_masklen(wchar_t c);

int		ft_sizeof_wstr_to_char(wchar_t *ws);

char	*ft_wchar_tptr_to_str(wchar_t *ws);

char	*ft_wchar_t_to_str(wchar_t c);

char    *ft_uint_to_octal(const unsigned int n);

char    *ft_long_int_to_uoctal(const long int n);

int     ft_is_flag(const char *restrict format, int i);

int     ft_printf_no_args(const char *restrict format);

char    *ft_parse_attributes(const char *restrict format, int *pos);

int     ft_is_attribute(char c);

int     ft_get_attributes_len(const char *restrict format, int pos);

char    *ft_parse_width(const char *restrict format, int *pos);

int     ft_get_width_len(const char *restrict format);

char    *ft_parse_precision(const char *restrict format, int *pos);

void    ft_apply_options(t_arg **e);

void    ft_apply_attributes(t_arg **e);

void    ft_apply_attr_minus(t_arg **e);

char    *ft_generate_width(t_arg **e);

#endif

