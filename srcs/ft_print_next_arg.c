/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_next_arg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 16:32:42 by jjaniec           #+#    #+#             */
/*   Updated: 2018/01/30 22:44:34 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Move forward in format until flag is skiped
*/

static void		ft_skip_flag(const char *restrict format, int *i, char *flag)
{
	int   j;

	j = 0;
	if (format[*i] == '%')
		*i += 1;
	while (format[*i] != flag[j])
		*i += 1;
	while (flag[j] && flag[j] == format[*i])
	{
		j++;
		*i += 1;
	}
}

static int      ft_calc_width_len(char *s)
{
    int     i;

    i = 0;
    while (s[i] == *s)
        i++;
    return (i);
}

/*
** Print 0 character to fit real printf in some cases
*/

static void     ft_print_0(int *r)
{
    ft_putchar(0);
    *r += 1;
}

/*
** Print data as a string of current argument and move on to the next one
*/

void			ft_print_next_arg(t_arg **li, const char *restrict format, int *i, int *r)
{
	t_arg *arg;

	arg = *li;
	if (*(arg->data_converted))
	{
        if (*(arg->flag) == 'c' && arg->attributes && ft_strchr(arg->attributes, '-'))
            if (ft_strchr(arg->data_converted, 0) && arg->width && !arg->data_converted[ft_atoi(arg->width) - 1])
                ft_print_0(r);
        ft_calc_width_len(arg->data_converted);
		ft_putstr(arg->data_converted);
		*r += ft_strlen(arg->data_converted);
        if (*(arg->flag) == 'c' && (!arg->attributes || (arg->attributes && !ft_strchr(arg->attributes, '-'))))
            if (ft_strchr(arg->data_converted, 0) && arg->width && !arg->data_converted[ft_atoi(arg->width) - 1])
                ft_print_0(r);
	}
	else if (*(arg->flag) == 'c' || *(arg->flag) == 'C')
        ft_print_0(r);
	ft_skip_flag(format, i, arg->flag);
	*li = arg->next;
	if (arg)
		ft_free_elem(arg);
}
