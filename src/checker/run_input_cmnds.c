/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_input_cmnds.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 17:33:22 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/03/01 18:38:00 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
