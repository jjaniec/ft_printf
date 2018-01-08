/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar_t_to_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 14:11:07 by jjaniec           #+#    #+#             */
/*   Updated: 2018/01/08 19:27:50 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Convert a string of unicode characters to a char pointer
*/

char	*ft_wchar_t_to_str(wchar_t *ws)
{
	char				*r;
	unsigned int		i;
	unsigned int		j;


	i = -1;
	j = 1;
	r = (char *)malloc(ft_sizeof_wstr(ws) + sizeof(char));
	while (*ws)
	{
		while (ft_wchar_byte_to_char(ft_wchar_masklen(*ws), j, *ws))
		{
			r[++i] = ft_wchar_byte_to_char(ft_wchar_masklen(*ws), j, *ws);
			j++;
		}
		j = 1;
		*ws++;
	}
	r[i] = '\0';
	return (r);
}
