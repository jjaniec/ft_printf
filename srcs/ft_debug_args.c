/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 18:49:18 by jjaniec           #+#    #+#             */
/*   Updated: 2018/01/16 17:29:18 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Cycle through arg structures to print their content
*/

void	ft_debug_args(const char *restrict format, t_arg *args)
{
	int		i;
	t_arg	*li;

	li = args;
	i = 1;
    printf("Args count : %d\n", ft_count_args(format));
	while (li->next || li)
	{
		printf("Arg[%d]:\n\
				\tdata_converted: [%s]\n\
				\tflag: [%s]\n\
                \t\t\twidth: [%s]\n\
				\tprecision: [%s]\n\
                \t\t\tattributes: [%s]\n", i, li->data_converted, li->flag, li->width, li->precision, li->attributes);
        if (li && li->next)
		    li = li->next;
        else
            break;
		i++;
	}
}
