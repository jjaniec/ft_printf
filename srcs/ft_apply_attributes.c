/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_attributes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 15:20:05 by jjaniec           #+#    #+#             */
/*   Updated: 2018/01/16 15:43:23 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Apply attributes on converted argument passed as parameter
**
** -
** The output is left justified in its field, not right justified (the default).
** +
** Signed numbers will always be printed with a leading sign (+ or -).
** space
** Positive numbers are preceded by a space (negative numbers by a - sign).
** 0
** For numeric conversions, pad with leading zeros to the field width.
** #
** An alternative output form. For o, the first digit will be '0'.
** For x or X, "0x" or "0X" will be prefixed to a non-zero result.
*/

void 	ft_apply_attributes(t_arg **e)
{
	if (ft_strchr((*e)->attributes, ' ') && !ft_strchr((*e)->attributes, '+'))
		ft_apply_attr_space(e);
	if (ft_strchr((*e)->attributes, '-'))
		ft_apply_attr_minus(e);
}
/*
int 	main()
{
	t_arg *a;

	a->data_converted = ft_strdup("45");
	a->width = ft_strdup("5");
	a->attributes = ft_strdup("-");
	a->precision = ft_strdup("2");
	a->flag = ft_strdup("d");
	a->next = NULL;
	ft_apply_options(&a);
	printf("%s", a->data_converted);
	return (0);
}

*/
