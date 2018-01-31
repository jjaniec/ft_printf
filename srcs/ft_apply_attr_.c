/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_minus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 16:25:24 by jjaniec           #+#    #+#             */
/*   Updated: 2018/01/31 14:51:15 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Apply attribute space on content of arg $e
*/

void	 ft_apply_attr_space(t_arg **e)
{
	char	*s;
	char	*a;

    if (ft_is_conv_numeric(e) && *(*e)->flag != 'u' && \
        !(ft_atoi((*e)->data_converted) < 0 && ft_strchr((*e)->data_converted, '-')))
	{
		a = malloc(sizeof(char) * 2);
		a[1] = '\0';
		if (ft_atoi((*e)->data_converted) >= 0)
			a[0] = ' ';
		else
			a[0] = '-';
		s = ft_strjoin_free(a, (*e)->data_converted);
		(*e)->data_converted = s;
	}
}

/*
** Apply plus attribute on content of arg $e
*/

void	ft_apply_attr_plus(t_arg **e)
{
	char	*s;
	char	*a;

	if (((*e)->flag[0] == 'd' || \
		  (*e)->flag[0] == 'i') && \
		((ft_atoi((*e)->data_converted) >= 0)))
	{
		a = malloc(sizeof(char) * 2);
		a[0] = '+';
		a[1] = '\0';
		s = ft_strjoin_free(a, (*e)->data_converted);
		(*e)->data_converted = s;
	}
}

/*
** Apply hashtag attribute on content of arg $e
*/

void    ft_apply_attr_hashtag(t_arg **e)
{
    char    *c;
    char    *t;

    if ((*((*e)->flag) == 'o' || *((*e)->flag) == 'O') && \
        ft_atoi((*e)->data_converted) != 0)
        (*e)->data_converted = ft_strjoin_free(ft_strdup("0"), (*e)->data_converted);
    else if ((*((*e)->flag) == 'x' || *((*e)->flag) == 'X') && ft_atoi_hex((*e)->data_converted) != 0)
    {
        if (*((*e)->data_converted) == ' ')
        {
            c = ft_strnotchr((*e)->data_converted, ' ');
            if (c && (unsigned int)c > (unsigned int)(*e)->data_converted)
                *(c - 1) = *((*e)->flag);
            if (c && (unsigned int)c >= (unsigned int)(*e)->data_converted)
                *(c - 2) = '0';
        }
        else if (*((*e)->data_converted) == '0' && (*e)->data_converted[1] == '0' && !(*e)->precision)
            (*e)->data_converted[1] = *((*e)->flag);
        else
        {
            t = ft_strdup("0x");
            t[1] = *((*e)->flag);
            (*e)->data_converted = ft_strjoin_free(t, (*e)->data_converted);
        }
    }
}
