/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar_tptr_to_str.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 14:11:07 by jjaniec           #+#    #+#             */
/*   Updated: 2018/01/27 15:44:27 by jjaniec          ###   ########.fr       */
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

    if (!ws)
        return (ft_strdup("(null)"));
	i = -1;
	j = 1;
	r = (char *)malloc(ft_sizeof_wstr_to_char(ws) + sizeof(char));
	while (*ws++)
	{
		while (ft_wchar_byte_to_char(ft_wchar_masklen(ws[-1]), j, ws[-1]))
		{
			r[++i] = ft_wchar_byte_to_char(ft_wchar_masklen(ws[-1]), j, ws[-1]);
			j++;
		}
		j = 1;
	}
	r[i + 1] = '\0';
	return (r);
}
