/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint_to_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 20:54:02 by jjaniec           #+#    #+#             */
/*   Updated: 2018/01/24 16:30:29 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Calculate len required to store x in a string
*/

static int	ft_uint_to_str_slen(unsigned int x)
{
	int		i;

	i = 0;
	while (x > 0)
	{
		x /= 10;
		i++;
	}
	return (i);
}

/*
** Convert x as a string
*/

char	*ft_uint_to_str(unsigned int x)
{
	char	*s;
	int		i;

	if (x == 0)
		return (ft_strdup("0"));
	i = ft_uint_to_str_slen(x);
	s = malloc(sizeof(char) * i + 1);
	s[i] = '\0';
	i--;
	while (i > -1 && x!= 0)
	{
		s[i] = (x % 10) + '0';
		x /= 10;
		i--;
	}
	return (s);
}
