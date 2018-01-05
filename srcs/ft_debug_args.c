/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 18:49:18 by jjaniec           #+#    #+#             */
/*   Updated: 2018/01/05 19:11:25 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Cycle through arg structures to print their content
*/

void	ft_debug_args(t_arg *args)
{
	int		i;
	t_arg	*li;

	li = args;
	i = 1;
	while (li->next)
	{
		printf("Arg[%d]:\n\
				\tdata_converted: [%s]\n\
				\tflag: [%s]\n\
				\tprecision: [%s]\n", i, li->data_converted, li->flag, li->precision);
		li = li->next;
		i++;
	}
	if (li)
	{
		printf("Arg[%d]:\n\
				\tdata_converted: [%s]\n\
				\tflag: [%s]\n\
				\tprecision: [%s]\n", i, li->data_converted, li->flag, li->precision);
	}
}
