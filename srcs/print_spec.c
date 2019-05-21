#include "ft_printf.h"

void    ft_print_percent(t_pf_obj *ob)
{
    if (ob->flag.f_minus)
    {
        ob->ret += write(ob->fd, "%", 1);
        while (--ob->flag.w_nbr > 0)
            ob->ret += write(ob->fd, " ", 1);
    }
    else
    {
        while (--ob->flag.w_nbr > 0)
            ob->ret += (ob->flag.f_zero) ?
            write(ob->fd, "0", 1) : write(ob->fd, " ", 1);
            ob->ret += write(ob->fd, "%", 1);
    }
    ob->i++;
}

void       ft_print_int(t_pf_obj *ob)
{
    long	i;
	long	nbr;

	ft_init_int_arg(ob, &nbr);
	if ((i = (long long)nbr) < 0)
	{
		ob->flag.negativ = 1;
		i *= -1;
	}//число остается отрицательным!
	ob->flag.f_minus == 1 ? ob->flag.f_zero = 0 : 0;
	ob->flag.f_plus == 1 ? ob->flag.f_space = 0 : 0;
	ob->flag.f_plus == 1 ? ob->flag.negativ = 1 : 0;
	ob->flag.a_nbr >= 0 ? ob->flag.f_zero = 0 : 0;
	if (nbr == LLONG_MIN || nbr == LONG_MIN)
		ob->out = ft_strdup("-9223372036854775808");
	else if (ob->type == pf_hh)
		ob->out = ft_itoa((char)i);
	else if (ob->type == pf_h)
		ob->out = ft_itoa((short)i);
	else if (ob->type == pf_notype)
		ob->out = ft_itoa((int)i);
	else if (ob->type == pf_j || ob->type == pf_t ||
			ob->type == pf_l || ob->type == pf_ll)
		ob->out = ft_ltoa((long)i);
	ft_print_digit(ob);
}