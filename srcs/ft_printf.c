/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 13:44:01 by jjaniec           #+#    #+#             */
/*   Updated: 2017/12/16 19:03:05 by jjaniec          ###   ########.fr       */
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
	char		*flag;

	j = ft_count_args(format);
	va_start(va_ptr, j);
	i = -1;
	while (format[++i])
	{
		if (format[i] == '%' && format[i + 1] && ft_get_flag(format, i)[0])
		{
			flag = ft_get_flag(format, i);
			if (ft_strlen(flag) == 1)
				ft_print_arg(format, va_ptr,  &i, flag);
			i += ft_strlen(flag);
		}
		if (format[i] == '{' && format[i + 1])
			ft_print_color(format, va_ptr, &i);
		if (format[i] != '%' || (format[i] == '%' && format[i + 1] == '%'))
			ft_putchar(format[((format[i] == '%' && format[i + 1] == '%') ? (i++) : (i))]);
	}
	va_end(va_ptr);
	return (0);
}
