#include "ft_printf.h"
#define TYPE ob->type ==

void	print_unsint(t_ob *ob, char c)
{
	long	nbr;

	ob->flag.space = 0;
	ob->flag.plus = 0;
	init_int_arg(ob, &nbr);
	if (nbr == LLONG_MIN || nbr == LONG_MIN)
		ob->out = ft_strdup("-9223372036854775808");
	else if (c == 'D' || c == 'U' || ob->type == type_z || ob->type == type_l
		|| ob->type == type_t || ob->type == type_j || ob->type == type_ll)
		ob->out = ft_ultoa((unsigned long)nbr);
	else if (ob->type == type_h)
		ob->out = ft_ultoa((unsigned short)nbr);
	else if (ob->type == type_hh)
		ob->out = ft_ultoa((unsigned char)nbr);
	else if (ob->type == type_notype && c != 'U')
		ob->out = ft_ultoa((unsigned int)nbr);
	print_digit(ob);
}

void	print_base(t_ob *ob, char c)
{
	long			nbr;
	unsigned long	tmp;

	tmp = 0;
	init_int_arg(ob, &nbr);
	if (c == 'O' || TYPE type_z || TYPE type_t || TYPE type_j
		|| TYPE type_l || TYPE type_ll)
		tmp = (unsigned long)nbr;
	else if (TYPE type_h)
		tmp = (unsigned short)nbr;
	else if (TYPE type_notype)
		tmp = (unsigned int)nbr;
	else if (TYPE type_hh)
		tmp = (unsigned char)nbr;
	if (c == 'o' || c == 'O')
		ob->out = ft_ultoa_base(tmp, 8);
	else
		ob->out = ft_ultoa_base(tmp, 16);
	ob->flag.minus ? ob->flag.zero = 0 : 0;
	print_xox(ob, c, nbr);
}