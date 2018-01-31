/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 13:41:09 by jjaniec           #+#    #+#             */
/*   Updated: 2018/01/31 19:57:43 by jjaniec          ###   ########.fr       */
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
# include <limits.h>

typedef struct	s_arg
{
	char			*data_converted;
	char			*flag;
    char            *modifiers;
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

void	ft_print_next_arg(t_arg **li, const char *restrict format, int *i, int *r);

void	ft_print_color(const char *restrict format, va_list va_ptr, int *i);

int		ft_is_flag_c(char c);

int		ft_is_modifier(char c, char c2);

char	*ft_get_flag(const char *restrict format, int pos);

char	*ft_convert_arg_no_modifiers(va_list va_arg, char flag);

char	*ft_char_to_str(char c);

void	ft_putwchar(wchar_t c);

void	ft_putwstr(wchar_t *s);

char	ft_wchar_byte_to_char(int w_char_len, int bytepos, wchar_t c);

int		ft_wchar_masklen(wint_t c);

int		ft_sizeof_wstr_to_char(wchar_t *ws);

char	*ft_wchar_tptr_to_str(wchar_t *ws);

char	*ft_wchar_t_to_str(wint_t c);

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

void    ft_apply_attr_minus_zero(t_arg **e);

void    ft_apply_attr_plus(t_arg **e);

void    ft_apply_attr_space(t_arg **e);

char    *ft_generate_width(int l, char c);

void    ft_apply_width(t_arg **e);

void    ft_byte_swap(char *a, char *b);

void    *ft_free_elem(t_arg *e);

void    ft_putchar_printf(char c, int *r);

char    *ft_printf_str_arg(char *a);

void    ft_apply_precision(t_arg **e);

int     ft_is_conv_numeric(t_arg **e);

char    *ft_parse_modifiers(const char *restrict format, int *pos);

char    *ft_convert_arg_modifiers(va_list va_ptr, t_arg **e);

char    *ft_imax_toa(intmax_t n);

char    *ft_voidptr_to_hex(void *data);

void    ft_apply_attr_hashtag(t_arg **e);

int     ft_atoi_hex(char *s);

char    *ft_strnotchr(const char *s, char c);

char    *ft_uitoa_base(uintmax_t n, uint8_t b);

void    ft_printf_percent(const char *restrict format, int *pos, int *r);

void    *ft_free_arglist(t_arg *l);

#endif

