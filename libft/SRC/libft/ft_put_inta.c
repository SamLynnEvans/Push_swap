/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_inta.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 14:41:39 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/02/02 14:46:59 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_inta(int *arr, int len)
{
	int i;

	i = 0;
	if (len == 0)
		return ;
	ft_putchar('{');
	while (i < len)
	{
		ft_putnbr(arr[i]);
		if (i + 1 < len)
			ft_putstr(", ");
		i++;
	}
	ft_putchar('}');
}
