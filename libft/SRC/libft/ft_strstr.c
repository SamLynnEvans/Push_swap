/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 11:39:04 by slynn-ev          #+#    #+#             */
/*   Updated: 2017/12/05 11:39:56 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;

	if (!*needle)
		return ((char *)haystack);
	while (*haystack)
	{
		i = 0;
		if (*haystack == needle[i])
		{
			while (haystack[i] == needle[i])
			{
				i++;
				if (needle[i] == '\0')
					return ((char *)haystack);
			}
		}
		haystack++;
	}
	return (NULL);
}
