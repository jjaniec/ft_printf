/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar_tptr_to_str.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 14:11:07 by jjaniec           #+#    #+#             */
/*   Updated: 2018/02/12 21:02:08 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Convert a string of unicode characters to a char pointer,
** if an invalid unicode is found during the conversion, place a '!' char
** to let know ft_handle_S_error if the string should be printed 
** depending of it's precision
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
	while (r && *ws++)
    {
        t = ft_wchar_t_to_str((wint_t)(*ws));
        if (!t && r)
            t = ft_strdup("!");
        r = ft_strjoin_free(r, t);
    }
	return (r);
}
