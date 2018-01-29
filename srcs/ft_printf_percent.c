/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 16:43:59 by jjaniec           #+#    #+#             */
/*   Updated: 2018/01/29 17:35:08 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static t_arg    *ft_create_temp_elem(const char *restrict format, int *pos)
{
    t_arg *e;

	e = (t_arg *)malloc(sizeof(t_arg));
	e->attributes = ft_parse_attributes(format, pos);
	e->width = ft_parse_width(format, pos);
	if (format[*pos + 1] == '.')
	    e->precision = ft_parse_precision(format, pos);
	else
	    e->precision = NULL;
	if (format[*pos + 1] == 'l' || format[*pos + 1] == 'h' || \
	    format[*pos + 1] == 'z' || format[*pos + 1] == 'j')
	    e->modifiers = ft_parse_modifiers(format, pos);
	else
	    e->modifiers = NULL;
    e->flag = ft_strdup(" ");
    e->flag[1] = '\0';
    e->data_converted = ft_strdup(e->flag);
	ft_apply_options(&e);
	e->next = NULL;
    return (e);
}


static int      ft_skip_to_char(const char *restrict format, int *pos)
{
    int     a;

    a = *pos;
    while (ft_isdigit(format[a]))
        a += 1;
    if (format[a] == '.')
        a += 1;
    while (ft_isdigit(format[a]))
        a += 1;
    return (a);
}

void    ft_printf_percent(const char *restrict format, int *pos, int *r)
{
	t_arg	*e;
    int     a;

    if (format[*pos] == '%' && format[*pos + 1] == '%')
        *pos += 1;
    else if (format[*pos] == '%' && !format[*pos + 1])
    {
        *pos += 1;
        *r = 0;
    }
    else if (format[*pos + 1])
    {
        a = ft_skip_to_char(format, pos);
        e = ft_create_temp_elem(format, pos);
        e->flag[0] = format[a];
	    ft_putstr(e->data_converted);
        *pos += 1;
        *r += ft_strlen(e->data_converted);
        while (format[*pos] != e->flag[0])
            *pos += 1;
        *pos += 1;
    }
}
