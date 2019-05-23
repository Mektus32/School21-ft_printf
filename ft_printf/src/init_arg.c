#include "ft_printf.h"

void	init_int_arg(t_ob *ob, long *nbr)
{
	if (ob->dollar.dollar)
	{
		va_copy(ob->ap[0], ob->ap[1]);
		while (--ob->dollar.num >= 0)
			*nbr = va_arg(ob->ap[0], long);
		return ;
	}
	*nbr = va_arg(ob->ap[0], long);
}

void	init_str_arg(t_ob *ob)
{
	if (ob->dollar.dollar)
	{
		va_copy(ob->ap[0], ob->ap[1]);
		while (--ob->dollar.num >= 0)
			ob->out = va_arg(ob->ap[0], char *);
		return ;
	}
		ob->out = va_arg(ob->ap[0], char *);
}

void	init_char_arg(t_ob *ob, int *c)
{
	if (ob->dollar.dollar)
	{
		va_copy(ob->ap[0], ob->ap[1]);
		while (--ob->dollar.num >= 0)
			c = va_arg(ob->ap[0], int);
		return ;
	}
	c = va_arg(ob->ap[0], int);
}