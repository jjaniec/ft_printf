/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_minus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 16:25:24 by jjaniec           #+#    #+#             */
/*   Updated: 2018/01/16 17:24:21 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Apply minus attribute on content of arg $e
*/

void    ft_apply_attr_minus(t_arg **e)
{
    char    *s;

    if ((*e)->width)
    {
        s = ft_strjoin_free((*e)->data_converted, ft_generate_width(e));
        if (s != NULL)
        {
            free((*e)->data_converted);
            (*e)->data_converted = s;
        }
    }
}

