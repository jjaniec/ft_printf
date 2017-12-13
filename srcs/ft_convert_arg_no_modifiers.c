/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_arg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 14:25:16 by jjaniec           #+#    #+#             */
/*   Updated: 2017/12/13 21:03:31 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Convert argument of any type in a string to be printed
*/

char	*ft_convert_arg_no_modifiers(va_list va_ptr, char *flag)
{
	char	*s;
	char	*(*f[100])(void *);

	f[('d' - 'a')] = &ft_itoa;
	if (ft_strlen(flag) == 1)
		if (flag[0] == 's')
			return (va_arg(va_ptr, char *));
		else
			return ((*f[flag[0] - 'a'])((int)va_arg(va_ptr, int)));
	return (NULL);
}
