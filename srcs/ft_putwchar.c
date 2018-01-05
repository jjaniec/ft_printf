/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 20:19:38 by jjaniec           #+#    #+#             */
/*   Updated: 2018/01/05 21:21:11 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putwchar(wchar_t c)
{
	if (c <= 0x7F)
		ft_putchar((char)c);
	else if (c <= 0x7FF)
	{
		
	}
	else if (c <= 0xFFFF)
	{
		
	}
	else if (c <= 0x1FFFFF)
	{
		
	}
}
