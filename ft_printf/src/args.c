#include "ft_printf.h"

static	void	ft_check_dollar(const char *restrict fmt, t_ob *ob)
{
	int		tmp;

	tmp = ob->i;
	if (ISNUM(fmt[tmp]))
	{
		ob->dollar.num = ft_atoi(fmt[ob->i])
	}
}

static	void	ft_get_weight(t_ob *ob)
{
	ob->flag.weight = va_arg(ob->ap[0], int);
	if (ob->flag.weight < 0)
	{
		ob->flag.weight = -ob->flag.weight;
		ob->flag.minus = 1;
	}
}

void	check_args(const char *restrict fmt, t_ob *ob)
{
	ft_check_dollar(fmt, ob);
	while (ft_strchr(FLAGS, fmt[ob->i]))
	{
		fmt[ob->i] == '-' ? ob->flag.minus = 1 : 0;
		fmt[ob->i] == '+' ? ob->flag.plus = 1 : 0;
		fmt[ob->i] == ' ' ? ob->flag.space = 1 : 0;
		fmt[ob->i] == '#' ? ob->flag.hash = 1 : 0;
		fmt[ob->i] == '0' ? ob->flag.zero = 1 : 0;
		fmt[ob->i] == 39 ? ob->flag.quote = 1 : 0;
		fmt[ob->i] == '*' ? ft_get_weight(ob) : 0;
		
	}
}