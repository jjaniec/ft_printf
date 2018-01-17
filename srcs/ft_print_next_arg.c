/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_next_arg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 16:32:42 by jjaniec           #+#    #+#             */
/*   Updated: 2018/01/17 22:15:40 by jjaniec          ###   ########.fr       */
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
    while (format[*i] != flag[j])
        *i += 1;
    while (flag[j] && flag[j] == format[*i])
    {
        j++;
        *i += 1;
    }
}

/*
** Print data as a string of current argument and move on to the next one
*/

void          	ft_print_next_arg(t_arg **li, const char *restrict format, int *i)
{
    t_arg *arg;

    arg = *li;
	ft_putstr(arg->data_converted);
    ft_skip_flag(format, i, arg->flag);
	*li = arg->next;
    /*if (arg)
        ft_free_elem(arg);*/
}
