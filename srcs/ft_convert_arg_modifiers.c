/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_arg_modifiers.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 15:08:13 by jjaniec           #+#    #+#             */
/*   Updated: 2018/01/21 18:37:46 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Convert argument of any type with modifiers in a char pointer to print it
*/

char    *ft_convert_arg_modifiers(va_list va_ptr, t_arg **e)
{   
    if ((*e)->modifiers && (*e)->flag)
    {
        if (ft_strcmp("l", (*e)->modifiers) == 0)
            if ((*e)->flag[0] == 'u')
                return (ft_imax_toa(va_arg(va_ptr, unsigned long int)));
            if ((*e)->flag[0] == 'c')
                return (ft_wchar_t_to_str(va_arg(va_ptr, wint_t)));
            if (ft_is_conv_numeric(e))
                return (ft_imax_toa(va_arg(va_ptr, long int)));
        if (ft_strcmp("h", (*e)->modifiers) == 0)
            if ((*e)->flag[0] == 'u')
                return (ft_imax_toa((unsigned short int)va_arg(va_ptr, int)));
            if (ft_is_conv_numeric(e))
                return (ft_imax_toa((short int)va_arg(va_ptr, int)));
        if (ft_strcmp("ll", (*e)->modifiers) == 0)
            if ((*e)->flag[0] == 'u')
                return (ft_imax_toa(va_arg(va_ptr, unsigned long long int)));
            if (ft_is_conv_numeric(e))
                return (ft_imax_toa(va_arg(va_ptr, long long int)));
        if (ft_strcmp("hh", (*e)->modifiers) == 0)
            if ((*e)->flag[0] == 'u')
                return (ft_imax_toa((char)va_arg(va_ptr, unsigned int)));
            if (ft_is_conv_numeric(e))
                return (ft_imax_toa((char)va_arg(va_ptr, int)));
        if (ft_strcmp("j", (*e)->modifiers) == 0)
            if ((*e)->flag[0] == 'u')
                return (ft_imax_toa(va_arg(va_ptr, uintmax_t)));
            if (ft_is_conv_numeric(e))
                return (ft_imax_toa(va_arg(va_ptr, intmax_t)));
        if (ft_strcmp("z", (*e)->modifiers) == 0)
            if ((*e)->flag[0] == 'u')
                return (ft_imax_toa(va_arg(va_ptr, ssize_t)));
            if (ft_is_conv_numeric(e))
                return (ft_imax_toa(va_arg(va_ptr, size_t)));

    }
    return (NULL);
}
