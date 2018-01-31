/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 21:58:27 by jjaniec           #+#    #+#             */
/*   Updated: 2018/01/31 18:26:18 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Free ptr if ptr != NULL
*/

static int		ft_free_ptr(void *p, int r)
{
	if (p)
		free(p);
	p = NULL;
	return (r);
}

/*
** Return 1 if passed position in format is the beginning of a flag
** otherwise return 0
*/

int				ft_is_flag(const char *restrict format, int i)
{
	int		a;
	char	*t;
	char	*t2;

	a = i;
	if (!(format[i] == '%' && format[i + 1] != '%'))
		return (0);
	t = ft_get_flag(format, i);
	t2 = ft_get_flag(format, i + 1);
	if (t[0] || (format[i + 1] == '.' && t2[0]))
	{
		free(t);
		return ((ft_free_ptr(t2, 1)));
	}
	free(t2);
	if (ft_is_attribute(format[i + 1]) || ft_isdigit(format[i + 1]) || format[i + 1] == '.')
	{
		ft_free_ptr(ft_parse_attributes(format, &a), 0);
		ft_free_ptr(ft_parse_width(format, &a), 0);
		if (format [a] == '.' || format[a + 1] == '.')
			ft_free_ptr(ft_parse_precision(format, &a), 0);
		free(t);
		t = ft_get_flag(format, a);
		if (t[0])
			return (ft_free_ptr(t, 1));
	}
	return (ft_free_ptr(t, 0));
}
