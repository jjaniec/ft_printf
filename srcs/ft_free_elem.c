/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_elem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 21:18:50 by jjaniec           #+#    #+#             */
/*   Updated: 2018/01/18 14:49:08 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Free all elements of a t_arg structure
*/

void    ft_free_elem(t_arg *e)
{
    if (!ft_strchr(e->flag, 's') && e->data_converted)
        free(e->data_converted);
    if (e->flag)
        free(e->flag);
    if (e->width)
        free(e->width);
    if (e->precision)
        free(e->precision);
    if (e->attributes)
        free(e->attributes);
    free(e);
}
