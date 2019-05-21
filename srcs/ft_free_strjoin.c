#include "ft_printf.h"

char    *ft_free_strjoin(char *del, char const *src)
{
	char	*tmp;

	if (!(tmp = ft_strjoin(del, src)))
		return (NULL);
	free(del);
	del = NULL;
	return (tmp);
}