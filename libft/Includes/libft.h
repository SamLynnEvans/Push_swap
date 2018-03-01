/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 11:52:39 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/02/28 13:44:16 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define DECIMAL 10
# define HEXA 16
# define HEXA_UPPER 17
# define OCTAL 8
# define OCTAL_UPPER 9
# define BINARY 2
# define HEX_CHAR1 (*str >= 'a' && *str <= 'f') || (*str >= 'A' && *str <= 'F')
# define HEX_PREC *str == 'x' || *str == 'X'

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					ft_abs(int num);
char				**ft_add_charpointer(char **arr, char *content, int count);
void				ft_put_inta(int *arr, int len);
int					ft_atoi_base(char *str, int base);
int					ft_numlen(long long num, int base, size_t size);
int					ft_unumlen(unsigned long long num);
void				ft_unicode_putchar(int c);
int					ft_power(int num, int power);
char				*ft_lsttstr_del(t_list **list);
void				ft_putstrn(char *str, int n);
t_list				*ft_lstnew_ptr(void const *content, size_t content_size);
char				*ft_strcat(char *dst, const char *src);
char				*ft_strjoin_free(char const *s1, char const *s2);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_strdebug(char *str, char *name);
void				ft_print_list(t_list *list);
char				*ft_strcpy(char *dst, const char *src);
void				ft_strdebug(char *s, char *name);
void				ft_intdebug(int a, char *name);
char				*ft_strncat(char *dst, const char *src, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(const char *s);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *haystack,
const char *needle, size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
int					ft_atoi(const char *s);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strequ(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strnequ(char const *s1,
char const *s2, size_t n);
size_t				ft_strlcat(char *dst,
const char *src, size_t size);
t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				*ft_memchr(const void *s, int c, size_t n);
void				ft_bzero(void *b, size_t len);
void				ft_memdel(void **ap);
void				ft_putnbr(int c);
void				ft_putnbr_fd(int c, int fd);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dst,
const void *src, int c, size_t n);
void				*ft_memcpy(void *dst,
const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstaddend(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_strclr(char *s);
void				ft_strdel(char **as);
void				ft_striter(char *s, void(*f)(char *));
void				ft_striteri(char *s, void(*f)(unsigned int, char *));
int					*str_to_intdata(char *str, int size);

#endif
