/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 13:44:01 by jjaniec           #+#    #+#             */
/*   Updated: 2018/01/05 16:41:32 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
**
*/

int		ft_printf(const char *restrict format, ...)
{
	int		i;
	int		c;
	va_list	va_ptr;
	t_arg	*args;

	c = ft_count_args(format);
	va_start(va_ptr, c);
	args = ft_create_arglist(va_ptr, format);
	i = -1;
	while (format[++i])
	{
		if (format[i] == '%' && format[i + 1] != '%' && ft_get_flag(format, i)[0])
			ft_print_next_arg(&args);
		//if (format[i] == '{' && ft_get_color(format, i)[0])
		//	ft_print_color(ft_get_color(format, i), &i);
	}
	return (0);
}

/*
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
}*/
