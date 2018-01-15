/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 14:42:31 by jjaniec           #+#    #+#             */
/*   Updated: 2018/01/14 19:19:15 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Create and return an element of type t_arg to store data of an argument
*/

t_arg	*ft_create_elem(va_list va_ptr, const char *restrict format, int pos)
{
	t_arg	*e;

	e = (t_arg *)malloc(sizeof(t_arg));
	e->precision = NULL;
    e->attributes = ft_parse_attributes(format, &pos);
	//e->precision = ft_get_precision(flag);
	e->flag = ft_get_flag(format, pos);
	e->data_converted = ft_convert_arg_no_modifiers(va_ptr, e->flag);
	e->next = NULL;
	//printf("Created elem with: \n   data_converted: %s\n   flag: %s\n   precision:%s\n---\n", e->data_converted, e->flag, e->precision);
	return (e);
}
