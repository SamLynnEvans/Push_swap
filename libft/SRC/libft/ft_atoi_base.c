/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 13:23:44 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/02/03 11:57:20 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char g_hex[16] = "0123456789abcdef";

int	get_val(char c)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (c == g_hex[i] || c + 32 == g_hex[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, int base)
{
	int	p;
	int	i;
	int	val;

	i = 0;
	p = 0;
	if (*str == '0')
		str++;
	if (*str == 'x' || *str == 'X')
		str++;
	while (ft_isdigit(*str) || HEX_CHAR1 || HEX_PREC)
	{
		if ((val = get_val(*str)) == -1)
			return (0);
		p = base * p + val % base;
		str++;
	}
	return (p);
}
