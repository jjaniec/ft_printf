/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 20:50:34 by jjaniec           #+#    #+#             */
/*   Updated: 2017/12/12 13:46:03 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Test main
*/

int		main(int ac, char **av)
{
	char *s;

	s = "yegfheusfh%diufheus%lufeufih%rojirg";
	ft_printf(s, 12);
	//printf(s, 12);
	return (0);
}
