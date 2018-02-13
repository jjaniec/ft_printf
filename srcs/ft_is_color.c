/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 22:49:56 by jjaniec           #+#    #+#             */
/*   Updated: 2018/02/13 22:51:45 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Parse prefix of color "LIGHT" or "DARK"
*/

static char   *ft_parse_clprefix(char *cl)
{
    if (strncmp(cl, "LIGHT_", 6) == 0)
        return (ft_strsub(cl, 0, 6));
    if (strncmp(cl, "DARK_", 5) == 0)
        return (ft_strsub(cl, 0, 5));
    return (ft_strdup(""));
}

/*
** Return 1 if $cl is a defined color, otherwise return 0
*/

char    *ft_is_color(char *cl)
{
    int     i;
    char    *l;

    i = 0;
    if (*(cl) == 'C' && cl[1] == 'L' && cl[2] == '_')
        i += 2;
    if ((cl[i] == 'F' || cl[i] == 'B') && cl[i + 1] == 'G' && cl[i + 2] == '_')
        i += 2;
    else if (i != 0)
    {
        free(cl);
        return (NULL);
    }
    l = ft_parse_clprefix(cl + i);
    return (NULL);
}
