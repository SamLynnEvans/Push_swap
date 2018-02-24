/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 11:22:50 by slynn-ev          #+#    #+#             */
/*   Updated: 2017/12/05 15:01:34 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned long	i;
	int				j;
	int				dsize;

	dsize = (ft_strlen((char *)src) + ft_strlen(dst));
	i = 0;
	j = 0;
	if ((unsigned long)ft_strlen(dst) > size)
		return ((int)size + ft_strlen((char *)src));
	while (dst[i])
		i++;
	while (src[j] && i < size - 1)
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (dsize);
}
