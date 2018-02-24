/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 22:20:44 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/01/22 22:20:47 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_flags(char *str, int *skip)
{
	int		i;
	char	*flags;

	i = 0;
	while ((FC_ONE || FC_TWO || FC_THREE || NUM) && str[i])
		i++;
	*skip = i + 1;
	flags = malloc(sizeof(char) * (i + 1));
	i = 0;
	while ((FC_ONE || FC_TWO || FC_THREE || NUM) && str[i])
	{
		flags[i] = str[i];
		i++;
	}
	flags[i] = '\0';
	return (flags);
}

void	get_modval(va_list ap, char *flags, int *mod, int *mod2)
{
	*mod = 0;
	*mod2 = 0;
	while (*flags != '.' && *flags)
	{
		*mod = (*flags == '*') ? va_arg(ap, int) : *mod;
		if (*flags >= '0' && *flags <= '9')
		{
			*mod = ft_atoi(flags);
			while (*(flags + 1) <= '9' && *(flags + 1) >= '0')
				flags++;
		}
		flags++;
	}
	while (*flags)
	{
		*mod2 = (*flags == '*') ? va_arg(ap, int) : *mod2;
		if (*flags <= '9' && *flags >= '0')
		{
			*mod2 = ft_atoi(flags);
			while (*(flags + 1) <= '9' && *(flags + 1) >= '0')
				flags++;
		}
		flags++;
	}
}

int		print_chars(va_list ap, char *flags, char c, int mod[2])
{
	if (ft_strrchr(flags, 'l') && (c == 'c' || c == 's'))
		c = c - 32;
	if (c == '%')
		return (print_char('%', flags, mod));
	else if (c == 'S')
		return (ft_putstr_unicode(va_arg(ap, int *), flags, mod));
	else if (c == 'C')
		return (ft_putchar_unicode(va_arg(ap, int), flags, mod));
	else if (c == 's')
		return (print_string(va_arg(ap, char *), flags, mod));
	else if (c == 'c')
		return (print_char((char)(va_arg(ap, int)), flags, mod));
	else if (c == 'p')
		return (print_pointer(va_arg(ap, long long *), flags, mod));
	else if (c == 'r')
		return (print_file(va_arg(ap, int), flags, mod));
	else
		return (print_char(c, flags, mod));
	return (0);
}

int		print_variable(va_list ap, int *skip, char *str)
{
	char	*flags;
	int		mod[2];
	int		count;

	count = 0;
	flags = get_flags(str + 1, skip);
	get_modval(ap, flags, &mod[0], &mod[1]);
	if (mod[0] < 0)
		flags = ft_strjoin_free(flags, "-");
	mod[0] = (mod[0] < 0) ? mod[0] * -1 : mod[0];
	if (*(str + *skip) == '\0')
		*skip = 0;
	else if (ft_strrchr("dDuUixXoOb", *(str + *skip)))
		count += print_number(ap, &flags, str + *skip, mod);
	else
		count += print_chars(ap, flags, *(str + *skip), mod);
	free(flags);
	return (count);
}

int		ft_printf(char *str, ...)
{
	va_list	ap;
	int		skip;
	int		count;

	count = 0;
	va_start(ap, str);
	while (*str)
	{
		skip = 0;
		if (*str == '{')
			count += print_colour(str, &skip);
		else if (*str == '%')
			count += print_variable(ap, &skip, str);
		else
		{
			count++;
			ft_putchar(*str);
		}
		str += skip;
		str++;
	}
	va_end(ap);
	return (count);
}
