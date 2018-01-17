/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_minus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 16:25:24 by jjaniec           #+#    #+#             */
/*   Updated: 2018/01/17 16:19:44 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Apply attributes zero or minus on content of arg $e
*/

void    ft_apply_attr_minus_zero(t_arg **e)
{
    char    *s;

    if ((*e)->width && ((*e)->flag[0] == 'd' || (*e)->flag[0] == 'i'))
    {
        if (ft_strchr((*e)->attributes, '0') && !ft_strchr((*e)->attributes, '-'))
            s = ft_strjoin_free(ft_generate_width(e), (*e)->data_converted);
        else
            s = ft_strjoin_free((*e)->data_converted, ft_generate_width(e));
        if (s)
            (*e)->data_converted = s;
    }
}

/*
** Apply attribute space on content of arg $e
*/

void	 ft_apply_attr_space(t_arg **e)
{
	char	*s;
	char	*a;

	if (((*e)->flag[0] == 'd' || \
		  (*e)->flag[0] == 'i'))
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
