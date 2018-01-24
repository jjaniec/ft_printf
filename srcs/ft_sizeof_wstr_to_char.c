/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sizeof_wstr_to_char.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 19:28:35 by jjaniec           #+#    #+#             */
/*   Updated: 2018/01/24 14:53:13 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Return the required space to store a wide char pointer in a char pointer
*/

int		ft_sizeof_wstr_to_char(wchar_t *ws)
{
	int		ret;

	ret = 0;
	while (*ws++)
		ret += ft_wchar_masklen(ws[0]);
	//printf("ret size: %d\n", ret);
	return (sizeof(char) * ret);
}
