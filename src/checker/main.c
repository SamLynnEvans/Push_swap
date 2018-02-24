#include "push_swap.h"

void	error_exit(void)
{
	ft_putstr("KO\n");
	exit(1);
}

void	swapper(char *line, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(line, "sa"))
	{
		swap(&a->head);
		return ;
	}
	if (!ft_strcmp(line, "sb"))
	{
		swap(&b->head);
		return ;
	}
	swap(&a->head);
	swap(&b->head);
}

void	rotater(char *line, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(line, "ra"))
	{
		rotate(&a->head, &a->end);
		return ;
	}
 	if (!ft_strcmp(line, "rb"))
	{
		rotate(&b->head, &b->end);
		return ;
	}
	rotate(&a->head, &a->end);
	rotate(&b->head, &b->end);
}

void	rev_rotater(char *line, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(line, "rra"))
	{
		rev_rotate(&a->head, &a->end);
		return ;
	}
 	if (!ft_strcmp(line, "rrb"))
	{
		rev_rotate(&b->head, &b->end);
		return ;
	}
	rev_rotate(&a->head, &a->end);
	rev_rotate(&b->head, &b->end);
}

int	check_a(t_stack *a)
{
	t_pslst	*tmp;

	tmp = a->head;
	while (tmp->nxt != NULL)
	{
		ft_printf("%d, ", tmp->n);
		if (tmp->nxt->n < tmp->n)
			return (0);
		tmp = tmp->nxt; 
	}
		ft_printf("%d, ", tmp->n);
	return (1);
}

int main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	char	*line;

	build_stack(&a, &b, av, ac);
	print_stacks(a.head, b.head, "start");
	while (get_next_line(0, &line) > 0)
	{
		if (!ft_strcmp(line, "sa") || !ft_strcmp(line, "sb") || !ft_strcmp(line, "ss"))
			swapper(line, &a, &b);
		else if (!ft_strcmp(line, "pa"))
			push(&b.head, &a.head, &a.end);
		else if (!ft_strcmp(line, "pb"))
			push(&a.head, &b.head, &b.end);
		else if (!ft_strcmp(line, "ra") || !ft_strcmp(line, "rb") || !ft_strcmp(line, "rr"))
		rotater(line, &a, &b);
		else if (!ft_strcmp(line, "rra") || !ft_strcmp(line, "rrb") || !ft_strcmp(line, "rrr"))
		rev_rotater(line, &a, &b);
		else
			error_exit();
		print_stacks(a.head, b.head, line); 
		free(line);
	}
	if (!check_a(&a) || b.head)
		error_exit();
	ft_putstr("OK\n");
}
