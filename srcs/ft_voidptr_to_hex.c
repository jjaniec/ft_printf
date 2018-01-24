/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_voidptr_to_hex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 18:59:35 by jjaniec           #+#    #+#             */
/*   Updated: 2018/01/24 16:30:45 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Converts raw data to a char * of hex values
*/

char	*ft_voidptr_to_hex(void *data)
{
	uintmax_t	x;
	char		*s;
	char		*prefix;

	x = (uintmax_t)data;
	s = ft_uint_to_hex(x);
	prefix = ft_strdup("0x");
	return (ft_strjoin_free(prefix, s));
}
