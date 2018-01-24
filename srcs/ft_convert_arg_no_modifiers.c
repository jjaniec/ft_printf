/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_arg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 14:25:16 by jjaniec           #+#    #+#             */
/*   Updated: 2018/01/24 16:09:09 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Fill function pointer tab with functions used to convert data of arguments
** in strings
** Conversions to handle : sSpdDioOuUxXcC %%
*/

static void	ft_fill_function_pointers_tab(char *(**f)(void *))
{
	f[('s' - 'A')] = (void *)&ft_printf_str_arg;
	f[('p' - 'A')] = (char *(*)(void *))&ft_voidptr_to_hex;
	f[('d' - 'A')] = (char *(*)(void *))&ft_imax_toa;
	f[('i' - 'A')] = (char *(*)(void *))&ft_imax_toa;
	f[('o' - 'A')] = (char *(*)(void *))&ft_uint_to_octal;
	f[('u' - 'A')] = (char *(*)(void *))&ft_uint_to_str;
	f[('x' - 'A')] = (char *(*)(void *))&ft_uint_to_hex;
	f[('c' - 'A')] = (char *(*)(void *))&ft_char_to_str;
}

/*
** Convert argument if conversion identifier is >= 'A' && <= 'Z'
*/

char        *ft_convert_arg_no_modifiers_caps(va_list va_ptr, char fl)
{
	if (fl == 'S')
        return (ft_wchar_tptr_to_str(va_arg(va_ptr, wchar_t *)));
	if (fl == 'C')
		return (ft_wchar_t_to_str(va_arg(va_ptr, wint_t)));
    if (fl == 'D')
        return (ft_imax_toa(va_arg(va_ptr, intmax_t)));
    if (fl == 'O')
        return (ft_long_int_to_uoctal(va_arg(va_ptr, long int)));
    if (fl == 'X')
        return (ft_uint_to_hex_caps(va_arg(va_ptr, unsigned int)));
    if (fl == 'U')
        return (ft_imax_toa(va_arg(va_ptr, unsigned long int)));
    return (NULL);
}

/*
** Convert argument of any type in a string to be printed
*/

char	    *ft_convert_arg_no_modifiers(va_list va_ptr, char fl)
{
	char	*(*f[100])(void *);

	ft_fill_function_pointers_tab(f);
	if (fl == 's')
		return ((*f[fl - 'A'])((va_arg(va_ptr, char *))));
	if (fl == 'c')
		return ((*f[fl - 'A'])((void *)(size_t)va_arg(va_ptr, int)));
	if (fl == 'd' || fl == 'i')
		return ((*f[fl - 'A'])((void *)(size_t)va_arg(va_ptr, int)));
	if (fl == 'o' || fl == 'u' || fl == 'x')
		return ((*f[fl - 'A'])((void *)(size_t)va_arg(va_ptr, unsigned int)));
	if (fl == 'p')
        return ((*f[fl - 'A'])((void *)va_arg(va_ptr, void *)));
    if (fl >= 'A' && fl <= 'Z')
        return (ft_convert_arg_no_modifiers_caps(va_ptr, fl));
	return (NULL);
}
