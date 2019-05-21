#include "ft_printf.h"

void	ft_get_spec(const char *restrict fmt, t_pf_obj *ob)
{
	if (fmt[ob->i] == '%')
		ft_print_percent(ob);
	else if ((fmt[ob->i] == 'd' || fmt[ob->i] == 'i') && ob->type != pf_z)
		ft_print_int(ob);
}