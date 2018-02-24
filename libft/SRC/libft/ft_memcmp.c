/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 10:43:22 by slynn-ev          #+#    #+#             */
/*   Updated: 2017/12/05 10:43:47 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char	*s_one;
	unsigned const char	*s_two;
	unsigned long		i;

	s_one = s1;
	s_two = s2;
	i = 0;
	if (n == 0)
		return (0);
	while (s_one[i] == s_two[i] && i < n)
	{
		if (i == n - 1)
			return (0);
		i++;
	}
	return (s_one[i] - s_two[i]);
}
