/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_next_arg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 16:32:42 by jjaniec           #+#    #+#             */
/*   Updated: 2018/01/16 14:15:18 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Move forward in format until flag is skiped
*/

static void     ft_skip_flag(const char *restrict format, int *i, char *flag)
{
    int   j;

    j = 0;
    *i += 1;
    if (format[*i] == '.')
        *i += 1;
    while (flag[j] && flag[j] == format[*i])
    {
        j++;
        *i += 1;
    }
}

/*
** Move forward in format until attributes of flag are skipped
*/

static void     ft_skip_attributes(const char *restrict format, 
    int *i, char *attr)
{
    *i += 1;
    while (ft_strchr(attr, format[*i + 1]))
        *i += 1;
}

/*
** Move forward in format until width options are skipped
*/

static void     ft_skip_width(const char *restrict format,
    int *i, char *width)
{
    int     j;

    j = 0;
    *i += 1;
    while (width[j] && format[*i] == width[j])
    {
        *i += 1;
        j += 1;
    }
}

/*
** Move forward in format until precision params are skipped
*/

static void     ft_skip_precision(const char *restrict format,
    int *i, char *precision)
{
    int     j;

    j = 0;
    if (precision && format[*i] == '.' && ft_isdigit(format[*i + 1]))
    {
        *i += 1;
        while (precision[j] && format[*i] == precision[j])
        {
            *i += 1;
            j++;
        }
    }
}

/*
** Print arg and move on to the next one ont the linked list
*/

void          	ft_print_next_arg(t_arg **li, const char *restrict format, int *i)
{
    t_arg *arg;

    arg = *li;
	ft_putstr(arg->data_converted);
    if (ft_is_attribute(format[*i + 1]) && arg->attributes)
        ft_skip_attributes(format, i, arg->attributes);
    if (ft_isdigit(format[*i + 1]) && arg->width)
        ft_skip_width(format, i, arg->width);
    if (format[*i] == '.' && arg->precision)
        ft_skip_precision(format, i, arg->precision);
    ft_skip_flag(format, i, arg->flag);
	*li = arg->next;
}
