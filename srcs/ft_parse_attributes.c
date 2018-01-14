/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_attributes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 18:59:50 by jjaniec           #+#    #+#             */
/*   Updated: 2018/01/14 19:25:43 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Return 0 if $c is an attribute, otherwise return 1
*/

static int  ft_is_attribute(char c)
{
    if (c == '0' || c == ' ' || c == '+' || c == '-' || c == '#')
      return (1);
    return (0);

}

/*
** Return lenght of attributes before flag
*/

static int  ft_get_attributes_len(const char *restrict format, int pos)
{   
    int     i;

    i = 0;
    while (format[pos + i] && i < 6 && ft_is_attribute(format[pos + i]))
        i++;
    return ((i == 6) ? (5) : (i));
}

/*
** Return attributes before flag (#0+-[escape])
*/

char    *ft_parse_attributes(const char *restrict format, int *pos)
{
    char    *s;
    int     i;
    int     l;

    i = 0;
    l = ft_get_attributes_len(format, *pos);
    if (l == 0)
      return (NULL);
    s = malloc(sizeof(char) * l + 1);
    while (i < l && ft_is_attribute(format[*pos + i]))
    {
        s[i] = format[*pos + i];
        i++;
    }
    s[l] = '\0';
    *pos += ft_strlen(s);
    return (s);
}
