#include "ft_printf.h"

char    *ft_free_strjoin_rev(char const *src, char *del)
{
	char	*tmp;

	if (!(tmp = ft_strjoin(src, del)))
		return (NULL);
	free(del);
	del = NULL;
	return (tmp);
}