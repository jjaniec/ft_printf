/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 14:05:23 by jjaniec           #+#    #+#             */
/*   Updated: 2018/01/29 21:51:09 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		ft_can_ret_0(t_arg **e)
{
	if ((*((*e)->flag) == 'o' || \
		*((*e)->flag) == 'O') && (*e)->attributes && \
        ft_strchr((*e)->attributes, '#'))
		return (0);
	return (1);

}

/*
** Apply precision on converted element
*/

void			ft_apply_precision(t_arg **e)
{
	int		x;
	int		y;

	y = 0;
	x = 0;
	if (ft_strchr((*e)->flag, 's'))
		(*e)->data_converted = ft_strsub_free(\
			(*e)->data_converted, 0, ft_atoi((*e)->precision));
	if (ft_is_conv_numeric(e))
	{
		if (ft_strchr((*e)->precision, '.') && \
			ft_strcmp((*e)->data_converted, "0") == 0 && ft_can_ret_0(e))
		{
			free((*e)->data_converted);
			(*e)->data_converted = ft_strdup("");
		}
		else
		{
			y = ft_atoi((*e)->data_converted);
			x = (ft_atoi((*e)->precision) - ft_strlen((*e)->data_converted) + \
				((y >= 0) ? (1) : (2)));
			if (x > 0)
				(*e)->data_converted = \
				ft_strjoin_free(ft_generate_width(x, '0'), (*e)->data_converted);
			if (y < 0)
				ft_byte_swap(ft_strchr((*e)->data_converted, '-'), &(*e)->data_converted[0]);
		}
	}
}
