/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 20:50:34 by jjaniec           #+#    #+#             */
/*   Updated: 2017/12/13 20:19:47 by jjaniec          ###   ########.fr       */
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
	s = "yegfheusfh%diufhe%sus%lufeufi%whoj%hhuirg";
	ft_printf(s, 12);
	
	printf("\n%d", ft_is_modifier('l', 0));
	printf("\n%s", ft_get_flag(s, i));
	//printf(s, 12);
	return (0);
}
