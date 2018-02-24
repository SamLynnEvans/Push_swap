/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 10:37:32 by slynn-ev          #+#    #+#             */
/*   Updated: 2017/12/15 13:53:04 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memdup(void const *content, size_t n)
{
	unsigned long	i;
	char			*b;
	char			*a;

	a = (char *)content;
	if (!(b = (char *)malloc(sizeof(char) * n)))
		return (NULL);
	i = 0;
	while (i < n)
	{
		b[i] = a[i];
		i++;
	}
	return ((void *)b);
}

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list *tmp;

	if (!(tmp = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		tmp->content = NULL;
		tmp->content_size = 0;
		tmp->next = NULL;
		return (tmp);
	}
	tmp->content = ft_memdup(content, content_size);
	tmp->content_size = content_size;
	tmp->next = NULL;
	return (tmp);
}
