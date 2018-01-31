/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 20:42:58 by jjaniec           #+#    #+#             */
/*   Updated: 2018/01/31 18:26:19 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_color(const char *restrict format, va_list va_ptr, int *pos)
{
	printf("color %s\n", format);
	va_ptr = NULL;
	*pos += 1;
}
