/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_next_arg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 16:32:42 by jjaniec           #+#    #+#             */
/*   Updated: 2018/01/15 15:47:18 by jjaniec          ###   ########.fr       */
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
    while (ft_strchr(attr, format[*i]) != NULL)
        *i += 1;
}

/*
** Print arg and move on to the next one ont the linked list
*/

void          	ft_print_next_arg(t_arg **li, const char *restrict format, int *i)
{
    t_arg *arg;

    arg = *li;
	ft_putstr(arg->data_converted);
    if (ft_is_attribute(format[*i + 1]))
    {
       *i += 1;
        ft_skip_attributes(format, i, arg->attributes);
    }
    ft_skip_flag(format, i, arg->flag);
	*li = arg->next;
}
