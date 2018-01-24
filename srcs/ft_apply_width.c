/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 17:45:52 by jjaniec           #+#    #+#             */
/*   Updated: 2018/01/24 16:30:44 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Swap bytes of the postive or negative char before the number and the behind
** right before it
*/

void		ft_byte_swap(char *a, char *b)
{
	char	t;

	if (a && b)
	{
		t = *b;
		*b = *a;
		*a = t;
	}
}

/*
** Resize the char * with '0' or ' ' of the data converted of $e
** as specified in width option
*/

void			ft_apply_width(t_arg **e)
{
	char	c;
	char	cx;
	char	*s;
	int		l;

	cx = 0;
	l = ft_atoi((*e)->width) - ft_strlen((*e)->data_converted) + 1;
	if (l >= 2)
	{
		if ((*e)->attributes && ft_strchr((*e)->attributes, '0') && \
			!ft_strchr((*e)->attributes, '-') && !(ft_is_conv_numeric(e) && (*e)->precision))
			c = '0';
		else
			c = ' ';
		if (((*e)->data_converted[0] == '-' || (*e)->data_converted[0] == '+') && c == '0')
			cx = (*e)->data_converted[0];
		if ((*e)->attributes && ft_strchr((*e)->attributes, '-'))
			s = ft_strjoin_free((*e)->data_converted, ft_generate_width(l, c));
		else
			s = ft_strjoin_free(ft_generate_width(l, c), (*e)->data_converted);
		(*e)->data_converted = s;
		if (cx && (*e)->attributes && ft_strchr((*e)->attributes, '0'))
			ft_byte_swap(ft_strchr((*e)->data_converted, cx), \
				&(*e)->data_converted[0]);
	}
}
