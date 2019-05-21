#include "ft_printf.h"

void    ft_init_int_arg(t_pf_obj *ob, long *nbr)
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