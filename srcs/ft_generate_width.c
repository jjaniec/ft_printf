/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_width.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 16:37:39 by jjaniec           #+#    #+#             */
/*   Updated: 2018/01/16 17:47:52 by jjaniec          ###   ########.fr       */
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

    i = -1;
    l = ft_atoi((*e)->width) - (ft_strlen((*e)->data_converted));
    if (!(l > 0))
        return (NULL);
    s = malloc(sizeof(char) * l + 1);
    while (++i != l)
        s[i] = ' ';
    s[l] = '\0';
    return (s);
}
