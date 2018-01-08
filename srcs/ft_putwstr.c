/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 13:07:28 by jjaniec           #+#    #+#             */
/*   Updated: 2018/01/08 13:48:23 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putwstr(wchar_t *s)
{/*
	int		i;

	i = -1;
	while (s[++i])
		ft_putwchar(s[i]);*/
	while (*s++)
		ft_putwchar(s[-1]);
}
/*
int		main()
{
	wchar_t			*s;

	s = (wchar_t *)malloc(sizeof(wchar_t) * 4);

	s[0] = '\0';
	s[0] = 0xA9;
	s[1] = 0x851;
	s[2] = 0x100D7;
	s[3] = '\0';
	ft_putwstr(s);
}*/
