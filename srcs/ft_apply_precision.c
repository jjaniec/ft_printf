/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 14:05:23 by jjaniec           #+#    #+#             */
/*   Updated: 2018/01/20 15:24:51 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Apply precision on converted element
*/

void    ft_apply_precision(t_arg **e)
{
    if (ft_strchr((*e)->flag, 's'))
        (*e)->data_converted = ft_strsub_free(\
            (*e)->data_converted, 0, ft_atoi((*e)->precision));
}
