/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 21:58:27 by jjaniec           #+#    #+#             */
/*   Updated: 2018/01/12 22:02:21 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Return 1 if passed position in format is the beginning of a flag
** otherwise return 0
*/

int     ft_is_flag(const char *restrict format, int i)
{
   if (format[i] == '%' && \
       format[i + 1] != '%' && \
       ft_get_flag(format, i)[0]) 
     return (1);
   return (0);
}
