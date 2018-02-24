/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_printers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 22:01:39 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/01/22 18:17:27 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned long long	ushorten_num(long long n, int size)
{
	if (size == sizeof(int))
		return ((unsigned int)n);
	if (size == sizeof(char))
		return ((unsigned char)n);
	if (size == sizeof(short))
		return ((unsigned short)n);
	return (0);
}

static	long long			shorten_number(long long num, int int_size)
{
	if (int_size == sizeof(short))
		return ((short)num);
	return ((char)num);
}

int							pf_signed(long long num,
char *flags, int mod, int base)
{
	char	space_type;
	int		p;
	int		num_length;
	char	int_size;

	int_size = get_int_size(flags);
	if (int_size == sizeof(char) || int_size == sizeof(short))
		num = shorten_number(num, int_size);
	p = (base == DECIMAL || num != 0) ? get_precision(flags, base, num) : 0;
	num_length = ft_numlen(num, base, int_size);
	space_type = bit_space_type(flags);
	if (!p && base == DECIMAL && (space_type & SPACE))
		num_length += print_spaces(1);
	if (!(space_type & MINUS) && !(space_type & ZERO))
		num_length += print_spaces(mod - (num_length + ((p == NEG) ? 1 : p)));
	if (p)
		num_length += print_precision(base, p);
	if (space_type & ZERO && !(space_type & MINUS))
		num_length += print_zeroes(mod - num_length);
	ft_putbase(num, base, int_size * 8);
	if (space_type & MINUS)
		num_length += print_spaces(mod - num_length);
	return (num_length);
}

int							pf_unsigned(unsigned long long num,
char *flags, int mod[2], int dot)
{
	char				space_type;
	int					num_l;
	int					size;
	int					count;

	size = get_int_size(flags);
	if (size != sizeof(long long))
		num = ushorten_num(num, size);
	num_l = (mod[1] == 0 && num == 0 && dot) ?
	0 : ft_unumlen(num);
	count = num_l;
	space_type = bit_space_type(flags);
	if (!(space_type & MINUS) && (dot || !(space_type & ZERO)))
		count += dot_spaces(num_l, mod, 0, 10);
	if (dot)
		count += print_zeroes(mod[1] - num_l);
	else if (space_type & ZERO)
		count += print_zeroes(mod[0] - num_l);
	if (num == 0 && (mod[1] != 0 || !dot))
		ft_putchar('0');
	else if (mod[1] != 0 || num != 0)
		rc_putbase(num, DECIMAL);
	if (space_type & MINUS)
		count += print_spaces(mod[0] - count);
	return (count);
}

int							pf_dot_signed(long long num,
char *flags, int mod[2], int base)
{
	char	space_type;
	int		num_l;
	int		p;
	int		size;
	int		count;

	size = get_int_size(flags);
	if (size == sizeof(char) || size == sizeof(short))
		num = shorten_number(num, size);
	num_l = (mod[1] == 0 && num == 0) ? 0 : ft_numlen(num, base, size);
	count = num_l;
	space_type = bit_space_type(flags);
	p = dot_precision(base, num, mod, flags);
	mod[1] -= (base == OCTAL) ? p : 0;
	count += (base == DECIMAL) ? fs(space_type, count, &mod) : 0;
	if (!(space_type & MINUS))
		count += dot_spaces(num_l, mod, p, base);
	if (p)
		count += print_precision(base, p);
	count += print_zeroes(mod[1] - num_l);
	if (mod[1] > 0 || num != 0)
		ft_putbase(num, base, size * 8);
	if (space_type & MINUS)
		count += print_spaces(mod[0] - count);
	return (count);
}
