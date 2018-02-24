/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode_utf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 22:37:04 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/01/22 17:10:04 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	int_putchar(int c)
{
	write(1, &c, 1);
}

static void	print_uc_two_byte(int c)
{
	unsigned char x[2];

	x[0] = 192 | ((1984 & c) >> 6);
	x[1] = 128 | (63 & c);
	write(1, x, 2);
}

static void	print_uc_three_byte(int c)
{
	unsigned char	x[3];

	x[0] = 224 | ((61440 & c) >> 12);
	x[1] = 128 | ((4032 & c) >> 6);
	x[2] = 128 | (63 & c);
	write(1, x, 3);
}

static void	print_uc_four_byte(int c)
{
	unsigned char x[4];

	x[0] = 240 | ((1835008 & c) >> 18);
	x[1] = 128 | ((258048 & c) >> 12);
	x[2] = 128 | ((4032 & c) >> 6);
	x[3] = 128 | (63 & c);
	write(1, x, 4);
}

void		ft_unicode_putchar(int c)
{
	if (c < 127 && c >= 0)
		int_putchar(c);
	if (c > 127 && c < 2047)
		print_uc_two_byte(c);
	if (c > 2047 && c < 65535)
		print_uc_three_byte(c);
	if (c > 65536 && c < 1112064)
		print_uc_four_byte(c);
}
