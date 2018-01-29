/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 13:15:20 by jjaniec           #+#    #+#             */
/*   Updated: 2018/01/27 15:02:52 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Calculate len of a string to contain $base version of $n
*/

int     ft_get_slen(uintmax_t n, uint8_t b)
{
    int     i;

    i = 0;
    while ((n / b) > 0)
    {
        n /= b;
        i++;   
    }
    return (i);
}

/*
** Converts an unsigned int into it's base $base version
*/

char    *ft_uitoa_base(uintmax_t n, uint8_t b)
{
    char    *s;
    char    *sr;
    int     t;

    t = ft_get_slen(n, b);
    s = ft_strnew(t + 1);
    sr = s;
    s += (sizeof(char) * (t));
    if (n == 0)
        return (ft_strdup("0"));
    while (n != 0)
    {
        t = n % b;
        *s-- = (t > 9) ? (t + ('a' - 10)) : (t + '0');
        n /= b;
    }
    return (sr);
}