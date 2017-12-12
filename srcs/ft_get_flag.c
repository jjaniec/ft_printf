/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 21:39:21 by jjaniec           #+#    #+#             */
/*   Updated: 2017/12/12 13:11:57 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Return 0 if $c, or $c$c2 is a flag of printf, otherwise
** returns 1
*/

int		ft_is_flag_c1(char c)
{
	if (c == 's' || \
			c == 'S' || \
			c == 'p' || \
			c == 'd' || \
			c == 'D' || \
			c == 'i' || \
			c == 'o' || \
			c == 'O' || \
			c == 'u' || \
			c == 'U' || \
			c == 'x' || \
			c == 'X' || \
			c == 'c' || \
			c == 'C' || \
			c == '%' || \
			c == '#' || \
			c == '0' || \
			c == '-' || \
			c == '+' || \
			c == ' ' || \
			c == 'h' || \
			c == 'l' || \
			c == 'j' || \
			c == 'z')
		return (0);
	return (1);
}

/*
**
*/

int		ft_is_flag_c2(char c1, char c2)
{
	if (c1 == '\0')
		return (1);
	if (c1 == 'l' && c2 == 'u')
		return (0);
	return (1);
}

/*
**
*/

char	*ft_get_flag(const char *restrict format, int *pos)
{
	char	flag[3];

	if (ft_is_flag_c1(format[*pos + 1]))
	{
		flag[0] = format[*pos + 1];
		if (format[*pos + 2] && ft_is_flag_c2(format[*pos + 2]))
			flag[1] = format[*pos + 2];
		else
			flag[1] = '\0';
	}
	else
	{
		flag[0] = '\0';
		flag[1] = '\0';
	}
	flag[2] = '\0';
	*pos += ft_strlen(flag);
	return (flag);
}
