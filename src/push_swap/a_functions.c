/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_functions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 18:58:34 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/03/01 19:11:50 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	special_median_a(t_stack *a)
{
	t_pslst	*tmp;
	int		arr[12];
	int		i;
	int		j[2];

	tmp = a->head;
	i = 0;
	while (tmp != a->p[a->top])
	{
		arr[i++] = tmp->n;
		tmp = tmp->nxt;
	}
	j[0] = -1;
	while (j[0]++ < i)
	{
		j[1] = j[0];
		while (++j[1] < i)
			if (arr[j[0]] < arr[j[1]])
			{
				arr[11] = arr[j[1]];
				arr[j[1]] = arr[j[0]];
				arr[j[0]] = arr[11];
			}
	}
	return ((!a->p[a->top]) ? arr[3] : arr[2]);
}

int		deal_higher_a(t_stack *a, char *cmnds, int med, int count[2])
{
	int		skips;
	t_pslst	*tmp;

	skips = 0;
	tmp = a->head;
	while (tmp != a->p[a->top] && tmp->n > med)
	{
		skips++;
		tmp = tmp->nxt;
	}
	if (tmp == a->p[a->top])
		return (0);
	count[0] += skips;
	while (skips--)
	{
		rev_rotate(&a->head, &a->end);
		ft_strcat(cmnds, "rra\n");
	}
	return (1);
}

void	split_round_median_a(t_stack *a, t_stack *b, int med, char *cmnds)
{
	int		count[2];

	count[0] = 0;
	count[1] = 0;
	if (b->head)
		b->p[++(b->top)] = b->head;
	while (a->head != a->p[a->top])
	{
		if (a->head->n <= med)
		{
			push(&a->head, &b->head, &b->end);
			ft_strcat(cmnds, "pb\n");
		}
		else if (!(deal_higher_a(a, cmnds, med, count)))
			break ;
	}
	while (a->p[a->top] && --count[0] >= 0)
	{
		rotate(&a->head, &a->end);
		ft_strcat(cmnds, "ra\n");
	}
}

void	three_case(t_stack *a, char *tmp)
{
	if (a->head->n == a->head->nxt->nxt->n
	|| a->head->nxt->n == a->head->nxt->nxt->n)
		exit(1);
	while (!(a->head->nxt->n < a->head->nxt->nxt->n
	&& a->head->n < a->head->nxt->nxt->n))
	{
		if (a->head->nxt->n > a->head->nxt->nxt->n
		&& a->head->nxt->n > a->head->n)
		{
			rotate(&a->head, &a->end);
			ft_strcat(tmp, "ra\n");
		}
		else
		{
			rev_rotate(&a->head, &a->end);
			ft_strcat(tmp, "rra\n");
		}
	}
	if (!(a->head->nxt->n < a->head->n))
		return ;
	swap(&a->head);
	ft_strcat(tmp, "sa\n");
}

void	sort_a(t_stack *a, int count, char *tmp)
{
	if (count == 1)
		return ;
	if (a->head->n == a->head->nxt->n)
		error_exit();
	if (count == 2)
	{
		if (a->head->nxt->n < a->head->n)
		{
			swap(&a->head);
			ft_strcat(tmp, "sa\n");
		}
		return ;
	}
	three_case(a, tmp);
}
