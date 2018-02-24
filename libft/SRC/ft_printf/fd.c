/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 21:30:20 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/01/22 22:15:31 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_filecontent(int fd)
{
	char	*file_cont;
	char	*line;
	int		first;
	int		ret;

	first = 1;
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		if (first)
		{
			file_cont = ft_strdup(line);
			first = 0;
			continue ;
		}
		file_cont = ft_strjoin_free(file_cont, line);
		free(line);
	}
	if (ret == -1)
		file_cont = ft_strdup("FILE ERROR");
	return (file_cont);
}

int		print_file(int fd, char *flags, int mod[2])
{
	char	*file_cont;
	int		ret;

	file_cont = get_filecontent(fd);
	ret = print_string(file_cont, flags, mod);
	free(file_cont);
	return (ret);
}
