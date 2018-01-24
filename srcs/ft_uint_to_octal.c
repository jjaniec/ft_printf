/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint_to_octal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 20:12:15 by jjaniec           #+#    #+#             */
/*   Updated: 2018/01/24 17:29:41 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Get len of string to store $n in its octal form
*/

static uintmax_t	 ft_get_pwr_tooctal(const uintmax_t n)
{
	uintmax_t	 i;
	uintmax_t	 div;

	i = 1;
	div = 8;
	while (n / div > 0)
	{
		div *= 8;
		i++;
	}
	return (i);
}

/*
** Convert an uintmax_t passed as parameter in it's octal form
** stored in a char *
*/

char	*ft_uint_to_octal(const uintmax_t n)
{
	intmax_t		i;
	char	        *buf;
	intmax_t		buf_len;
	intmax_t		y;
	intmax_t		div;

	div = 1;
	i = 0;
	buf_len = ft_get_pwr_tooctal(n);
	y = buf_len;
	buf = (char *)malloc(sizeof(char) * buf_len + 1);
	while (y-- != 1)
	  div *= 8;
	while (i != buf_len - 0)
	{
		buf[i++] = ((n % (div * 8)) / div) + '0';
		div /= 8;
	}
	buf[i] = '\0';
	return (buf);
}
