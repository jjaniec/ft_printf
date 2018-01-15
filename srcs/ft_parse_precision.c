/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 18:46:09 by jjaniec           #+#    #+#             */
/*   Updated: 2018/01/15 18:51:43 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Return a char pointer containing precision options
** if none are found return NULL
*/ 

char    *ft_parse_precision(const char *restrict format, int *pos)
{
    int     x;
    char    *s;

    x = *pos + 1;
    s = ft_parse_width(format, &x);
    *pos = x;
    return (s);
}

int     main()
{
    int     x;

    x = 5;
    printf("%s", ft_parse_width("fe%12.215c", &x));
    printf(" - x %d", x);
    return (0);
}
