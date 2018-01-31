/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 14:05:23 by jjaniec           #+#    #+#             */
/*   Updated: 2018/01/31 19:25:11 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Handle exceptions cases for o/O w/ # attribute
*/

static int		ft_can_ret_0(t_arg **e)
{
	if ((*((*e)->flag) == 'o' || \
		*((*e)->flag) == 'O') && (*e)->attributes && \
		ft_strchr((*e)->attributes, '#'))
		return (0);
	return (1);
}

/*
** Apply precision on non numeric conversions (s/p)
*/

static void		ft_apply_precision_nonnumeric(t_arg **e)
{
	int		x;

	x = ft_atoi((*e)->precision);
	if (*((*e)->flag) == 's')
		(*e)->data_converted = ft_strsub_free(\
			(*e)->data_converted, 0, x);
	if (*((*e)->flag) == 'p')
	{
		if (*(*e)->precision == '.' && strcmp((*e)->data_converted, "0x0") == 0)
		{
			free((*e)->data_converted);
			(*e)->data_converted = ft_strdup("0x");
		}
		else if ((int)ft_strlen((*e)->data_converted) - 2 < x)
		{
			if (strcmp((*e)->data_converted, "0x0") == 0)
				(*e)->data_converted = ft_strjoin_free(ft_generate_width(x, '0'), (*e)->data_converted);
			else
				(*e)->data_converted = ft_strjoin_free(ft_generate_width(x - (ft_strlen((*e)->data_converted) - 3), '0'), (*e)->data_converted);
			*(ft_strchr((*e)->data_converted, 'x')) = '0';
			(*e)->data_converted[1] = 'x';
		}
	}
}

/*
** Apply precision on numeric conversions (d/u/i/x/o/U/X/D/O)
*/

static void		ft_apply_precision_numeric(t_arg **e)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
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

/*
** Apply precision on converted element
*/

void			ft_apply_precision(t_arg **e)
{
	if (!ft_is_conv_numeric(e))
		ft_apply_precision_nonnumeric(e);
	else
		ft_apply_precision_numeric(e);
}
