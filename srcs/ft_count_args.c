/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 16:21:54 by jjaniec           #+#    #+#             */
/*   Updated: 2018/01/05 19:24:23 by jjaniec          ###   ########.fr       */
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
	i = -1;
	while (format[++i])
		if (format[i] == '%' && format[i + 1] != '%')
		{
			printf("ft_get_flag %s", ft_get_flag(format, i));
			t += (ft_get_flag(format, i)[0]) ? (1) : (0);
		}
	printf("Number of args : %d\n", t);
	return (t);
}
