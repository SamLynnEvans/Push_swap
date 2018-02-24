/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 11:24:43 by slynn-ev          #+#    #+#             */
/*   Updated: 2017/12/05 15:19:05 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*dst;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i])
		i++;
	if ((dst = (char *)malloc(sizeof(char) * (i + 1))))
	{
		i = 0;
		while (*s)
			dst[i++] = (*f)(*s++);
		dst[i] = '\0';
		return (dst);
	}
	return (NULL);
}
