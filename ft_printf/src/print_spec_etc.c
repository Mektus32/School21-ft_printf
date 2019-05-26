#include "ft_printf.h"
#define TYPE ob->type ==
#define WGH ob->flag.weight
#define OUT ob->out

void	print_unsint(t_ob *ob, char c)
{
	long	nbr;

	ob->flag.space = 0;
	ob->flag.plus = 0;
	init_int_arg(ob, &nbr);
	if (nbr == LLONG_MIN || nbr == LONG_MIN)
		OUT = ft_strdup("-9223372036854775808");
	else if (c == 'D' || c == 'U' || ob->type == type_z || ob->type == type_l
		|| ob->type == type_t || ob->type == type_j || ob->type == type_ll)
		OUT = ft_ultoa((unsigned long)nbr);
	else if (ob->type == type_h)
		OUT = ft_ultoa((unsigned short)nbr);
	else if (ob->type == type_hh)
		OUT = ft_ultoa((unsigned char)nbr);
	else if (ob->type == type_notype && c != 'U')
		OUT = ft_ultoa((unsigned int)nbr);
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
		OUT = ft_ultoa_base(tmp, 8);
	else
		OUT = ft_ultoa_base(tmp, 16);
	ob->flag.minus ? ob->flag.zero = 0 : 0;
	print_xox(ob, c, nbr);
}

void	print_pointer(t_ob *ob)
{
	long	nbr;

	init_int_arg(ob, &nbr);
	OUT = ft_ltoa_base(nbr, 16);
	OUT = ft_free_strjoin_duo(ft_strdup("0X"), OUT);
	if (WGH > ft_strlen(OUT))
		OUT = ft_free_strjoin_duo(ft_memset(ft_strnew(WGH - ft_strlen(OUT)), 
			' ', WGH - ft_strlen(OUT)), OUT);
		OUT = ft_tolower(OUT);
	ob->i++;
	ob->ret += write(ob->fd, OUT, ft_strlen(OUT));
	free(OUT);
}