/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 20:41:46 by jjaniec           #+#    #+#             */
/*   Updated: 2017/12/11 21:53:29 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Prints argument in format[*pos] passed as argument in printf
*/

void	ft_print_arg(const char *restrict format, va_list va_ptr, int *pos)
{
	char	flag[2];

	flag[0] = format[*pos + 1];
	if (format[*pos + 2] && ft_is_flag_c2(format[*pos + 2])
		flag[1] = format[*pos + 2];


	*pos += 1;
}
