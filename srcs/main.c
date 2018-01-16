/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 20:50:34 by jjaniec           #+#    #+#             */
/*   Updated: 2018/01/16 18:42:05 by jjaniec          ###   ########.fr       */
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
	s = "char - char uni|%0.c|%000+++8.454C||\ndec |% 5d||%-+010i|\nrand+str -struni rokdrgopih|%+s||%4.8445S|\n hex & hex caps |%+x| |% X|\nrand+fake e%wfdwia%qjirg\noctal o|%0 o|\nuint |%0##u|";
    setlocale(LC_ALL, "");
	ft_printf(s,\
        'X',
        q[0],
        12,
        -12, 
        "debug", 
        q, 
        255, 
        255, 
        255,
        4242
        );
	//printf(s, 'X', q[0], 12, 12, "debug", q, 255, 255, 255, 4242);
	//printf("\nnoargs + blank\n");

	return (0);
}
