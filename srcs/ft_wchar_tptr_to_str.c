/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar_tptr_to_str.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 14:11:07 by jjaniec           #+#    #+#             */
/*   Updated: 2018/02/09 16:34:54 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Convert a string of unicode characters to a char pointer
*/

char	*ft_wchar_tptr_to_str(wchar_t *ws)
{
	char				*r;
	unsigned int		i;
	unsigned int		j;

	if (!ws)
		return (ft_strdup("(null)"));
	i = 0;
	j = 1;
	r = ft_strdup("");
    r = ft_strjoin_free(r, ft_wchar_t_to_str((wint_t)(*ws)));
	while (*ws++)
        r = ft_strjoin_free(r, ft_wchar_t_to_str((wint_t)(*ws)));
	return (r);
}
