/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 14:05:23 by jjaniec           #+#    #+#             */
/*   Updated: 2018/01/20 16:49:43 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Apply precision on converted element
*/

void    ft_apply_precision(t_arg **e)
{
    int     x;

    x = 0;
    if (ft_strchr((*e)->flag, 's'))
        (*e)->data_converted = ft_strsub_free(\
            (*e)->data_converted, 0, ft_atoi((*e)->precision));
    if (ft_strchr((*e)->flag, 'd') || ft_strchr((*e)->flag, 'i'))
    {
      x = (ft_atoi((*e)->precision) - ft_strlen((*e)->data_converted) + 1);
        if (x > 0)
            (*e)->data_converted = ft_strjoin_free(ft_generate_width(x, '0'), (*e)->data_converted);
    }
}
