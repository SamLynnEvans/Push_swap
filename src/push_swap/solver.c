/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 13:52:50 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/03/02 12:34:21 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		split_a(t_stack *a, t_stack *b, t_list **cmnd)
{
	int		count;
	long	median;
	char	tmp[a->ac * 4];

	tmp[0] = '\0';
	count = get_count(a);
	median = NO_MED;
	if (count <= 11 && count > 2)
		median = special_median_a(a);
	else if (count > 11)
		median = get_true_median(a);
	if (median != NO_MED)
		split_round_median_a(a, b, (int)median, tmp);
	else
		sort_a(a, count, tmp);
	if (tmp[0])
		ft_lstaddend(cmnd, ft_lstnew_str(tmp));
	if (median == NO_MED)
		a->p[++(a->top)] = a->head;
	return ((median == NO_MED) ? 1 : 0);
}

int		sorted(t_stack *a)
{
	t_pslst	*tmp;

	tmp = a->head;
	while (tmp)
	{
		if (tmp->nxt && tmp->nxt->n < tmp->n)
			return (0);
		tmp = tmp->nxt;
		if (tmp == a->p[a->top])
			break ;
	}
	return (1);
}

void	push_b(t_stack *b, t_stack *a, int count, char *tmp)
{
	int i;

	i = 0;
	count = (count == -1) ? 3 : count;
	while (i++ < count)
	{
		push(&b->head, &a->head, &a->end);
		ft_strcat(tmp, "pa\n");
	}
}

void	b_to_a(t_stack *a, t_stack *b, t_list **cmnd)
{
	int		count;
	long	median;
	char	tmp[a->ac * 4];

	tmp[0] = '\0';
	count = get_count(b);
	median = NO_MED;
	if (count <= 6 && count > 2)
		median = special_median_b(b);
	else if (count > 6)
		median = get_true_median(b);
	if (median != NO_MED)
		split_round_median_b(a, b, (int)median, tmp);
	else
		sort_b(b, count, tmp);
	if (median == NO_MED)
		push_b(b, a, count, tmp);
	if (tmp[0])
		ft_lstaddend(cmnd, ft_lstnew_str(tmp));
}

t_list	*solver(t_stack *a, t_stack *b)
{
	t_list	*cmnd;
	int		ret;
	int		sort;

	cmnd = ft_lstnew((void *)"\0", 1);
	while (!(sort = sorted(a)) || b->head != NULL)
	{
		if (!sort)
		{
			while ((ret = split_a(a, b, &cmnd)) == 0)
				;
			if (ret == -1)
				exit(1);
		}
		else
			a->p[++(a->top)] = a->head;
		b_to_a(a, b, &cmnd);
	}
	return (cmnd);
}
