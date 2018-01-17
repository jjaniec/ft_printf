/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_width.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 16:37:39 by jjaniec           #+#    #+#             */
/*   Updated: 2018/01/17 16:17:50 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Generate a string to be concatenated with the content of the argument
*/

char    *ft_generate_width(t_arg **e)
{
    char    *s;
    int     l;
    int     i;
    char    c;

    i = -1;
    l = ft_atoi((*e)->width) - (ft_strlen((*e)->data_converted) + \
        ((ft_strchr((*e)->attributes, '+') ? (1) : (0))));
    if (!(l > 0))
        return (NULL);
    if (ft_strchr((*e)->attributes, '0') && !ft_strchr((*e)->attributes, '-'))
        c = '0';
    else
        c = ' ';
    s = malloc(sizeof(char) * l + 1);
    while (++i != l)
        s[i] = c;
    s[l] = '\0';
    return (s);
}
