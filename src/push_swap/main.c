#include "push_swap.h"

int	get_count(t_stack *s)
{
	int		count;
	t_pslst *tmp;

	tmp = s->head;
	count = 0;
	while (tmp != s->p[s->top] && count < 12)
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
	m[1] = (s->p[s->top]) ? s->p[s->top]->n : s->end->n;
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

int	get_true_median(t_stack *a)
{
	t_pslst *tmp;
	int arr[a->ac + 1];
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
				arr[a->ac] = arr[j[1]];
				arr[j[1]] = arr[j[0]];
				arr[j[0]] = arr[a->ac];
			}
	}
	return (arr[i / 2]);
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
	if (count <= 6 && count > 2)
		median = special_median_a(a);
	else if (count > 6)
		median = get_true_median(a);
	if (median != NO_MED)
		i = split_round_median_a(a, b, (int)median, tmp);
	else
		i = sort_a(a, count, tmp);
	if (i == -1)
		return (-1);
	if (i++)
	{
		ft_lstaddend(cmnd, ft_lstnew((void *)tmp, i));
	}
	if (median == NO_MED)
		a->p[++(a->top)] = a->head;
//	ft_printf("%s\n", tmp);
//	print_stacks(a->head, b->head, "start");		
	return ((median == NO_MED) ? 1 : 0);
}

int	push_b(t_stack *b, t_stack *a, int count, char *tmp)
{
	int i;
	int	ret;

	ret = 0;
	i = 0;
	count = (count == -1) ? 3 : count;
	while (i++ < count)
	{
		push(&b->head, &a->head, &a->end);
		ft_strcat(tmp, "pa\n");
		ret += 3;
	}
	return (ret);
}

int	b_to_a(t_stack *a, t_stack *b, t_list **cmnd)
{
	int		count;
	long	median;
	char	tmp[a->ac * 4];
	int		i;

	i = 0;
	tmp[0] = '\0';
	count = get_count(b);
	median = NO_MED;
	if (count <= 6 && count > 2)
		median = special_median_b(b);
	else if (count > 6)
		median = get_true_median(b);
	if (median != NO_MED)
		i = split_round_median_b(a, b, (int)median, tmp);
	else
		i = sort_b(b, count, tmp);
	if (i == -1)
		return (-1);
	if (median == NO_MED)
		i += push_b(b, a, count, tmp);
	if (i++)
	{
		//tmp[i++] = '\0'; 
		ft_lstaddend(cmnd, ft_lstnew((void *)tmp, i));
	}
//	ft_printf("%s\n", tmp);
//	print_stacks(a->head, b->head, "start");		
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
	int	ret;

	cmnd = ft_lstnew((void *)"\0", 1);
	while (b->head != NULL || !sorted(a))
	{
		while ((ret = split_a(a, b, &cmnd)) == 0)
			;
		if (ret == -1)
			exit(1);
		b_to_a(a, b, &cmnd);
	}
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
//	simple_sort(&a, &b);
//	print_stacks(a.head, b.head, "start");
	cmnd = solver(&a, &b);
	while (cmnd != NULL)
	{
		ft_putstr((char *)cmnd->content);
		cmnd = cmnd->next;
	}
}

/*
finish condition = if pb == NULL && a is sorted from pa
*/
