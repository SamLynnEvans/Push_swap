/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 19:26:55 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/03/02 12:34:42 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define NO_MED 2147483648
# define STRCMP ft_strcmp

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include <limits.h>

typedef struct		s_pslst
{
	int				n;
	struct s_pslst	*nxt;
	struct s_pslst	*prv;
}					t_pslst;

typedef struct		s_stack
{
	t_pslst			*head;
	t_pslst			*end;
	t_pslst			**p;
	int				top;
	int				ac;
}					t_stack;

void				push(t_pslst **from, t_pslst **to, t_pslst **to_end);
void				swap(t_pslst **head);
void				rotate(t_pslst **head, t_pslst **end);
void				rev_rotate(t_pslst **head, t_pslst **end);
void				build_stack(t_stack *a, t_stack *b, char **av, int ac);
void				print_stacks(t_pslst *a, t_pslst *b, char *line);
long				special_median_a(t_stack *a);
int					deal_higher_a(t_stack *a, char *cd, int m, int c[2]);
void				split_round_median_a(t_stack *a, t_stack *b,
int med, char *cmnds);

void				sort_a(t_stack *a, int count, char *tmp);
long				special_median_b(t_stack *b);
int					deal_lower_b(t_stack *b,
char *cd, int m, int c[2]);

void				split_round_median_b
(t_stack *a, t_stack *b, int med, char *cmnds);

void				sort_b(t_stack *b, int count, char *tmp);
int					split_a(t_stack *a, t_stack *b, t_list **cmnd);
void				b_to_a(t_stack *a, t_stack *b, t_list **cmnd);
int					sorted(t_stack *a);
t_list				*solver(t_stack *a, t_stack *b);
int					get_count(t_stack *s);
int					get_true_median(t_stack *a);
void				error_exit(void);

void				rev_rotater(char *line, t_stack *a, t_stack *b);
void				swapper(char *line, t_stack *a, t_stack *b);
void				rotater(char *line, t_stack *a, t_stack *b);

#endif
