/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 13:44:01 by jjaniec           #+#    #+#             */
/*   Updated: 2018/01/12 22:02:52 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
**
*/

int		ft_printf(const char *restrict format, ...)
{
	int		i;
	va_list	va_ptr;
	t_arg	*args;

	if (!ft_count_args(format))
		return (write(1, format, ft_strlen(format)));
	va_start(va_ptr, format);
	args = ft_create_arglist(va_ptr, format);
	va_end(va_ptr);
	
    printf("\n---format : %s---\n", format);
	ft_debug_args(args);
	printf("---\n");
	i = -1;
	while (format[++i])
	{
		if (ft_is_flag(format, i))
			ft_print_next_arg(&args, format, &i);
        else
            if (format[i])
                ft_putchar(format[i]);
	}
	printf("\n---END---\n");
	return (0);
}
