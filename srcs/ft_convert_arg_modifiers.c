/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_arg_modifiers.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 15:08:13 by jjaniec           #+#    #+#             */
/*   Updated: 2018/01/24 16:30:20 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Convert argument of any type with modifiers in a char pointer to print it
*/

char	*ft_convert_arg_modifiers(va_list va_ptr, t_arg **e)
{
	char	c;

	c = 0;
	if ((*e)->modifiers && (*e)->flag)
	{
		c = (*e)->flag[0];
		if (ft_strcmp("l", (*e)->modifiers) == 0)
		{
			if (c == 'u')
				return (ft_imax_toa(va_arg(va_ptr, unsigned long int)));
			if (c == 'o')
				return (ft_uint_to_octal(va_arg(va_ptr, unsigned long int)));
			if (c == 'x')
				return (ft_uint_to_hex(va_arg(va_ptr, unsigned long int)));
			if (c == 'X')
				return (ft_uint_to_hex_caps(va_arg(va_ptr, unsigned long int)));
			if (c == 'c')
				return (ft_wchar_t_to_str(va_arg(va_ptr, wint_t)));
			if (c == 's')
				return (ft_wchar_tptr_to_str(va_arg(va_ptr, wchar_t *)));
			if (c == 'd' || c == 'i')
				return (ft_imax_toa(va_arg(va_ptr, long int)));
		}
		if (ft_strcmp("h", (*e)->modifiers) == 0)
		{
			if (c == 'u')
				return (ft_imax_toa((unsigned short int)va_arg(va_ptr, int)));
			if (c == 'o')
				return (ft_uint_to_octal((unsigned short int)va_arg(va_ptr, int)));
			if (c == 'x')
				return (ft_uint_to_hex((unsigned short int)va_arg(va_ptr, int)));
			if (c == 'X')
				return (ft_uint_to_hex_caps((unsigned short int)va_arg(va_ptr, int)));
			if (c == 'd' || c == 'i')
				return (ft_imax_toa((short int)va_arg(va_ptr, int)));
		}
		if (ft_strcmp("ll", (*e)->modifiers) == 0)
		{
			if (c == 'u')
				return (ft_imax_toa(va_arg(va_ptr, unsigned long long int)));
			if (c == 'o')
				return (ft_uint_to_octal(va_arg(va_ptr, unsigned long long int)));
			if (c == 'x')
				return (ft_uint_to_hex(va_arg(va_ptr, unsigned long long int)));
			if (c == 'X')
				return (ft_uint_to_hex_caps(va_arg(va_ptr, unsigned long long int)));
			if (c == 'd' || c == 'i')
				return (ft_imax_toa(va_arg(va_ptr, long long int)));
		}
		if (ft_strcmp("hh", (*e)->modifiers) == 0)
		{
			if (c == 'u')
				return (ft_imax_toa((unsigned char)va_arg(va_ptr, int)));
			if (c == 'o')
				return (ft_uint_to_octal((unsigned char)va_arg(va_ptr, int)));
			if (c == 'x')
				return (ft_uint_to_hex((unsigned char)va_arg(va_ptr, int)));
			if (c == 'X')
				return (ft_uint_to_hex_caps((unsigned char)va_arg(va_ptr, int)));
			if (c == 'd' || c == 'i')
				return (ft_imax_toa((signed char)va_arg(va_ptr, int)));
		}
		if (ft_strcmp("j", (*e)->modifiers) == 0)
		{
			if (c == 'u')
				return (ft_imax_toa(va_arg(va_ptr, uintmax_t)));
			if (c == 'o')
				return (ft_uint_to_octal(va_arg(va_ptr, uintmax_t)));
			if (c == 'x')
				return (ft_uint_to_hex(va_arg(va_ptr, uintmax_t)));
			if (c == 'X')
				return (ft_uint_to_hex_caps(va_arg(va_ptr, uintmax_t)));
			if (c == 'd' || c == 'i')
				return (ft_imax_toa(va_arg(va_ptr, intmax_t)));
		}
		if (ft_strcmp("z", (*e)->modifiers) == 0)
		{
			if (c == 'u')
				return (ft_imax_toa(va_arg(va_ptr, size_t)));
			if (c == 'o')
				return (ft_uint_to_octal(va_arg(va_ptr, size_t)));
			if (c == 'x')
				return (ft_uint_to_hex(va_arg(va_ptr, size_t)));
			if (c == 'X')
				return (ft_uint_to_hex_caps(va_arg(va_ptr, size_t)));
			if (c == 'd' || c == 'i')
				return (ft_imax_toa(va_arg(va_ptr, size_t)));
		}
	}
	return ((c) ? (ft_convert_arg_no_modifiers(va_ptr, c)) : (NULL));
}
