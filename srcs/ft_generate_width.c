/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_width.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 16:37:39 by jjaniec           #+#    #+#             */
/*   Updated: 2018/01/17 18:18:37 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Generate a string to be concatenated with the content of the argument
*/

char    *ft_generate_width(int l, char c)
{
    char    *s;
    int     i;

    i = -1;
    s = malloc(sizeof(char) * l + 1);
    while (++i < l - 1)
        s[i] = c;
    s[l] = '\0';
    return (s);
}
