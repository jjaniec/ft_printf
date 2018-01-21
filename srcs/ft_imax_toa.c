/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imax_toa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 16:02:40 by jjaniec           #+#    #+#             */
/*   Updated: 2018/01/21 16:39:19 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static intmax_t	ft_itoa_slen(intmax_t n)
{
	intmax_t		i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char		    *ft_imax_toa(intmax_t n)
{
	intmax_t	i;
	char	    *s;

	i = ft_itoa_slen(n) - 1;
	if (!(s = (char *)malloc(sizeof(char) * i + 2)))
		return (NULL);
	s[i + 1] = '\0';
	if (n < 0)
		s[0] = '-';
	if (n == 0)
		s[i] = '0';
	n = ((n < 0) ? (-n) : (n));
	while (i > ((n > 0) ? (-1) : (0)))
	{
		s[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	return (s);
}
