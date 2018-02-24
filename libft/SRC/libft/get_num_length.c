/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_num_length.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 14:21:05 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/01/21 22:56:17 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_numlen(long long num, int base, size_t size)
{
	int count;

	count = 0;
	base = (base == OCTAL_UPPER) ? OCTAL : base;
	base = (base == HEXA_UPPER) ? HEXA : base;
	if (base != DECIMAL && num < 0)
	{
		if (base == OCTAL)
			return (size * 8 / 3 + 1);
		if (base == HEXA)
			return (size * 8 / 4);
		if (base == BINARY)
			return (size * 8);
	}
	if (base == DECIMAL && num < 0)
		num *= -1;
	while (num)
	{
		num /= base;
		count++;
	}
	return ((count == 0) ? 1 : count);
}

int	ft_unumlen(unsigned long long num)
{
	int count;

	count = 0;
	while (num)
	{
		num /= 10;
		count++;
	}
	return ((count == 0) ? 1 : count);
}
