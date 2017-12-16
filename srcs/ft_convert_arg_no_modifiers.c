/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_arg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 14:25:16 by jjaniec           #+#    #+#             */
/*   Updated: 2017/12/16 14:23:12 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Fill function pointer tab with functions used to convert data of arguments
** in strings
** Conversions to handle : sSpdDioOuUxXcC %%
*/

void	ft_fill_function_pointers_tab(char *(**f)(void *))
{
	//f[('S' - 'A')] = ft_wchat_t_to_str//alias de ls
	//f[('p' - 'A')] = &ft_void_to_hex;
	f[('d' - 'A')] = &ft_itoa;
	//f[('D' - 'A')] = &ft_itoa(ft_longint_to_signedint()); //alias ld
	f[('i' - 'A')] = &ft_itoa;
	//f[('o' - 'A')] = &ft_uint_to_octal_to_str;
	//f[('O' - 'A')] = &ft_long_int_to_unsignedoctal //alias lo
	f[('u' - 'A')] = &ft_uint_to_str;
	//f[('U' - 'A')] = &ft_long_int_to_unsigned_dec // alias lu
	//f[('x' - 'A')] = &ft_uint_to_hex_to_str;
	//f[('X' - 'A')] = &ft_uint_to_hex;
	f[('c' - 'A')] = &ft_char_to_str;
	//f[('C' - 'A')] = &ft_wint_t_to_char // alias de lc
}

/*
** Convert argument of any type in a string to be printed
*/

char	*ft_convert_arg_no_modifiers(va_list va_ptr, char *fl)
{
	char	*s;
	char	*(*f[100])(void *);

	ft_fill_function_pointers_tab(f);
	if (ft_strlen(fl) == 1)
		if (*fl == 's')
			return (va_arg(va_ptr, char *));
		else if (*fl == 'c')
			return ((*f[*fl - 'A'])((char)va_arg(va_ptr, char)));
		else if (*fl == 'd')
			return ((*f[*fl - 'A'])((int)va_arg(va_ptr, int)));
		else if (*fl == 'o' || *fl == 'u' || *fl == 'x' || *fl == 'X')
			return ((*f[*fl - 'A'])((unsigned int)va_arg(va_ptr, unsigned int)));
		else if (*fl == 'p')
			return ((*f[*fl - 'A'])((void *)va_arg(va_ptr, void *)));
	return (NULL);
}
