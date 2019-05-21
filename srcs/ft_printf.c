#include "ft_printf.h"

void    ft_init_flags(t_pf_flag *flag)
{
    flag->f_minus = 0;
	flag->f_plus = 0;
	flag->f_space = 0;
	flag->f_hash = 0;
	flag->f_zero = 0;
	flag->w_nbr = -1;
	flag->a_nbr = -1;
    flag->negativ = 1;
}

void	ft_check_arg(const char *restrict fmt, t_pf_obj *ob)
{
	ob->i++;
	ft_get_dollar(fmt, ob);
	ft_get_flag(fmt, ob);
	ft_get_spec(fmt, ob);
}

int     ft_printf(const char *restrict fmt, ...)
{
    t_pf_obj    ob;

    ft_bzero(&ob, sizeof(ob));
    ob.fd = 1;
    va_start(ob.ap[0], fmt);
    va_copy(ob.ap[1], ob.ap[0]);
    while (fmt[ob.i])
    {
        // if (fmt[ob.i] == '{')
        //     ft_change_style(fmt, &ob);
        if (fmt[ob.i] == '%')
            ft_check_arg(fmt, &ob);
        else
            ob.ret += write(ob.fd, &fmt[ob.i++], 1);
    }
    va_end(ob.ap[0]);
	return (ob.ret);
}