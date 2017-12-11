/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 13:44:01 by jjaniec           #+#    #+#             */
/*   Updated: 2017/12/11 21:53:03 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
**
*/

int		ft_printf(const char *restrict format, ...)
{
	int			i;
	va_list		va_ptr;

	va_start(va_ptr, ft_count_args(format));
	i = -1;
	while (format[++i])
	{
		if (format[i] == '%' && format[i + 1] && ft_is_flag_c1([i + 1]))
			ft_print_arg(format, va_ptr,  &i);
		if (format[i] == '{' && format[i + 1])
			ft_print_color(format, va_ptr, &i);
		if (format[i])
			ft_putchar(format[i]);
	}
	va_end(va_ptr);
	return (0);
}
