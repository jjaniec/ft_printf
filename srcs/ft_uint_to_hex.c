/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint_to_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 16:30:04 by jjaniec           #+#    #+#             */
/*   Updated: 2017/12/16 17:10:44 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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
	ft_printf("Ret_pwrhex : %d\n", i);
	return (i);
}

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
		buf[i++] = n % (div * 16) / div + '0';
		//printf("buf%d = %d\n", i, n % (div * 16) / div);
		div /= 16;
	}
	buf[i] = '\0';
	return (buf);
}
