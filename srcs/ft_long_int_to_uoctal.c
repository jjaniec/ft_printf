/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_int_to_uoctal.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 19:18:18 by jjaniec           #+#    #+#             */
/*   Updated: 2018/01/24 16:30:24 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Convert a long int passed as parameter in it's unsigned octal form
*/

char	*ft_long_int_to_uoctal(const long int n)
{
	return ((n < 0) ? (ft_uint_to_octal(n * -1)) : (ft_uint_to_octal(n)));
}
