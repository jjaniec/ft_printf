/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_printf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 18:09:05 by jjaniec           #+#    #+#             */
/*   Updated: 2018/01/24 15:30:01 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Print passed char as parameter and increment return value of ft_printf
*/

void    ft_putchar_printf(char c, int *r)
{
    ft_putchar(c);
    if (c)
        *r += 1;
}
