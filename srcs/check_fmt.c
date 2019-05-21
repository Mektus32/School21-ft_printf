#include "ft_printf.h"

void	ft_get_a_nbr(const char *restrict fmt, t_pf_obj *ob)
{
	if (fmt[ob->i + 1] >= '0' && fmt[ob->i + 1] <= '9')
	{
		ob->i++;
		ob->flag.a_nbr = ft_atoi(&(fmt[ob->i + 1]));
		while (fmt[ob->i] >= '0' && fmt[ob->i] <= '9')
			ob->i++;	
	}
	else if (ob->i + 1 == '*')
	{
		ob->flag.a_nbr = va_arg(ob->ap[0], int);
		ob->i += 2;
	}

}

void	ft_get_type(const char *restrict fmt, t_pf_obj *ob)
{
	if (fmt[ob->i] == 'h' && fmt[ob->i] != 'h')
		ob->type = pf_h;
	else if (fmt[ob->i] == 'h' && fmt[ob->i] == 'h')
	{
		ob->type = pf_hh;
		ob->i++;
	}
	else if (fmt[ob->i] == 'l' && fmt[ob->i] != 'l')
		ob->type = pf_l;
	else if (fmt[ob->i] == 'l' && fmt[ob->i] == 'l')
	{
		ob->type = pf_ll;
		ob->i++;
	}
	else if (fmt[ob->i] == 'j')
		ob->type = pf_j;
	else if (fmt[ob->i] == 'z')
		ob->type = pf_j;
	else if (fmt[ob->i] == 't')
		ob->type = pf_t;
	else if (fmt[ob->i] == 'L')
		ob->type = pf_L;
}

void	ft_get_w_nbr(t_pf_obj *ob)
{
	ob->flag.w_nbr = va_arg(ob->ap[0], int);
	if (ob->flag.w_nbr < 0)
	{
		ob->flag.w_nbr *= -1;
		ob->flag.f_minus = 1;
	}
}

void	ft_get_flag(const char *restrict fmt, t_pf_obj *ob)
{
	while (ft_strchr(PF_FLAG, fmt[ob->i]))
	{
		fmt[ob->i] == '-' ? ob->flag.f_minus = 1 : 0;
		fmt[ob->i] == '+' ? ob->flag.f_plus = 1 : 0;
		fmt[ob->i] == ' ' ? ob->flag.f_space = 1 : 0;
		fmt[ob->i] == '0' ? ob->flag.f_zero = 1 : 0;
		fmt[ob->i] == '#' ? ob->flag.f_hash = 1 : 0;
		fmt[ob->i] == '*' ? ft_get_w_nbr(ob) : 0;
		fmt[ob->i] >= 'L' && fmt[ob->i] <= 'z' ? ft_get_type(fmt, ob) : 0;
		if (fmt[ob->i] == '.')
			ft_get_a_nbr(fmt, ob);
		if (fmt[ob->i] >= '0' && fmt[ob->i] <= '9')
		{
			ob->flag.w_nbr = ft_atoi(&(fmt[ob->i]));
			while (fmt[ob->i] >= '0' && fmt[ob->i] <= '9')
				ob->i++;
		}
		else
			ob->i++;
	}
}

void	ft_get_dollar(const char *restrict fmt, t_pf_obj *ob)
{
	int		i;
	int		tmp;

	ob->type = pf_notype;
	ob->dollar.dollar = 0;
	i = 0;
	ft_init_flags(&ob->flag);
	if (fmt[ob->i] >= '0' && fmt[ob->i] <= '9')
	{
		tmp = ft_atoi(&(fmt[ob->i]));
		while (fmt[ob->i + i] >= '0' && fmt[ob->i + i] <= '9')
			i++;
		if (fmt[ob->i + i] == '$')
		{
			ob->dollar.dollar = 1;
			ob->dollar.num = tmp;
			ob->i += i + 1;
		}
	}
}