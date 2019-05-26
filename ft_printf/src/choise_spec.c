#include "ft_printf.h"

static	void	choise_specs_etc(const char *restrict fmt, t_ob *ob)
{
	if (ft_strchr(OX, fmt[ob->i]))
		print_base(ob, fmt[ob->i]);
}

void	choise_specs(const char *restrict fmt, t_ob *ob)
{
	if (fmt[ob->i] == '%')
		print_percent(ob);
	else if ((fmt[ob->i] == 's' || fmt[ob->i] == 'c') && 
		ob->type != type_l)
		fmt[ob->i] == 'c' ? print_char(ob) : print_str(ob);
	else if (((fmt[ob->i] == 's' || fmt[ob->i] == 'c') && ob->type == type_l)
		|| fmt[ob->i] == 'S' || fmt[ob->i] == 'C')
		fmt[ob->i] == 'c' ? print_char(ob) : print_str(ob);
	else if ((fmt[ob->i] == 'd' || fmt[ob->i] == 'i') && ob->type != type_z)
		print_int(ob);
	else if (fmt[ob->i] == 'u' || fmt[ob->i] == 'U' || fmt[ob->i] == 'D' ||
		((fmt[ob->i] == 'd' || fmt[ob->i] == 'i') && ob->type == type_z))
		print_unsint(ob, fmt[ob->i]);
	else if (ft_strchr(PRECS, fmt[ob->i]))
		printf("c = %c", fmt[ob->i]);
	else
		choise_specs_etc(fmt, ob);
}