/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 10:42:19 by slynn-ev          #+#    #+#             */
/*   Updated: 2017/12/15 14:58:42 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned long	i;
	void			*p;
	const char		*src;
	unsigned char	a;

	a = (unsigned char)c;
	src = s;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)*(src + i) == a)
		{
			p = (void *)(src + i);
			return (p);
		}
		i++;
	}
	return (NULL);
}
