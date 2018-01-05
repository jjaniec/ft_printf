/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 13:44:01 by jjaniec           #+#    #+#             */
/*   Updated: 2018/01/05 19:06:48 by jjaniec          ###   ########.fr       */
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
	printf("---");
	ft_debug_args(args);
	printf("---");
	i = -1;
	while (format[++i])
	{
		if (format[i] == '%' && format[i + 1] != '%' && ft_get_flag(format, i)[0])
			ft_print_next_arg(&args);
		else
			ft_putchar(format[(format[i + 1] == '%') ? (i++) : (i)]);
	}
	printf("\n---END---\n");
	return (0);
}
