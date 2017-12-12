/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 13:44:01 by jjaniec           #+#    #+#             */
/*   Updated: 2017/12/12 13:28:57 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
**
*/

int		ft_printf(const char *restrict format, ...)
{
	int			i;
	size_t		j;
	va_list		va_ptr;

	j = ft_count_args(format);
	va_start(va_ptr, j);
	i = -1;
	while (format[++i])
	{
		if (format[i] == '%' && format[i + 1] && ft_is_flag_c1(format[i + 1]))
			ft_print_arg(format, va_ptr,  &i);
		if (format[i] == '{' && format[i + 1])
			ft_print_color(format, va_ptr, &i);
		if (format[i])
			ft_putchar(format[i]);
	}
	va_end(va_ptr);
	return (0);
}
