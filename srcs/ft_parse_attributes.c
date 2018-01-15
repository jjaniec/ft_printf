/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_attributes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 18:59:50 by jjaniec           #+#    #+#             */
/*   Updated: 2018/01/15 14:10:01 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Return 0 if $c is an attribute, otherwise return 1
*/

int  ft_is_attribute(char c)
{
    if (c == '0' || c == ' ' || c == '+' || c == '-' || c == '#')
      return (1);
    return (0);

}

/*
** Return lenght of attributes before flag
*/

int  ft_get_attributes_len(const char *restrict format, int pos)
{   
    int     i;

    i = 0;
    while (format[pos + i] && i < 6 && ft_is_attribute(format[pos + i]))
        i++;
    printf("attributes len: %d", i);
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
    if (!(ft_is_attribute(format[*pos + 1])))
      return (NULL);
    printf("format : %s\n", (format + *pos));
    l = ft_get_attributes_len((format + *pos + 1), 0);
    s = malloc(sizeof(char) * l + 1);
    while (i < l && ft_is_attribute(format[*pos + i + 1]))
    {
        s[i] = format[*pos + i + 1];
        i++;
    }
    s[l] = '\0';
    *pos += ft_strlen(s);
    printf("attributes : %s\n", s);
    return (s);
}

int     main()
{
    int x;

    x = 5;
    printf("\n|%s|", ft_parse_attributes("fieji%+0 Ciefjij", &x));
    printf("x %d", x);
    return (0);

}
