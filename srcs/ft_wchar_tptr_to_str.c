/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar_tptr_to_str.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 14:11:07 by jjaniec           #+#    #+#             */
/*   Updated: 2018/01/31 19:49:56 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Convert a string of unicode characters to a char pointer
*/

char	*ft_wchar_tptr_to_str(wchar_t *ws)
{
	char				*r;
	unsigned int		i;
	unsigned int		j;
	int					maskl;

	if (!ws)
		return (ft_strdup("(null)"));
	i = 0;
	j = 1;
	r = (char *)malloc(ft_sizeof_wstr_to_char(ws) + 2);
	while (*ws)
	{
		maskl = ft_wchar_masklen(*ws);
		if (maskl == -1)
			return (NULL);
		while (ft_wchar_byte_to_char(maskl, j, *ws))
		{
			r[i++] = ft_wchar_byte_to_char(maskl, j, *ws);
			j++;
		}
		j = 1;
		ws++;
	}
	r[i] = '\0';
	return (r);
}
