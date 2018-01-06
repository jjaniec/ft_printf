/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 20:19:38 by jjaniec           #+#    #+#             */
/*   Updated: 2018/01/06 18:20:59 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putwchar(wchar_t c)
{
	if (c <= 0x7F)
		ft_putchar((char)c);
	else if (c <= 0x7FF)
	{
		ft_putchar((unsigned char)((c >> 6) | 0xC0));
		ft_putchar((unsigned char)((c & 0x3F) | 0x80));
	}/*
	else if (c <= 0xFFFF)
	{
		
	}
	else if (c <= 0x1FFFFF)
	{
		
	}*/
}

int		main()
{
	ft_putwchar('a');
	ft_putwchar(0xA9);
	ft_putwchar(0x851);
	ft_putwchar(0xFFFFF);


	unsigned char c;
    c = 0xe1;
    write(1, &c, 1);
    c = 0x88;
    write(1, &c, 1);
    c = 0xb4;
    write(1, &c, 1);
    c = 0x0a;
    write(1, &c, 1);
	return (0);
}
