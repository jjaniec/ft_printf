/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 17:45:52 by jjaniec           #+#    #+#             */
/*   Updated: 2018/01/17 18:31:45 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Resize the char * of the data converted of $e as specified in width option
*/

void    ft_apply_width(t_arg **e)
{
    char    c;
    char    *s;
    int     l;

    l = ft_atoi((*e)->width) - ft_strlen((*e)->data_converted) + 1;
    if (l >= 2)
    {
        if ((*e)->attributes && \
            ft_strchr((*e)->attributes, '0') && !ft_strchr((*e)->attributes, '-'))
            c = '0';
        else
            c = ' ';
        if ((*e)->attributes && ft_strchr((*e)->attributes, '-'))
            s = ft_strjoin_free((*e)->data_converted, ft_generate_width(l, c));
        else
            s = ft_strjoin_free(ft_generate_width(l, c), (*e)->data_converted);
        if (s)
            (*e)->data_converted = s;

    }

}
