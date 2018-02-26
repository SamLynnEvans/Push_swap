#include "push_swap.h"

int	get_count(t_stack *s)
{
	int		count;
	t_pslst *tmp;

	tmp = s->head;
	count = 0;
	while (tmp != s->p[s->top] && count <= 7)
	{
		count++;
		tmp = tmp->nxt;
	}
	if (!s->p[s->top] && count == 3)
		return (-1);
	return (count);
}

long	normal_median(t_stack *s)
{
	t_pslst *tmp;
	int m[3];
	int	count;
	int	lim;

	count = 0;
	m[0] = s->head->n;
	if (s->p[s->top])
		m[1] = s->p[s->top]->n;
	else
		m[1] = s->end->n;
	tmp = s->head;
	while (tmp != s->p[s->top])
	{
		count++;
		tmp = tmp->nxt;
	}
	lim = count / 2;
	count = 0;
	tmp = s->head;
	while (count++ < lim - 1)
		tmp = tmp->nxt;
	m[2] = tmp->n;
	if ((m[1] > m[0] && m[1] < m[2]) || (m[1] > m[2] && m[1] < m[0]))
		return (m[1]);
	if ((m[0] > m[1] && m[0] < m[2]) || (m[0] > m[2] && m[0] < m[1]))
		return (m[0]);
	return (m[2]);
}

long	special_median_a(t_stack *a)
{
	t_pslst *tmp;
	int arr[7];
	int	i;
	int j[2];

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
				arr[6] = arr[j[1]];
				arr[j[1]] = arr[j[0]];
				arr[j[0]] = arr[6];
			}
	}
	return ((!a->p[a->top]) ? arr[3] : arr[2]);
}

int		deal_higher_a(t_stack *a, char *cmnds, int med, int count[3])
{
	int skips;
	t_pslst *tmp;

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
		count[2] += 4;
	}
	return (1);
}

int		split_round_median_a(t_stack *a, t_stack *b, int med, char *cmnds)
{
	int		count[3];

	count[0] = 0;
	count[1] = 0;
	count[2] = 0;
	if (b->p[b->top])
		ft_intdebug(b->p[b->top]->n, "bstack");
	while (a->head->nxt != a->p[a->top])
	{
		if (a->head->n == med && count[1])
			return (-1);
		else if (a->head->n < med || (a->head->n == med && !count[1]++))
		{
			push(&a->head, &b->head, &b->end);
			ft_strcat(cmnds, "pb\n");
			count[2] += 3;
		}
		else if (!(deal_higher_a(a, cmnds, med, count)))
			break ;
	}
	while (a->p[a->top] && --count[0] >= 0)
	{
		rotate(&a->head, &a->end);
		ft_strcat(cmnds, "ra\n");
		count[2] += 3;
	}
	b->p[++(b->top)] = b->head;
	return (count[2]);
}

int three_case(t_stack *a, char *tmp)
{
	int i;

	i = 0;
	if (a->head->n == a->head->nxt->nxt->n || a->head->nxt->n == a->head->nxt->nxt->n)
		return (-1);
	while (1)
	{
		if (a->head->nxt->n < a->head->nxt->nxt->n && a->head->n < a->head->nxt->nxt->n)
		{
			if (a->head->nxt->n < a->head->n)
			{
				
				swap(&a->head);
				ft_strcat(tmp, "sa\n");
				return (i + 3);
			}
			return (i);
		}
		if (a->head->nxt->n > a->head->nxt->nxt->n && a->head->nxt->n > a->head->n)
		{
			rotate(&a->head, &a->end);
			ft_strcat(tmp, "ra\n");
			i += 3;
		}
		else
		{
			rev_rotate(&a->head, &a->end);
			ft_strcat(tmp, "rra\n");
			i += 4;
		}
	}
}
int	sort_a(t_stack *a, int count, char *tmp)
{
	if (count == 1)
		return (0);
	if (a->head->n == a->head->nxt->n)
		return (-1);
	if (count == 2)
	{
		if (a->head->nxt->n < a->head->n)
		{
			swap(&a->head);
			ft_strcat(tmp, "sa\n");
			return (3);
		}
		return (0);	
	}
	return (three_case(a, tmp));
}

int	split_a(t_stack *a, t_stack *b, t_list **cmnd)
{
	int		count;
	long	median;
	char	tmp[a->ac * 4];
	int		i;

	i = 0;
	tmp[0] = '\0';
	count = get_count(a);
	median = NO_MED;
	if (count < 6 && count > 2)
		median = special_median_a(a);
	else if (count > 6)
		median = normal_median(a);
	if (median != NO_MED)
		i = split_round_median_a(a, b, (int)median, tmp);
	else
		i = sort_a(a, count, tmp);
	if (i == -1)
		return (-1);
	if (i)
	{
		tmp[i++] = '\0'; 
		ft_lstaddend(cmnd, ft_lstnew((void *)tmp, i));
	}
//	ft_intdebug(median, "median");
	print_stacks(a->head, b->head, "TURN");		
	return ((median == NO_MED) ? 1 : 0);
}

int	sorted(t_stack *a)
{
	t_pslst	*tmp;

	tmp = a->head;
	while (tmp->nxt != a->p[a->top])
	{
		if (tmp->nxt->n < tmp->n)
			return (0);
		tmp = tmp->nxt; 
	}
	return (1);
}

t_list *solver(t_stack *a, t_stack *b)
{
	t_list *cmnd;
	int	sort;

	sort = 0;	
	cmnd = ft_lstnew((void *)"\0", 1);
//	if (!(sort = sorted(a)))
	while (split_a(a, b, &cmnd) == 0)
			;
//	split_a(a, b, &cmnd);
	if (sort == -1)
		exit(1);
//	while (b->head != NULL && !sort)
//	{
		/*get_count, if count over 6, split with normal median, if under 6, split with special median, if 2 or under, skip split, 
		A:
		solve = 0;
		while (!solve_a(a, b))
		solve(a, b)
		{
			count = get_count_a;
			median = NULL;
			if (count < 6 && count > 2)
				median = spesh_med;
			else if (count > 6)
				median = norm_med;
		}
		if (median)
			split_at_median;
		else
		{
			solve(a, count);
			set_new_pa;
			i++;
			return (1);
		}
		b_back_to_a(b, a, ba, pa);
		fun
		{
			


		}
		
		

		if (under_six(a, pa))
		{

			median = get_median(a);
			if (median)
		// sort a and create new pa[]
		}
		// else median = normal method
		*/
//	}
	return (cmnd);
}


int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	t_list *cmnd;

	build_stack(&a, &b, av, ac);
	a.p = malloc(sizeof(t_pslst*) * ac);
	a.ac = ac;
	b.ac = ac;
	b.p = malloc(sizeof(t_pslst*) * ac);
	a.top = 0;
	b.top = 0;
	a.p[a.top] = NULL;
	b.p[a.top] = NULL;
	print_stacks(a.head, b.head, "start");		
	cmnd = solver(&a, &b);
	while (cmnd != NULL)
	{
		ft_putstr((char *)cmnd->content);
		cmnd = cmnd->next;
	}
	//print_stacks(a.head, b.head, "start");		
}

/*
finish condition = if pb == NULL && a is sorted from pa
*/
