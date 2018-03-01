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
