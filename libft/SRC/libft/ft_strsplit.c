/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 11:35:16 by slynn-ev          #+#    #+#             */
/*   Updated: 2017/12/07 11:42:25 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	c_count(const char *s, char c)
{
	int	count;
	int	is_word;

	is_word = 0;
	count = 0;
	while (*s)
	{
		if (*s != c && is_word == 0)
		{
			is_word = 1;
			count++;
			while (*s != c)
				s++;
		}
		while (*s == c)
		{
			is_word = 0;
			s++;
		}
	}
	return (count + 1);
}

static int	allocate_length(char **split, const char *s, char c, int i)
{
	int	count;

	count = 0;
	while (s[count] != c && s[count] != '\0')
		count++;
	if (!(split[i] = (char *)malloc(sizeof(char) * count + 1)))
		return (0);
	return (1);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**t;
	int		i;
	int		j;

	i = 0;
	if (s == NULL || !(t = (char **)malloc(sizeof(char *) * (c_count(s, c)))))
		return (NULL);
	while (*s)
	{
		j = 0;
		while (*s == c)
			s++;
		if (*s != '\0')
		{
			if (!allocate_length(t, s, c, i))
				return (NULL);
			while (*s != c && *s != '\0')
				t[i][j++] = *s++;
			t[i][j] = '\0';
			i++;
		}
	}
	t[i] = 0;
	return (t);
}
