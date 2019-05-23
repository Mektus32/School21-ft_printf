#include "ft_printf.h"

void	choise_args(const char *restrict fmt, t_ob *ob)
{
	if (fmt[ob->i] == '%')
		print_percent(ob);
	else if ((fmt[ob->i] == 's' || fmt[ob->i] == 'c') && 
		ob->type != type_l)
		print_char(ob, fmt[ob->i]);
	else if (((fmt[ob->i] == 's' || fmt[ob->i] == 'c') && ob->type == type_l) 
		|| fmt[ob->i] == 'S' || fmt[ob->i] == 'C')
		print_wchar(ob, fmt[ob->i]);
}