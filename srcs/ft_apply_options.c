/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_options.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 14:43:43 by jjaniec           #+#    #+#             */
/*   Updated: 2018/01/16 17:01:45 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Apply attributes, width, precision on argument
*/

void    ft_apply_options(t_arg **e)
{
    if ((*e)->attributes)
        ft_apply_attributes(e);
}
