/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 13:44:01 by jjaniec           #+#    #+#             */
/*   Updated: 2018/01/24 16:30:44 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
**
*/

int		ft_printf(const char *restrict format, ...)
{
	int		i;
	int		l;
	int		r;
	va_list	va_ptr;
	t_arg	*args;

	if (!ft_count_args(format))
		return (ft_printf_no_args(format));
	va_start(va_ptr, format);
	args = ft_create_arglist(va_ptr, format);
	va_end(va_ptr);
	r = 0;
	//ft_debug_args(format, args);
	i = 0;
	l = (int)ft_strlen(format);
	while (format[i] && i < l)
	{
		while (format[i] && ft_is_flag(format, i) && args)
			ft_print_next_arg(&args, format, &i, &r);
		if (format[i])
		{
			if (format[i] == '%' && format[i + 1] == '%')
				i++;
			ft_putchar_printf(format[i], &r);
		}
		i++;
	}
	return (r);
}
