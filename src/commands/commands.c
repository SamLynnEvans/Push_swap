#include "push_swap.h"

void	print_stacks(t_pslst *a, t_pslst *b, char *line)
{
	t_pslst *tmp;

	tmp = a;
	ft_printf("%s\na: ", line);
	while (tmp != NULL)
	{
		ft_printf("%d, ", tmp->n);
		tmp = tmp->nxt;
	}
	tmp = b;
	ft_putstr("\nb : ");
	while (tmp != NULL)
	{
		ft_printf("%d, ", tmp->n);
		tmp = tmp->nxt;
	}
	ft_putchar('\n');
}	


void	lst_addend_fast(int n, t_pslst **back)
{
	t_pslst *tmp;

	if (*back == NULL)
		return ;
	tmp = malloc(sizeof(t_pslst));
	tmp->n = n;
	tmp->nxt = NULL;
	(*back)->nxt = tmp;
	tmp->prv = *back;
	*back = tmp;
}

void	build_stack(t_stack *a, t_stack *b, char **av, int ac)
{
	int		i;

	i = 1;
	
	a->head = malloc(sizeof(t_pslst));
	a->head->n = ft_atoi(av[i++]);
	a->head->prv = NULL;
	a->end = a->head;
	while (i < ac)
		lst_addend_fast(ft_atoi(av[i++]), &a->end);
	b->head = NULL;
	b->end = NULL;
} 

void 	push(t_pslst **from, t_pslst **to, t_pslst **to_end)
{
	t_pslst *tmp;

	if (*from == NULL)
		return ;
	tmp = *from;
	*from = (*from)->nxt;
	if (*from)
		(*from)->prv = NULL;
	if (*to)
		(*to)->prv = tmp;
	else
		*to_end = tmp;
	tmp->nxt = *to;
	*to = tmp;
	(*to)->prv = NULL;
}

void	swap(t_pslst **head)
{
	t_pslst *tmp;

	if (*head == NULL || (*head)->nxt == NULL)
		return ;
	tmp = *head;
	*head = (*head)->nxt;
	tmp->nxt = (*head)->nxt;
	tmp->prv = *head;
	(*head)->nxt = tmp;
	(*head)->prv = NULL;
}

void	rev_rotate(t_pslst **head, t_pslst **end)
{
	if (*head == NULL || *end == NULL || (*head)->nxt == NULL)
		return ;
	(*end)->nxt = *head;
	(*head)->prv = *end;
	*head = (*head)->nxt;
	(*head)->prv = NULL;
	*end = (*end)->nxt;
	(*end)->nxt = NULL;

}

void	rotate(t_pslst **head, t_pslst **end)
{
	if (*head == NULL || *end == NULL || (*end)->prv == NULL)
		return ;
	(*head)->prv = *end;
	(*end)->nxt = *head;
	*head = *end;
	*end = (*end)->prv;
	(*end)->nxt = NULL;
	(*head)->prv = NULL;
}
