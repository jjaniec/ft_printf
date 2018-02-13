/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 20:42:58 by jjaniec           #+#    #+#             */
/*   Updated: 2018/02/13 22:49:49 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Parse color specifier between '{' and '}' chars, if '}' if not found,
** return NULL
*/

static char    *ft_parse_specifier(const char *restrict format, int *pos)
{
    int     i;

    i = (*pos) + 1;
    while (format[i] && format[i] != '}')
        i++;
    if (!format[i])
        return (NULL);
    return (ft_strsub(format + (*pos) + 1, 0, i - 1 - *pos));
}

/*
** Print specified color between '{' and '}', if the color specifier
** is invalid, the function does not increment *pos, so the specifier can be
** printed like a normal string, if a valid color specifier is found,
** the function print the color and increment *pos to skip it in format
*/

int 	ft_print_color(const char *restrict format, int *pos)
{
    char    *cl;

    cl = ft_parse_specifier(format, pos);
    if (!cl)
        return (0);
    printf("\nparsed color : |%s|\n", cl);
    *pos += ft_strlen(cl) + 2;
    return (1);
}
