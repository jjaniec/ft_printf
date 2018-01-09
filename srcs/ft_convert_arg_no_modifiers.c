/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_arg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 14:25:16 by jjaniec           #+#    #+#             */
/*   Updated: 2018/01/09 17:14:11 by jjaniec          ###   ########.fr       */
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
	f[('S' - 'A')] = (void *)&ft_wchar_tptr_to_str;//alias de ls
	//f[('p' - 'A')] = &ft_void_to_hex;
	f[('d' - 'A')] = (char *(*)(void *))&ft_itoa;
	//f[('D' - 'A')] = &ft_itoa(ft_longint_to_signedint()); //alias ld
	f[('i' - 'A')] = (char *(*)(void *))&ft_itoa;
	//f[('o' - 'A')] = &ft_uint_to_octal;
	//f[('O' - 'A')] = &ft_long_int_to_unsignedoctal //alias lo
	f[('u' - 'A')] = (char *(*)(void *))&ft_uint_to_str;
	//f[('U' - 'A')] = &ft_long_int_to_unsigned_dec // alias lu
	f[('x' - 'A')] = (char *(*)(void *))&ft_uint_to_hex;
	f[('X' - 'A')] = (char *(*)(void *))&ft_uint_to_hex_caps;
	f[('c' - 'A')] = (char *(*)(void *))&ft_char_to_str;
	f[('C' - 'A')] = (char *(*)(void *))&ft_wchar_t_to_str; // alias de lc
}

/*
** Convert argument of any type in a string to be printed
*/

char	*ft_convert_arg_no_modifiers(va_list va_ptr, char *fl)
{
	char	*(*f[100])(void *);

	ft_fill_function_pointers_tab(f);
	if (ft_strlen(fl) == 1)
	{
		if (*fl == 's')
			return (va_arg(va_ptr, char *));
		if (*fl == 'c')
			return ((*f[*fl - 'A'])((void *)(size_t)va_arg(va_ptr, int)));
		if (*fl == 'd')
			return ((*f[*fl - 'A'])((void *)(size_t)va_arg(va_ptr, int)));
		if (*fl == 'o' || *fl == 'u' || *fl == 'x' || *fl == 'X')
			return ((*f[*fl - 'A'])((void *)(size_t)va_arg(va_ptr, unsigned int)));
		if (*fl == 'S' || (fl[0] == 'l' && fl[1] == 's'))
			return ((*f[*fl - 'A'])((void *)va_arg(va_ptr, wchar_t *)));
		if (*fl == 'C' || (fl[0] == 'l' && fl[1] == 'c'))
			return ((*f[*fl - 'A'])((void *)(size_t)va_arg(va_ptr, wint_t)));
		if (*fl == 'p')
			return ((*f[*fl - 'A'])((void *)va_arg(va_ptr, void *)));
	}
	return (NULL);
}
