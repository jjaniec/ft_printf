/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 20:50:34 by jjaniec           #+#    #+#             */
/*   Updated: 2018/01/14 17:39:39 by jjaniec          ###   ########.fr       */
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
	wchar_t q[3];
	q[0] = 0x100D7;
	q[1] = 0x100D7;
	q[2] = '\0';
  
	i = 0;
    ft_printf("%%");
	s = "char - char uni|%c||%C|\ndec |%d||%i|\nrand+str -struni rokdrgopih|%s||%S|\n hex & hex caps |%x| |%X|\nrand+fake e%wfdwia%qjirg\noctal o|%o|\nuint |%u|";
	ft_printf(s,\
        'X',
        q[0],
        12,
        12, 
        "debug", 
        q, 
        255, 
        255, 
        255,
        4242
        );
	printf(s, 'X', q[0], 12, 12, "debug", q, 255, 255, 255, 4242);

	//printf("\nnoargs + blank\n");

	return (0);
}
