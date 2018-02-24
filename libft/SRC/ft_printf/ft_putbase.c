/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase_lower.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:45:10 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/01/21 23:33:20 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char	g_hexa[16] = "0123456789abcdef";
char	g_hexa_uc[16] = "0123456789ABCDEF";

void	rc_putbase(unsigned long long num, int base)
{
	if (num)
	{
		rc_putbase(num / base, base);
		ft_putchar(g_hexa[num % base]);
	}
}

void	rc_putbase_upper(unsigned long long num, int base)
{
	if (num)
	{
		rc_putbase_upper(num / base, base);
		ft_putchar(g_hexa_uc[num % base]);
	}
}

void	ft_print_output(char *output, int output_len)
{
	int	first_letter;

	first_letter = 1;
	output_len--;
	while (output_len >= 0)
	{
		ft_putchar(output[output_len]);
		first_letter = 0;
		output_len--;
	}
}

void	neg_base_printer(long long num, int base, int int_size, int caps)
{
	char	output[64];
	int		bitmask;
	int		mask_width;
	int		x;
	int		count[2];

	x = 0;
	count[1] = 0;
	mask_width = (base == HEXA) ? 4 : 1;
	mask_width = (base == OCTAL) ? 3 : mask_width;
	while (x < int_size)
	{
		bitmask = 0;
		count[0] = -1;
		if (base == OCTAL && x + 3 >= int_size)
			mask_width = mask_width - (3 - (int_size % 3));
		while (++count[0] < mask_width)
		{
			if ((num & 1UL << x))
				bitmask ^= 1UL << count[0];
			x++;
		}
		output[count[1]++] = (caps) ? g_hexa_uc[bitmask] : g_hexa[bitmask];
	}
	ft_print_output(output, count[1]);
}

void	ft_putbase(long long num, int base, int int_size)
{
	int	caps;

	caps = 0;
	if (base == HEXA_UPPER)
	{
		caps = 1;
		base = HEXA;
	}
	if (num < 0 && base == DECIMAL)
		num *= -1;
	base = (base == OCTAL_UPPER) ? OCTAL : base;
	if (num == 0)
		ft_putchar('0');
	if (num < 0 && base != DECIMAL)
		neg_base_printer(num, base, int_size, caps);
	else
	{
		if (!caps)
			rc_putbase(num, base);
		else
			rc_putbase_upper(num, base);
	}
}
