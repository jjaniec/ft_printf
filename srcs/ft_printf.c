/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 13:44:01 by jjaniec           #+#    #+#             */
/*   Updated: 2017/12/11 16:21:38 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
**
*/

int		ft_printf(const char *restrict format, ...)
{
	int			i;
	va_list		args;

	va_start(args, ft_count_args(format));
	i = -1;
	while (format[++i])
	{
		if (format[i] == '%')
			ft_print_arg(format, &i);
		if (format[i] == '{')
			ft_print_color(format, &i);
		if (format[i])
			ft_putchar(format[i]);
	}
	return (0);
}

int		main(int ac, char **av)
{
	ft_printf("fisojfoiej");
	return (0);
}
