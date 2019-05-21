#include "ft_printf.h"

char    *ft_free_strjoin_duo(char *new, char *del)
{
	char	*tmp;

	if (!(tmp = ft_strjoin(new, del)))
		return (NULL);
	free(del);
    free(new);
    new = NULL;
	del = NULL;
	return (tmp);
}