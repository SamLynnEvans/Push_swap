/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 10:59:26 by slynn-ev          #+#    #+#             */
/*   Updated: 2017/12/05 12:31:58 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_rc_putnbr_fd(long num, int fd)
{
	if (num)
	{
		ft_rc_putnbr_fd(num / 10, fd);
		ft_putchar_fd(num % 10 + '0', fd);
	}
}

void		ft_putnbr_fd(int n, int fd)
{
	long	a;

	a = (long)n;
	if (a < 0)
	{
		a *= -1;
		ft_putchar_fd('-', fd);
	}
	if (a == 0)
		ft_putchar_fd('0', fd);
	else
		ft_rc_putnbr_fd(a, fd);
}
