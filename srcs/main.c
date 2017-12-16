/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 20:50:34 by jjaniec           #+#    #+#             */
/*   Updated: 2017/12/16 17:12:13 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Test main
*/

int		main(int ac, char **av)
{
	char	*s;
	int		i;

	i = 0;
	s = "ye  |%c|  |%d|ih|%s|us|%lu|fe%wfoj|%hhu|irg";
	ft_printf(s, 'X', 12, "dwdiaji");

	ft_printf("\nRslt uinttohex: %s\n", ft_uint_to_hex(255));

	//printf("%s", ft_uint_to_str(4294967296));
	return (0);
}
