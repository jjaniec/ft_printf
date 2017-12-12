/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_arg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 14:25:16 by jjaniec           #+#    #+#             */
/*   Updated: 2017/12/12 14:37:29 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Convert argument of any type in a string to be printed
*/

char	*ft_convert_arg(va_list va_ptr, char *flag)
{
	char	*s;
	char	(*f[30])(void *);

	f[0] = ft_itoa;
	if (!strcmp(flag, "d"))
		return ((*f[0])(va_arg(va_ptr, int)));
	return (NULL);
}
