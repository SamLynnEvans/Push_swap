/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 15:38:14 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/01/22 18:35:51 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		read_count(int count[4])
{
	if (count[2] || count[0] || count[3])
		return (sizeof(long long));
	if (count[1] >= 2)
		return (sizeof(char));
	if (count[1] == 1)
		return (sizeof(short));
	return (sizeof(int));
}

char		get_int_size(char *flags)
{
	int	count[4];
	int	i;

	i = 0;
	while (i < 4)
		count[i++] = 0;
	i = 0;
	while (flags[i])
	{
		if (flags[i] == 'l')
			count[0]++;
		if (flags[i] == 'h')
			count[1]++;
		if (flags[i] == 'j')
			count[2]++;
		if (flags[i] == 'z')
			count[3]++;
		i++;
	}
	return (read_count(count));
}

long long	get_num(va_list ap, int size)
{
	if (size == sizeof(int)
	|| size == sizeof(short) || size == sizeof(char))
		return (va_arg(ap, int));
	return (va_arg(ap, long long));
}

int			get_base(char *c)
{
	if (*c == 'x')
		return (HEXA);
	if (*c == 'X')
		return (HEXA_UPPER);
	if (*c == 'O' || *c == 'o')
		return (OCTAL);
	if (*c == 'b' || *c == 'B')
		return (BINARY);
	return (DECIMAL);
}

int			print_number(va_list ap, char **flags, char *c, int mod[2])
{
	char	int_size;
	int		base;
	int		dot;

	dot = (ft_strrchr(*flags, '.') && mod[1] >= 0) ? 1 : 0;
	if (*c == 'D' || *c == 'O' || *c == 'U')
		*flags = ft_strjoin_free(*flags, "ll");
	base = get_base(c);
	int_size = get_int_size(*flags);
	if (*c == 'u' || *c == 'U')
		return (pf_unsigned(va_arg(ap, unsigned long long), *flags, mod, dot));
	else if (!dot)
		return (pf_signed(get_num(ap, int_size), *flags, mod[0], base));
	else
		return (pf_dot_signed(get_num(ap, int_size), *flags, mod, base));
}
