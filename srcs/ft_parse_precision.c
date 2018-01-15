/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 18:54:43 by jjaniec           #+#    #+#             */
/*   Updated: 2018/01/15 19:22:55 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Return a char pointer containing precision options
** if none are found return NULL
*/

char	*ft_parse_precision(const char *restrict format, int *pos)
{
	int		x;
	char	*s;

	if (format[*pos + 1] == '.')
		*pos += 1;
	else
		return (NULL);
	x = *pos;
	s = ft_parse_width(format, &x);
	*pos = x;
	return (s);
}
