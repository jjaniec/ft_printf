/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 20:50:34 by jjaniec           #+#    #+#             */
/*   Updated: 2018/01/12 21:28:59 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Test main
*/

int		main(void)
{
	char	*s;
	/*int		i;
	wchar_t q[2];
    long int    lol = 42;
	q[0] = 0x100D7;
	q[1] = '\0';
  
	i = 0;
	s = "char |%c|\ndec |%d|\nrand+str rokdrgopih|%s|\n hex & hex caps |%x| |%X|\nrand+fake e%wfdwia%qjirg";
	ft_printf(s, 'X', 12, "debug", 255, 255);
	printf(s, 'X', 12, "debug", 255, 255);

	ft_printf("\nRslt ui%dnttoh%%ex%S%C: %s\n", 12, &q[0], q[0], ft_uint_to_hex(52));
	printf("\nRslt ui%dnttohex%S%C: %s\n", 12, &q[0], q[0], ft_uint_to_hex(52));
  
	ft_printf("\nnoargs + blank\n");
	printf("\nnoargs + blank\n");

	printf("%lu  %u   %u", lol, (unsigned int)-42, 42);
	ft_printf("  %u   %u", (unsigned int)-42, 42);
  
	return (0);
}
