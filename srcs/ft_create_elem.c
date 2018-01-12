/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 14:42:31 by jjaniec           #+#    #+#             */
/*   Updated: 2018/01/12 20:12:32 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Create and return an element of type t_arg to store data of an argument
*/

t_arg	*ft_create_elem(va_list va_ptr, char *flag)
{
	t_arg	*e;

	e = (t_arg *)malloc(sizeof(t_arg));
	e->data_converted = ft_convert_arg_no_modifiers(va_ptr, flag);
	e->flag = flag;
	e->precision = NULL;
	//e->precision = ft_get_precision(flag);
	e->next = NULL;
	//printf("Created elem with: \n   data_converted: %s\n   flag: %s\n   precision:%s\n---\n", e->data_converted, e->flag, e->precision);
	return (e);
}
