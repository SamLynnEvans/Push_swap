/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 12:43:22 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/01/22 22:18:13 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define FC_ONE str[i] == '.' || str[i] == '#' || str[i] == '+' || str[i] == '-'
# define FC_TWO str[i] == ' ' || str[i] == '0' || str[i] == 'j' || str[i] == 'l'
# define FC_THREE str[i] == 'z' || str[i] == 'h' || str[i] == '*'
# define NUM (str[i] <= '9' && str[i] >= '0')
# define DECIMAL 10
# define HEXA 16
# define HEXA_UPPER 17
# define OCTAL 8
# define OCTAL_UPPER 9
# define BINARY 2
# define ZERO 1
# define SPACE 2
# define MINUS 4
# define NEG 4
# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN    "\x1b[36m"
# define RESET   "\x1b[0m"

# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"
# include "get_next_line.h"

typedef struct	s_print_colour
{
	char *colour;
	char *print_c;
}				t_print_colour;

int				print_spaces(int spaces);
int				print_file(int fd, char *flags, int mod[2]);
int				dot_precision(int base, int num, int mod[2], char *flags);
int				fs(char space_type, int count, int **mod);
int				print_zeroes(int zeroes);
int				pf_unsigned(unsigned long long n, char *fg, int mod[2], int dt);
int				dot_spaces(int num_l, int mod[2], int precision, int base);
char			get_int_size(char *flags);
void			rc_putbase(unsigned long long num, int base);
char			read_count(int count[4]);
int				pf_dot_signed(long long num, char *flags, int mod[2], int base);
char			bit_space_type(char *flags);
int				get_precision(char *flags, int base, long long num);
int				pf_signed(long long n, char *flags, int mod, int base);
int				print_colour(char *str, int *skip);
int				dt_print_str(char *str, char *flags, int mod[2]);
int				ft_putstr_unicode(int *str, char *flags, int mod[2]);
int				ft_putchar_unicode(int c, char *flags, int mod[2]);
int				ft_printf(char *str, ...);
int				print_precision(int base, int caps);
int				print_char(char c, char *flags, int mod[2]);
int				print_number(va_list ap, char **flags, char *c, int mod[2]);
int				print_pointer(long long *p, char *flags, int mod[2]);
int				print_string(char *str, char *flags, int mod[2]);
void			ft_pf_percent(char *str, char *flags);
void			ft_pf_string(char *str, char *flags);
void			ft_putbase(long long num, int base, int filler);
void			get_mod_values(char *flags, int *mod, int *mod2);

#endif
