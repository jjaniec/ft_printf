/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 14:14:21 by jjaniec           #+#    #+#             */
/*   Updated: 2018/01/27 18:09:08 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Finds the len in bytes of a wide char converted in a char *
*/

int		ft_wchar_masklen(wint_t c)
{
  if (c < 0x0 || (c >= 0xD800 && c <= 0xF8FF) || \
      (c >= 0xAC00 && c <= 0xD7AF) )
        return (-1);
	if (c <= 254)
		return (1);
	if (c <= 0x7FF)
		return (2);
	if (c <= 0xFFFF)
		return (3);
    if (c >= 0x110000)
        return (-1);
	return (4);
}
