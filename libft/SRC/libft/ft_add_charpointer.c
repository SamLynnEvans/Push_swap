/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_charpointer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 13:44:59 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/02/28 14:02:52 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_add_charpointer(char **array, char *content, int count)
{
	char	**ret;
	int		i;

	if (content == NULL || count < 0)
		return (NULL);
	if (!(ret = malloc(sizeof(char *) * (count + 1))))
		return (NULL);
	i = -1;
	while (++i < count)
		ret[i] = array[i];
	ret[i] = content;
	if (count != 0)
		free(array);
	return (ret);
}
