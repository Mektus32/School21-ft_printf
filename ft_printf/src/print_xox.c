#include "ft_printf.h"

void    print_xox(t_ob *ob, char c, long nbr)
{
	char	*tmp;

	if (ob->flag.dot && !nbr)
	{
		if ((c == 'o' || c == 'O') && ob->flag.hash)
			c += 0;
		else
		{
			free(ob->out);
			ob->out = ft_strdup("");
		}
	}
	if (ob->flag.hash)
	{
		c == 'x' || c == 'X' ? 
	}
	if (c == 'x' || c == 'o')
		ob->out = ft_tolower(ob->out);
	ob->i++;
	ob->ret += write(ob->fd, ob->out, ft_strlen(ob->out));
	free(ob->out);
}