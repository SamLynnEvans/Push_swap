/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 14:29:54 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/03/01 18:39:26 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	t_list	*cmnd;

	build_stack(&a, &b, av, ac);
	a.p = malloc(sizeof(t_pslst*) * ac);
	a.ac = ac;
	b.ac = ac;
	b.p = malloc(sizeof(t_pslst*) * ac);
	a.top = 0;
	b.top = 0;
	a.p[a.top] = NULL;
	b.p[a.top] = NULL;
	cmnd = solver(&a, &b);
	while (cmnd != NULL)
	{
		ft_putstr((char *)cmnd->content);
		cmnd = cmnd->next;
	}
}
