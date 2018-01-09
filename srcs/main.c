/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 20:50:34 by jjaniec           #+#    #+#             */
/*   Updated: 2018/01/09 16:16:08 by jjaniec          ###   ########.fr       */
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
	wchar_t q[2];

	q[0] = 0x100D7;
	q[1] = '\0';

	i = 0;
	s = "char |%c|\ndec |%d|\nrand+str rokdrgopih|%s|\n hex & hex caps |%x| |%X|\nrand+fake e%wfdwia%qjirg";
	ft_printf(s, 'X', 12, "debug", 255, 255);

	ft_printf("\nRslt ui%dnttoh%%ex%S%C: %s\n", 12, &q[0], q[0], ft_uint_to_hex(1));

	//printf("%s", ft_uint_to_str(4294967296));
	return (0);
}
