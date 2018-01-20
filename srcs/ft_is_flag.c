/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 21:58:27 by jjaniec           #+#    #+#             */
/*   Updated: 2018/01/20 14:19:39 by jjaniec          ###   ########.fr       */
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
    char    *t;
    char    *t2;

    a = i;
    if (!(format[i] == '%' && format[i + 1] != '%'))
        return (0);
    t = ft_get_flag(format, i);
    t2 = ft_get_flag(format, i + 1);
    if (t[0] || (format[i + 1] == '.' && t2[0]))
        return (1);
    free(t2);
    if (ft_is_attribute(format[i + 1]) || ft_isdigit(format[i + 1]) || format[i + 1] == '.')
    {
        ft_parse_attributes(format, &a);
        ft_parse_width(format, &a);
        if (format [a] == '.' || format[a + 1] == '.')
            ft_parse_precision(format, &a);
        free(t);
        t = ft_get_flag(format, a);
        if (t[0])
        {
            free(t);
            return (1);
        }
    }
    free(t);
    return (0);
}
