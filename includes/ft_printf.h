/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 13:41:09 by jjaniec           #+#    #+#             */
/*   Updated: 2017/12/12 13:12:43 by jjaniec          ###   ########.fr       */
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

int		ft_is_flag_c1(char c);

int		ft_is_flag_c2(char c1, char c2);

int		ft_get_flag(const char *restrict format, int *pos);
#endif

