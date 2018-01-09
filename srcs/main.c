/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 20:50:34 by jjaniec           #+#    #+#             */
/*   Updated: 2018/01/09 18:09:55 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Test main
*/

int		main(void)
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

	ft_printf("\nnoargs + blank\n");

	ft_printf("");
	return (0);
}
