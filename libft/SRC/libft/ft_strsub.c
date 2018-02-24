/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 11:40:19 by slynn-ev          #+#    #+#             */
/*   Updated: 2017/12/05 15:39:03 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*cpy;
	unsigned long	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	if ((cpy = (char *)malloc(sizeof(char) * (len + 1))))
	{
		while (i < len)
		{
			cpy[i] = s[start + i];
			i++;
		}
		cpy[i] = '\0';
		return (cpy);
	}
	return (NULL);
}
