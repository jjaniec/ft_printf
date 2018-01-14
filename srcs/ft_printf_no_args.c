/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_no_args.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 15:22:31 by jjaniec           #+#    #+#             */
/*   Updated: 2018/01/14 17:38:11 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Removes double %
*/

static void ft_shrink_s(char **s, int pos)
{
    char    *d;
    int     i;

    i = -1;
    printf("len *s%zu\n", ft_strlen(*s));
    d = malloc(sizeof(char) * ft_strlen(*s));
    while (++i != pos)
    {
        d[i] = (*s)[i];
    }
    printf("i : %d\n", i);
    i += 1;
    write(1, "a", 1);
    while ((*s)[i])
    {
        d[i - 1] = (*s)[i];
        i++;
    }
    d[i - 1] = '\0';
    printf("\nd : %s(%zu) - s : %s(%zu)\n", d, ft_strlen(d), *s, ft_strlen(*s));
    free(*s);
    (*s) = d;
}

/*
** Calculate lenght of the string to be printed and call ft_shrink_s to remove %%
*/

static void ft_format_string_no_args(char **s, int *x)
{
    int     i;

    i = 0;
    while ((*s)[i])
    {
        if ((*s)[i] == '%' && (*s)[i + 1] == '%')
            ft_shrink_s(s, i);
        i++;
    }
    *x = i;
}

/*
** Handle return value and %% when no arguments are specified in printf
*/

int         ft_printf_no_args(const char *restrict format)
{
    char    *s;
    int     x;

    write(1, "b", 1);
    s = ft_strdup(format);
    write(1, "b", 1);
    ft_format_string_no_args(&s, &x);
    write(1, "b", 1);
    return (write(1, s, x));
}
