#include "libft.h"

char	**ft_add_charpointer(char **array, char *content, int count)
{
	char	**ret;
	int		i;

	if (content == NULL || count < 0)
		return (NULL);
	ret = malloc(sizeof(char *) * (count + 1));
	i = -1;
	while (++i < count)
		ret[i] = array[i];
	ret[i] = content;
	if (count != 0)
		free(array);
	return (ret);
}

