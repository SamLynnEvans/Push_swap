/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_intdata.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 13:39:45 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/02/28 13:39:47 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*str_to_intdata(char *str, int size)
{
	int *data;
	int	i;

	i = 0;
	data = malloc(sizeof(int) * size);
	while (*str)
	{
		if (ft_isdigit(*str) || (*str == '-' && ft_isdigit(*(str + 1))))
		{
			if (i > size)
				return (NULL);
			data[i++] = ft_atoi(str);
			while (ft_isdigit(*str) || *str == '-')
				str++;
		}
		else
			str++;
	}
	return (data);
}
