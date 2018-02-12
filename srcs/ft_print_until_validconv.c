/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_until_validconv.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 21:51:21 by jjaniec           #+#    #+#             */
/*   Updated: 2018/02/12 18:13:14 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
**
*/

static int  ft_invalid_conv_present(const char *restrict format, int i)
{
    int     a;

    //printf("fmt j |%s|\n", format + i);
    while (format[i])
    {
        if (format[i] == '%')
        {
            if (format[i + 1] == '%')
                a = 1;
            else
                a = !ft_is_flag(format, i);
            //printf("a : %d |%s| \n", a, format + i);
            return (a);
        }
        i++;
    }
    return (0);
}

/*
** Handle unicode errors and print content of percent conversions 
** until a valid conversion is found
*/

int         ft_print_until_validconv(const char *restrict format, int i)
{
    int     j;
    int     r;

    j = i - 1;
    r = 0;
    //printf("fmt: |%s|\n", format + i);
    while (format[j] && j > 0 && \
        !(format[j] == '%' && format[j + 1] != '%' && ft_is_flag(format, j)))
        j--;
    if (j == 0 || !ft_invalid_conv_present(format, j + 2))
        return (-1);
    //printf("fmt J %d : |%s|\n", j, format + j);
    if (ft_is_flag(format, j))
        while (format[j] && !ft_is_flag_c(format[j]))
            j++;
    j++;
    while (j < i)
    {
        if (format[j] == '%')
        {
            ft_printf_percent(format, &j, &r);
            if (format[j] == '%')
            {
                ft_putchar_printf(format[j], &r);
                if (!ft_invalid_conv_present(format, j + 1))
                    break;
            }
            else
            {
                if (!ft_invalid_conv_present(format, j + 1))
                    break;
                ft_putchar_printf(format[j], &r);
            }
        }
        else
            ft_putchar_printf(format[j], &r);
        j++;
    }
    return (-1);
}
