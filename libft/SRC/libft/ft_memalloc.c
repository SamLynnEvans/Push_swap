/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 10:39:06 by slynn-ev          #+#    #+#             */
/*   Updated: 2017/12/15 14:59:27 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *p;

	if (size == 0)
	{
		return (NULL);
	}
	else if (!(p = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	ft_bzero(p, size);
	return (p);
}
