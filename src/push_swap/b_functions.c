/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_functions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 14:23:38 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/03/02 12:48:09 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	special_median_b(t_stack *b)
{
	t_pslst *tmp;
	int		arr[7];
	int		i;
	int		j[2];

	tmp = b->head;
	i = 0;
	while (tmp != b->p[b->top])
	{
		arr[i++] = tmp->n;
		tmp = tmp->nxt;
	}
	j[0] = -1;
	while (j[0]++ < i)
	{
		j[1] = j[0];
		while (++j[1] < i)
			if (arr[j[0]] > arr[j[1]])
			{
				arr[6] = arr[j[1]];
				arr[j[1]] = arr[j[0]];
				arr[j[0]] = arr[6];
			}
	}
	return ((!b->p[b->top]) ? arr[2] : arr[1]);
}

int		deal_lower_b(t_stack *b, char *cmnds, int med, int count[2])
{
	int		skips;
	t_pslst *tmp;

	skips = 0;
	tmp = b->head;
	while (tmp != b->p[b->top] && tmp->n <= med)
	{
		skips++;
		tmp = tmp->nxt;
	}
	if (tmp == b->p[b->top])
		return (0);
	count[0] += skips;
	while (skips--)
	{
		rotate(&b->head, &b->end);
		ft_strcat(cmnds, "rb\n");
	}
	return (1);
}

void	split_round_median_b(t_stack *a, t_stack *b, int med, char *cmnds)
{
	int		count[2];

	count[0] = 0;
	count[1] = 0;
	while (b->head != b->p[b->top])
	{
		if (b->head->n > med)
		{
			push(&b->head, &a->head, &a->end);
			ft_strcat(cmnds, "pa\n");
		}
		else if (!(deal_lower_b(b, cmnds, med, count)))
			break ;
	}
	while (b->p[b->top] && --count[0] >= 0)
	{
		rev_rotate(&b->head, &b->end);
		ft_strcat(cmnds, "rrb\n");
	}
}

void	three_caseb(t_stack *a, char *tmp)
{
	while (!(a->head->nxt->n > a->head->nxt->nxt->n
	&& a->head->n > a->head->nxt->nxt->n))
	{
		if (a->head->nxt->n < a->head->nxt->nxt->n
		&& a->head->nxt->n < a->head->n)
		{
			rev_rotate(&a->head, &a->end);
			ft_strcat(tmp, "rrb\n");
		}
		else
		{
			rotate(&a->head, &a->end);
			ft_strcat(tmp, "rb\n");
		}
	}
	if (!(a->head->nxt->n > a->head->n))
		return ;
	swap(&a->head);
	ft_strcat(tmp, "sb\n");
}

void	sort_b(t_stack *b, int count, char *tmp)
{
	if (b->top)
		b->top--;
	if (count == 1 || !count)
		return ;
	if (count == 2)
	{
		if (b->head->nxt && b->head->nxt->n > b->head->n)
		{
			swap(&b->head);
			ft_strcat(tmp, "sb\n");
		}
		return ;
	}
	three_caseb(b, tmp);
}
