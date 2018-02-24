/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:37:49 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/01/22 15:48:10 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	dot_spaces(int num_l, int mod[2], int precision, int base)
{
	int	count;
	int	min;

	min = (mod[1] > num_l) ? mod[1] : num_l;
	count = 0;
	if (base == DECIMAL && precision)
		precision = 1;
	while (mod[0] > min + precision)
	{
		ft_putchar(' ');
		mod[0]--;
		count++;
	}
	return (count);
}

int	fs(char space_type, int count, int **mod)
{
	if (space_type & SPACE)
	{
		ft_putchar(' ');
		if (mod[0][1] > count)
			mod[0][0]--;
		return (1);
	}
	return (0);
}

int	dot_precision(int base, int num, int mod[2], char *flags)
{
	if (base == DECIMAL)
		return (get_precision(flags, base, num));
	if (base != OCTAL && num != 0)
		return (get_precision(flags, base, num));
	if (base == OCTAL && mod[1] == 0)
		return (get_precision(flags, base, num));
	return (0);
}
