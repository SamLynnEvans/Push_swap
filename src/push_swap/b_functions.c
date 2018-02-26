#include "push_swap.h"

long	special_median_b(t_stack *b)
{
	t_pslst *tmp;
	int arr[7];
	int	i;
	int j[2];

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
	return ((!b->p[b->top]) ? arr[3] : arr[2]);
}

int		deal_lower_b(t_stack *b, char *cmnds, int med, int count[3])
{
	int skips;
	t_pslst *tmp;

	skips = 0;
	tmp = b->head;
	while (tmp != b->p[b->top] && tmp->n < med)
	{
		skips++;
		tmp = tmp->nxt;
	}
	if (tmp == b->p[b->top])
		return (0);
	count[0] += skips;
	while (skips--)
	{
		rev_rotate(&b->head, &b->end);
		ft_strcat(cmnds, "rrb\n");
		count[2] += 4;
	}
	return (1);
}

int		split_round_median_b(t_stack *a, t_stack *b, int med, char *cmnds)
{
	int		count[3];

	count[0] = 0;
	count[1] = 0;
	count[2] = 0;
	while (b->head != b->p[b->top])
	{
		if (b->head->n == med && count[1])
			return (-1);
		else if (b->head->n > med || (b->head->n == med && !count[1]++))
		{
			push(&b->head, &a->head, &a->end);
			ft_strcat(cmnds, "pa\n");
			count[2] += 3;
		}
		else if (!(deal_lower_b(b, cmnds, med, count)))
			break ;
	}
	while (b->p[b->top] && --count[0] >= 0)
	{
		rotate(&b->head, &b->end);
		ft_strcat(cmnds, "rb\n");
		count[2] += 3;
	}
	return (count[2]);
}

static int three_case(t_stack *a, char *tmp)
{
	int i;

	i = 0;
	if (a->head->n == a->head->nxt->nxt->n || a->head->nxt->n == a->head->nxt->nxt->n)
		return (-1);
	while (1)
	{
		if (a->head->nxt->n > a->head->nxt->nxt->n && a->head->n > a->head->nxt->nxt->n)
		{
			if (a->head->nxt->n > a->head->n)
			{
				
				swap(&a->head);
				ft_strcat(tmp, "sb\n");
				return (i + 3);
			}
			return (i);
		}
		if (a->head->nxt->n < a->head->nxt->nxt->n && a->head->nxt->n < a->head->n)
		{
			rotate(&a->head, &a->end);
			ft_strcat(tmp, "rb\n");
			i += 3;
		}
		else
		{
			rev_rotate(&a->head, &a->end);
			ft_strcat(tmp, "rrb\n");
			i += 4;
		}
	}
}

int	sort_b(t_stack *b, int count, char *tmp)
{
	if (b->top)
		b->top--;
	if (count == 1)
		return (0);
	if (b->head->n == b->head->nxt->n)
		return (-1);
	if (count == 2)
	{
		if (b->head->nxt->n > b->head->n)
		{
			swap(&b->head);
			ft_strcat(tmp, "sb\n");
			return (3);
		}
		return (0);	
	}
	return (three_case(b, tmp));
}
