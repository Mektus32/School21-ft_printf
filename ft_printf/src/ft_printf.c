#include "ft_printf.h"

static  void	init_flag(t_flag *flag)
{
	flag->minus = 0;
	flag->plus = 0;
	flag->space = 0;
	flag->hash = 0;
	flag->zero = 0;
	flag->quote = 0;
	flag->weight = -1;
	flag->plus = -1;
}

int	 ft_printf(const char *restrict fmt, ...)
{
	t_ob	ob;

	init_flag(&(ob.flag));
	ob.type = type_notype;
	ob.ret = 0;
	ob.i = 0;
    ob.dollar.dollar = 0;
	va_start(ob.ap[0], fmt);
	va_copy(ob.ap[1], ob.ap[0]);
	while (fmt[ob.i])
	{
		if (fmt[ob.i] == '{')
			check_settings(fmt, &ob);
		else if (fmt[ob.i] == '%')
			check_args(fmt, ob);
	}
	return (ob.ret);
}