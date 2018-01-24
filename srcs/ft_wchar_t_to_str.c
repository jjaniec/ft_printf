/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar_t_to_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 15:13:19 by jjaniec           #+#    #+#             */
/*   Updated: 2018/01/24 16:30:30 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Convert a unicode character to a char *
*/

char	*ft_wchar_t_to_str(wchar_t c)
{
	char	*s;
	int		i;
	int		masklen;

	masklen = ft_wchar_masklen(c);
	i = -1;
	s = (char *)malloc(masklen + 1);
	while (++i < masklen)
		s[i] = ft_wchar_byte_to_char(masklen, (i + 1), c);
	s[masklen] = '\0';
	return (s);
}
