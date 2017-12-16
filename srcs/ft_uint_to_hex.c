/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint_to_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 16:30:04 by jjaniec           #+#    #+#             */
/*   Updated: 2017/12/16 17:41:58 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Return the hexadecimal char for value of $x
*/

static char				ft_get_hexchar(short x)
{
	if (x >= 0 && x <= 9)
		return (x + '0');
	return (x - 10 + 'a');
}

/*
** Get len of string to store hexadecimal version of $n
*/

static unsigned int		ft_get_pwr_tohex(unsigned int n)
{
	unsigned int	i;
	unsigned int	div;

	i = 1;
	div = 16;
	while (n / div > 0)
	{
		div *= 16;
		i++;
	}
	return (i);
}

/*
** Convert unsigned in $n in his hexadecimal version,
** stored in a string and returned
** used for 'x' flag of printf
*/

char					*ft_uint_to_hex(unsigned int n)
{
	int		i;
	char	*buf;
	int		buf_len;
	int		y;
	int		div;

	div = 1;
	i = 0;
	buf_len = ft_get_pwr_tohex(n);
	y = buf_len;
	buf = (char *)malloc(sizeof(char) * buf_len + 1);
	while (y-- != 1)
		div *= 16;
	while (i != buf_len - 0)
	{
		buf[i++] = ft_get_hexchar(((n % (div * 16)) / div));
		div /= 16;
	}
	buf[i] = '\0';
	return (buf);
}

/*
** ft_uint_to_hex with capitalization of letters
** used for 'X' flag of printf
*/

char					*ft_uint_to_hex_caps(unsigned int n)
{
	char	*tmp;

	tmp = ft_uint_to_hex(n);
	return (ft_str_capitalize(tmp));
}
