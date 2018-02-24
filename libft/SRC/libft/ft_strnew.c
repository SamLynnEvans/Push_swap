/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 11:32:22 by slynn-ev          #+#    #+#             */
/*   Updated: 2017/12/05 15:38:18 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char			*s;
	unsigned long	i;

	i = 0;
	if ((s = (char *)malloc(sizeof(char) * (size + 1))))
	{
		while (i < size + 1)
			s[i++] = '\0';
		return (s);
	}
	return (NULL);
}
