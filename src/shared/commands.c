/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 18:27:55 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/03/02 12:46:15 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	push(t_pslst **from, t_pslst **to, t_pslst **to_end)
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

void	rotate(t_pslst **head, t_pslst **end)
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

void	rev_rotate(t_pslst **head, t_pslst **end)
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
