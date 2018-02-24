/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 11:41:27 by slynn-ev          #+#    #+#             */
/*   Updated: 2017/12/05 15:40:05 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_spclslen(char const *s)
{
	int	count;
	int	start;

	start = 0;
	count = 0;
	while (*s)
	{
		if (start == 1)
			count++;
		if (start == 0 && *s != ' ' && *s != '\n' && *s != '\t')
		{
			start = 1;
			count++;
		}
		s++;
	}
	s--;
	while (start == 1 && (*s == ' ' || *s == '\n' || *s == '\t'))
	{
		count--;
		s--;
	}
	return (count);
}

static void	trimmer(char const *s, char *spaceless, int len)
{
	int	i;
	int	start;

	start = 0;
	i = 0;
	while (i < len)
	{
		if (start == 1)
			spaceless[i++] = *s;
		if (start == 0 && *s != ' ' && *s != '\n' && *s != '\t')
		{
			start = 1;
			spaceless[i++] = *s;
		}
		s++;
	}
	spaceless[i] = '\0';
}

static char	*ft_strtrim_helper(char const *s)
{
	char			*spaceless;
	unsigned long	i;
	unsigned long	len;

	i = 0;
	len = ft_spclslen(s);
	if (len == 0)
	{
		if (!(spaceless = (char *)malloc(sizeof(char) * 1)))
			return (NULL);
		spaceless[0] = '\0';
		return (spaceless);
	}
	if (len == ft_strlen((char *)s))
		return (ft_strdup((char *)s));
	if ((spaceless = (char *)malloc(sizeof(char) * (len + 1))))
	{
		trimmer(s, spaceless, len);
		return (spaceless);
	}
	return (NULL);
}

char		*ft_strtrim(char const *s)
{
	if (s == NULL)
		return (NULL);
	return (ft_strtrim_helper(s));
}
