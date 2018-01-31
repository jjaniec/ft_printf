/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_arglist.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 14:55:13 by jjaniec           #+#    #+#             */
/*   Updated: 2018/01/31 19:58:22 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Free the arglist, used in case of an error
*/

void	*ft_free_arglist(t_arg *l)
{
	t_arg *o;

    o = NULL;
	while (l)
	{
		o = l;
	   	l = l->next;
	   	ft_free_elem(o);
	}
	return (NULL);
}

/*
** Create a linked list with all arguments passed in parameters
** it stores content converted as a char * in e.data_converted
** argument flag in e.flag and precision of argument to print in e.precision
*/

t_arg	*ft_create_arglist(va_list va_ptr, const char *restrict format)
{
	t_arg	*li;
	t_arg	*r;
	int		i;

	i = -1;
	li = NULL;
	r = NULL;
	while (format[++i])
		if (format[i] == '%' && ft_is_flag(format, i))
		{
			if (li != NULL)
			{
				li->next = ft_create_elem(va_ptr, format, i);
				if (!li)
					return (ft_free_arglist(r));
				li = li->next;
			}
			else
			{
				li = ft_create_elem(va_ptr, format, i);
				r = li;
			}
		}
	return (r);
}
