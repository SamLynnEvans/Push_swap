/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 11:21:15 by slynn-ev          #+#    #+#             */
/*   Updated: 2017/12/05 15:19:16 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int			len;
	char		*dst;
	int			i;
	char		*s;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	if ((dst = (char *)malloc(sizeof(char) * (len + 1))))
	{
		s = (char *)s1;
		while (*s)
			dst[i++] = *s++;
		s = (char *)s2;
		while (*s)
			dst[i++] = *s++;
		dst[i] = '\0';
		return ((char *)dst);
	}
	return (NULL);
}
