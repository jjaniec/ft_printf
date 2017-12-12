/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 20:41:46 by jjaniec           #+#    #+#             */
/*   Updated: 2017/12/12 13:10:56 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Prints argument in format[*pos] passed as argument in printf
*/

void	ft_print_arg(const char *restrict format, va_list va_ptr, int *pos)
{
	char	*flag;

	flag = ft_get_flag(format, pos);
	printf("Found flag : %s\n", flag);

	*pos += ft_strlen(flag);
}
