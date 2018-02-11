/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 14:42:31 by jjaniec           #+#    #+#             */
/*   Updated: 2018/02/11 15:59:11 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** 
*/

static t_arg    *ft_handle_S_error(t_arg *e)
{
    int     Sprec;
    int     errpos;

    errpos = -1;
    if (e->precision)
    {
        Sprec = ft_atoi(e->precision);
        while (e->data_converted[++errpos] != '!')
            ;/*
        printf("errpos : %d - sprec: %d\n", errpos, Sprec);*/
        if (Sprec <= errpos)
        {
            e->data_converted = ft_strsub_free(e->data_converted, 0, Sprec);
            return (e);
        }
    }
    return (ft_free_elem(e));
}

/*
** Handle unicode error cases in strings, when a defective unicode is found,
** return an element with data as 'err' (non possible in C/lc conversions)
** and his conversion as "!" to
** let know ft_print_next_arg to stop at previous element & return -1,
** otherwise, free the element and return -1
*/

static t_arg   *ft_handle_error(t_arg *e)
{
    if ((e->flag) && (*(e->flag) == 'S' || (*(e->flag) == 's' && e->modifiers && *(e->modifiers) == 'l')))
        return (ft_handle_S_error(e));
    if (*(e->flag) == 'C' || \
        (*(e->flag) == 'c' && (e->modifiers) && *(e->modifiers) == 'l'))
    {
        free(e->data_converted);
        free(e->flag);
        e->data_converted = ft_strdup("err");
        e->flag = ft_strdup("!");
        return (e);
    }
	return (ft_free_elem(e));
}

/*
** Create and return an element of type t_arg to store data of an argument
** and all of it's options (precision / width / modifiers / flags)
*/

t_arg	        *ft_create_elem(va_list va_ptr, const char *restrict format, int pos)
{
	t_arg	*e;

	e = (t_arg *)malloc(sizeof(t_arg));
	e->attributes = ft_parse_attributes(format, &pos);
	e->width = ft_parse_width(format, &pos);
	if (format[pos + 1] == '.')
		e->precision = ft_parse_precision(format, &pos);
	else
		e->precision = NULL;
	if (format[pos + 1] == 'l' || format[pos + 1] == 'h' || \
		format[pos + 1] == 'z' || format[pos + 1] == 'j')
		e->modifiers = ft_parse_modifiers(format, &pos);
	else
		e->modifiers = NULL;
	e->flag = ft_get_flag(format, pos);
	if (e->modifiers)
		e->data_converted = ft_convert_arg_modifiers(va_ptr, &e);
	else
		e->data_converted = ft_convert_arg_no_modifiers(va_ptr, e->flag[0]);
	if (!e->data_converted || (e->data_converted && ft_strchr(e->data_converted, '!')))
		return (ft_handle_error(e));
	ft_apply_options(&e);
	e->next = NULL;
	return (e);
}
