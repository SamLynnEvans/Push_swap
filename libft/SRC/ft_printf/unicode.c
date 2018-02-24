/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 18:57:00 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/01/22 19:39:33 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	unicode_strlen(int *str)
{
	int	count;

	count = 0;
	while (*str != '\0')
	{
		if (*str < 127 && *str >= 0)
			count++;
		else if (*str > 127 && *str < 2047)
			count += 2;
		else if (*str > 2047 && *str < 65535)
			count += 3;
		else if (*str > 65536 && *str < 1112064)
			count += 4;
		str++;
	}
	return (count);
}

int	ft_putstr_unicode(int *str, char *flags, int mod[2])
{
	int	len;
	int	space_type;

	if (str == NULL)
		return (print_string(NULL, flags, mod));
	if (ft_strrchr(flags, '.') && mod[1] == 0)
		return (print_string("", flags, mod));		
	space_type = bit_space_type(flags);
	len = unicode_strlen(str);
	if (!(space_type & MINUS) && mod[0] > len)
		print_spaces(mod[0] - len);
	while (*str != '\0')
	{
		ft_unicode_putchar(*str);
		str++;
	}
	if ((space_type & MINUS) && mod[0] > len)
		print_spaces(mod[0] - len);
	return ((len > mod[0]) ? len : mod[0]);
}

int	ft_putchar_uc_helper(int c, char *flags, int mod, int uc_size)
{
	int	space_type;
	int	o_mod;
	int	i;

	i = -1;
	o_mod = mod;
	space_type = bit_space_type(flags);
	if (!(space_type & MINUS))
		while (mod-- > uc_size)
			ft_putchar(' ');
	ft_unicode_putchar(c);
	if (space_type & MINUS)
		while (mod-- > uc_size)
			ft_putchar(' ');
	return ((uc_size > o_mod) ? uc_size : o_mod);
}

int	ft_putchar_unicode(int c, char *flags, int mod[2])
{
	if (ft_strrchr(flags, '.') && mod[1] == 0)
	{
		if (c < 256)
			return (print_char((char)c, flags, mod));
		return (-4);
	}	
	if (c < 127 && c >= 0)
		return (ft_putchar_uc_helper(c, flags, mod[0], 1));
	if (c > 127 && c < 2047)
		return (ft_putchar_uc_helper(c, flags, mod[0], 2));
	if (c > 2047 && c < 65535)
		return (ft_putchar_uc_helper(c, flags, mod[0], 3));
	if (c > 65536 && c < 1112064)
		return (ft_putchar_uc_helper(c, flags, mod[0], 4));
	return (0);
}
