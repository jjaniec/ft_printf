/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uimax_toa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 17:29:51 by jjaniec           #+#    #+#             */
/*   Updated: 2018/01/25 17:31:49 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Calculate len of string to store n in a char *
*/

static intmax_t	ft_itoa_slen(uintmax_t n)
{
	uintmax_t		i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

/*
** Store n in a char *
*/

char			*ft_uimax_toa(uintmax_t n)
{
	intmax_t	i;
	char		*s;

	i = ft_itoa_slen(n) - 1;
	if (!(s = (char *)malloc(sizeof(char) * i + 2)))
		return (NULL);
	s[i + 1] = '\0';
	if (n == 0)
		s[i] = '0';
	while (i > -1)
	{
		s[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	return (s);
}
