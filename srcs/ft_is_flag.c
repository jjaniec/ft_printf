/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 21:58:27 by jjaniec           #+#    #+#             */
/*   Updated: 2018/01/15 18:33:06 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Return 1 if passed position in format is the beginning of a flag
** otherwise return 0
*/

int     ft_is_flag(const char *restrict format, int i)
{
    int     a;

    a = i;
    if (!(format[i] == '%' && format[i + 1] != '%'))
        return (0);
    if (ft_get_flag(format, i)[0])
        return (1);
    if (ft_is_attribute(format[i + 1]) || ft_isdigit(format[i + 1]))
    {
        ft_parse_attributes(format, &a);
        ft_parse_width(format, &a);
        if (ft_get_flag(format, a)[0])
            return (1);
    }
    return (0);
}
