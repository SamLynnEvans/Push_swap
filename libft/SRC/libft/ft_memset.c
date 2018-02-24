/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 10:48:34 by slynn-ev          #+#    #+#             */
/*   Updated: 2017/12/05 10:52:04 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	value;
	char			*s;
	unsigned long	i;

	i = 0;
	s = (char *)b;
	value = c;
	while (i < len)
		s[i++] = c;
	return (b);
}
