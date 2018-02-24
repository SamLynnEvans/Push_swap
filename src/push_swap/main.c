#include "push_swap.h"

int	get_count(t_stack *s)
{
	int		count;
	t_pslst *tmp;

	tmp = s->head;
	while (tmp != s->p[s->top] && count <= 7)
	{
		count++;
		tmp = tmp->nxt;
	}
	if (!s->p[s->top] && count == 3)
		return (1);
	return (count);
}

int	normal_median(t_stack *s)
{
	t_pslst *tmp;
	int m[3];
	int	count;
	int	lim;

	count = 0;
	m[0] = s->head->n;
	m[1] = s->p[s->top]->n;
	tmp = s->head;
	while (tmp != s->p[s->top])
	{
		count++;
		tmp = tmp->nxt;
	}
	lim = count / 2;
	count = 0;
	tmp = s->head;
	while (count++ <= lim)
		tmp = tmp->nxt;
	m[2] = tmp->n;
	if ((m[1] > m[0] && m[1] < m[2]) || (m[1] > m[2] && m[1] < m[0])
		return (m[1]);
	if ((m[0] > m[1] && m[0] < m[2]) || (m[0] > m[2] && m[0] < m[1])
		return (m[0]);
	return (m[2]);
}

int	special_median_a(t_stack *a)
{
	t_pslst *tmp;
	int arr[7]
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

int		deal_higher(t_stack *a, char *cmnds, int med)
{
	if (!a->p[a->top] && !a->head->nxt->nxt->nxt && a->head->nxt->n > med &&
	a->head->nxt->nxt->n > med)
		return (0);
	if (a->head->nxt->nxt == a->p[a->top] && a->head->nxt->n > med)
		return (0);
	rotate(&a->head, &a->end);
	ft_strcat(tmp, "ra\n");
	*count += 1;
	return (1);
}

int		split_round_median_a(t_stack *a, t_stack *b, int med, char *cmnds)
{
	int		count;
	int		i;

	i = 1;
	count = 0;
	if (b->head)
		b->p[++(p->top)] = b->head;
	while (a->head->nxt != a->p[a->top] && i += 3)
	{
		if (a->head->n == med)
			return (-1);
		else if (a->head->n < med)	
		{
			push(a);
			ft_strcat(cmnds, "pa\n");
		}
		else if (!(deal_higher(a, cmnds, med, &count))
			return (i - 4);
	}
	while (a->p[a->top] && --count >= 0 && i += 3)
	{
		rev_rotate(&a->head, &a->end);
		ft_strcat(cmnds, "rra\n");
	}
	return (i - 1);
}

int	split_a(t_stack *a, t_stack *b, t_list **cmnd)
{
	int		count;
	t_pslst	median;
	char	tmp[a->ac];
	int		i;

	i = 0;
	tmp[0] = '\0';
	count = get_count(a);
	median = NULL;
	if (count < 6 && count > 2)
		median = special_median_a(a);
	else if (count > 6)
		median = normal_median(a);
	if (median)
		i = split_round_median_a(a, b, median->n, tmp);
	else
		i = sort(a, count, tmp, i);
	if (i = -1)
		return (-1);
	if (i)
		ft_lstadd(cmnd, ft_lstnew((void *)tmp, i));	
	return ((median) ? 0 : 1);
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
	
	cmnd = ft_lstnew((void *)"\0", 1);
	if (!(sort = sorted(a)))
		while (split_a(a, b, cmnd) == 0)
			;
	if (split == -1)
		exit(1);
	while (b->head != NULL && !sort)
	{
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
	}
	return (cmnd);
}


int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	build_stack(&a, &b, av, ac);
	a->p = malloc(sizeof(t_pslst*) * ac);
	a->ac = ac;
	b->ac = ac;
	b->p = malloc(sizeof(t_pslst*) * ac);
	a->top = 0;
	b->top = 0;
	a->p[a->top] = NULL;
	b->p[a->top] = NULL;
	solver(&a, &b);
//	print_stacks(a.head, b.head, "start");
		
}

/*
finish condition = if pb == NULL && a is sorted from pa
*/
