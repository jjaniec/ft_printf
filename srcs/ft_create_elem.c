/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 14:42:31 by jjaniec           #+#    #+#             */
/*   Updated: 2018/01/21 14:43:51 by jjaniec          ###   ########.fr       */
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
	e->attributes = ft_parse_attributes(format, &pos);
	e->width = ft_parse_width(format, &pos);
	if (format[pos + 1] == '.')
		e->precision = ft_parse_precision(format, &pos);
	else
		e->precision = NULL;
	if (format[pos + 1] == 'l' || format[pos + 1] == 'h' || \
		format[pos + 1] == 'z' || format[pos + 1] == 'j')
		e->modifiers = ft_parse_modifiers(format, &pos);
	else
		e->modifiers = NULL;
	e->flag = ft_get_flag(format, pos);
	/*
	if (!e->modifiers)*/
		e->data_converted = ft_convert_arg_no_modifiers(va_ptr, e->flag);/*
	else
		ft_convert_arg_modifiers(va_ptr, e->flag);*/
	ft_apply_options(&e);
	e->next = NULL;
	return (e);
}
