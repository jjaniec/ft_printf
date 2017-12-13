/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 13:41:09 by jjaniec           #+#    #+#             */
/*   Updated: 2017/12/13 19:56:14 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

int		ft_printf(const char *restrict format, ...);

int		ft_count_args(const char *restrict format);

void	ft_print_arg(const char *restrict format, va_list va_ptr, int *i);

void	ft_print_color(const char *restrict format, va_list va_ptr, int *i);

int		ft_is_flag_c(char c);

int		ft_is_modifier(char c, char c2);

char	*ft_get_flag(const char *restrict format, int pos);

char	*ft_convert_arg(va_list va_arg, char *flag);

#endif

