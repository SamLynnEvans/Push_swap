/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 10:17:44 by slynn-ev          #+#    #+#             */
/*   Updated: 2017/12/15 14:56:58 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numlen(int n, int sign)
{
	int	count;

	count = 0;
	while (n)
	{
		n /= 10;
		count++;
	}
	if (sign == -1)
		return (count + 2);
	else
		return (count + 1);
}

static void	fill_string(char *s, int n, int sign)
{
	long	a;
	int		i;
	int		j;

	i = 0;
	j = 0;
	a = n;
	if (sign == -1)
	{
		s[i++] = '-';
		a *= -1;
		j = 1;
	}
	while (a)
	{
		s[i++] = a % 10 + '0';
		a /= 10;
	}
	s[i--] = '\0';
	while (j < i)
	{
		a = s[i];
		s[i--] = s[j];
		s[j++] = a;
	}
}

char		*ft_itoa(int n)
{
	char	*s;
	int		sign;

	if (n == 0)
	{
		if (!(s = (char *)malloc(sizeof(char) * 2)))
			return (NULL);
		s[0] = '0';
		s[1] = '\0';
		return (s);
	}
	sign = 1;
	if (n < 0)
		sign = -1;
	if (!(s = (char *)malloc(sizeof(char) * numlen(n, sign))))
		return (NULL);
	fill_string(s, n, sign);
	return (s);
}
