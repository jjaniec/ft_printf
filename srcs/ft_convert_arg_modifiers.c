/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_arg_modifiers.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 15:08:13 by jjaniec           #+#    #+#             */
/*   Updated: 2018/01/21 16:20:59 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Convert argument of any type with modifiers in a char pointer to print it
*/

char    *ft_convert_arg_modifiers(va_list va_ptr, t_arg **e)
{   
    if (e)
  /*
    if ((*e)->modifiers && (*e)->flag)
    {*/
        /*if (ft_strcmp("l", (*e)->modifiers) == 0)
            if (ft_is_conv_numeric(e))*/
                return (ft_imax_toa(va_arg(va_ptr, long int)));
                
            /*
    }*/
    return (NULL);
}
