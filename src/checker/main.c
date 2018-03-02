/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 17:35:20 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/03/02 12:49:39 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_exit(t_stack *a, t_stack *b, int ok)
{
	t_pslst	*tmp;

	while (a->head)
	{
		tmp = a->head;
		a->head = a->head->nxt;
		free(tmp);
	}
	while (b->head)
	{
		tmp = b->head;
		b->head = b->head->nxt;
		free(tmp);
	}
	if (ok)
		ft_putstr("OK\n");
	if (!ok)
		ft_putstr("KO\n");
	exit(1);
}

int		check_a(t_stack *a)
{
	t_pslst	*tmp;

	tmp = a->head;
	while (tmp->nxt != NULL)
	{
		if (tmp->nxt->n < tmp->n)
			return (0);
		tmp = tmp->nxt;
	}
	return (1);
}

int		main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	char	*l;

	build_stack(&a, &b, av, ac);
	while (get_next_line(0, &l) > 0)
	{
		if (!STRCMP(l, "sa") || !STRCMP(l, "sb") || !STRCMP(l, "ss"))
			swapper(l, &a, &b);
		else if (!STRCMP(l, "pa"))
			push(&b.head, &a.head, &a.end);
		else if (!STRCMP(l, "pb"))
			push(&a.head, &b.head, &b.end);
		else if (!STRCMP(l, "ra") || !STRCMP(l, "rb") || !STRCMP(l, "rr"))
			rotater(l, &a, &b);
		else if (!STRCMP(l, "rra") || !STRCMP(l, "rrb") || !STRCMP(l, "rrr"))
			rev_rotater(l, &a, &b);
		else
			print_exit(&a, &b, 0);
		free(l);
	}
	if (!check_a(&a) || b.head)
		print_exit(&a, &b, 0);
	print_exit(&a, &b, 1);
}
