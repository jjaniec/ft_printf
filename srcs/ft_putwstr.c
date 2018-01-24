/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 13:07:28 by jjaniec           #+#    #+#             */
/*   Updated: 2018/01/24 16:30:29 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Print a string of unicode/wide characters
*/

void	ft_putwstr(wchar_t *s)
{
	while (*s++)
		ft_putwchar(s[-1]);
}
