#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#define NO_MED 2147483648

#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"

typedef struct		s_pslst
{
	int				n;
	struct	s_pslst *nxt;
	struct	s_pslst *prv;
}					t_pslst;
/*
typedef struct		s_index
{
	t_pslst			*p;
	struct	s_index	*nxt;
	struct	s_index	*prv;
}					t_index;
*/
typedef struct		s_stack
{
	t_pslst			*head;
	t_pslst			*end;
	t_pslst			**p;
	int				top;
	int				ac;
}					t_stack;

void		 		push(t_pslst **from, t_pslst **to, t_pslst **to_end);
void				swap(t_pslst **head);
void				rotate(t_pslst **head, t_pslst **end);
void				rev_rotate(t_pslst **head, t_pslst **end);
void				build_stack(t_stack *a, t_stack *b, char **av, int ac);
void				lst_addend_fast(int n, t_pslst **back);
void				print_stacks(t_pslst *a, t_pslst *b, char *line);

#endif
