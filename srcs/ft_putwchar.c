/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 20:19:38 by jjaniec           #+#    #+#             */
/*   Updated: 2018/01/08 14:01:32 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Print a unicode character stored in an 'int' or 'wchar_t'
**
** We get the length in bytes of the character to know the mask to apply
** to print the char
** Then we need to move the content of each bytes to the last one
** to fill our following masks,
** for a 2 bytes char:
**    110xxxxx 10xxxxxx
** 3 bytes char:
**    1110xxxx 10xxxxxx 10xxxxxx
** 4:
**    11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
*/

void	ft_putwchar(wchar_t c)
{/*
	int				i;
	int				m;

	i = 0;
	i += ((c >= 0xFFFF) ? (6) : (0));
	i += ((c >= 0x7FF) ? (6) : (0));
	i += ((c >= 0x7F) ? (6) : (0));
	if (i == 18)
		m = 0xF0;
	else if (i == 12)
		m = 0xE0;
	else if (i == 6)
		m = 0xC0;
	ft_putchar((unsigned char)(((c >> i) & ((i == 0) ? (0x7F) : (0x3F))) | ((i == 0) ? (0x00) : (m))));
	i -= 6;
	printf("\ni: %d - m : %x\n", i, m);
	while (i >= 0)
	{
		ft_putchar((unsigned char)((c >> i) & 0x3F) | 0x80);
		i -= 6;
	}
*/	
	if (c <= 0x7F)
		ft_putchar((unsigned char)(((c >> 0) & 0x7F) | 0x00));
	else if (c <= 0x7FF)
	{
		ft_putchar((unsigned char)(((c >> 6) & 0x3F) | 0xC0));
		ft_putchar((unsigned char)(((c >> 0) & 0x3F) | 0x80));
	}
	else if (c <= 0xFFFF)
	{
		ft_putchar((unsigned char)(((c >> 12) & 0x3F) | 0xE0));
		ft_putchar((unsigned char)(((c >> 6) & 0x3F) | 0x80));
		ft_putchar((unsigned char)(((c >> 0) & 0x3F) | 0x80));
	}
	else if (c <= 0x1FFFFF)
	{
		ft_putchar((unsigned char)((c >> 18) & 0x3F) | 0xF0);
		ft_putchar((unsigned char)((c >> 12) & 0x3F) | 0x80);
		ft_putchar((unsigned char)((c >> 6) & 0x3F) | 0x80);
		ft_putchar((unsigned char)((c >> 0) & 0x3F) | 0x80);
	}
}
