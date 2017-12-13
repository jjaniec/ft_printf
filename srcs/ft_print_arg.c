/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 20:41:46 by jjaniec           #+#    #+#             */
/*   Updated: 2017/12/13 18:37:15 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Prints argument in format[*pos] passed as argument in printf
*/

void	ft_print_arg(const char *restrict format, va_list va_ptr, int *pos)
{
	char	*flag;
	char	*arg_content_str;

	flag = ft_get_flag(format, pos);
	printf("\nFound flag : %s of len %zu\n", flag, ft_strlen(flag));
	arg_content_str = ft_convert_arg(va_ptr, flag);
	if (arg_content_str)
	{
		ft_putstr(arg_content_str);
	}
	*pos += ft_strlen(flag);
}
