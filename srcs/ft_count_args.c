/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 16:21:54 by jjaniec           #+#    #+#             */
/*   Updated: 2017/12/11 16:24:32 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Counts args passed in printf function by counting number of '%'
*/

int		ft_count_args(const char *restrict format)
{
	int		i;
	int		t;

	t = 0;
	i = 0;
	while (format[i++])
		t += ((format[i] == '%') ? (1) : (0));
	printf("Number of args : %d\n", t);
	return (t);
}
