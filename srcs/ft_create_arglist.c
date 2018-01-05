/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_arglist.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 14:55:13 by jjaniec           #+#    #+#             */
/*   Updated: 2018/01/05 15:54:43 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Create a linked list with all arguments passed in parameters
** it stores content converted as a char * in e.data_converted
** argument flag in e.flag and precision of argument to print in e.precision
*/

t_arg	*ft_create_arglist(va_list va_ptr, const char *restrict format)
{
	t_arg	*li;
	t_arg	**r;
	int		i;
	int		c;


	c = ft_count_args(format);
	i = -1;
	li = (t_arg *)malloc(sizeof(t_arg) * c);
	li = NULL;
	r = &li;
	while (c > 0 && format[++i])
	{
		if (format[i] == '%' && ft_get_flag(format, i)[0])
		{
			if (li != NULL)
			{
				li->next = ft_create_elem(va_ptr, ft_get_flag(format, i));
				li = li->next;
			}
			else
			{
				li = ft_create_elem(va_ptr, ft_get_flag(format, i));
				r = &li;
			}
			c -= 1;
		}
	}
	return (*r);
}
