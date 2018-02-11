/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar_tptr_to_str.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 14:11:07 by jjaniec           #+#    #+#             */
/*   Updated: 2018/02/11 15:59:16 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Convert a string of unicode characters to a char pointer
*/

char	*ft_wchar_tptr_to_str(wchar_t *ws)
{
	char				*r;
    char                *t;
	unsigned int		i;
	unsigned int		j;

	if (!ws)
		return (ft_strdup("(null)"));
	i = 0;
	j = 1;
    t = NULL;
    r = ft_wchar_t_to_str((wint_t)(*ws));
	while (*ws++)
    {
        t = ft_wchar_t_to_str((wint_t)(*ws));
        if (!t)
            t = ft_strdup("!");
        r = ft_strjoin_free(r, t);
    }/*
    printf("r: %s\n", r);*/
	return (r);
}
