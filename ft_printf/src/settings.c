#include "ft_printf.h"

static  void	set_options(const char *restrict fmt, t_ob *ob)
{
	if (!ft_strncmp(fmt + ob->i, "{SET:BO}", 8))
		ob->ret += write(1, "\x1B[1m", 4);
	else if (!ft_strncmp(fmt + ob->i, "{SET:FT}", 8))
		ob->ret += write(1, "\x1B[2m", 4);
	else if (!ft_strncmp(fmt + ob->i, "{SET:IT}", 8))
		ob->ret += write(1, "\x1B[3m", 4);
	else if (!ft_strncmp(fmt + ob->i, "{SET:UL}", 8))
		ob->ret += write(1, "\x1B[4m", 4);
	else if (!ft_strncmp(fmt + ob->i, "{SET:BL}", 8))
		ob->ret += write(1, "\x1B[5m", 4);
	else if (!ft_strncmp(fmt + ob->i, "{SET:RE}", 8))
		ob->ret += write(1, "\x1B[7m", 4);
	else if (!ft_strncmp(fmt + ob->i, "{SET:CC}", 8))
		ob->ret += write(1, "\x1B[8m", 4);
	else if (!ft_strncmp(fmt + ob->i, "{SET:RV}", 8))
		ob->ret += write(1, "\x1B[28m", 5);
	else
		return ;
	ob->i += 8;
}

static  void	set_background(const char *restrict fmt, t_ob *ob)
{
	if (!ft_strncmp(fmt + ob->i, "{BGC:BLK}", 9))
		ob->ret += write(1, "\x1B[40m", 5);
	else if (!ft_strncmp(fmt + ob->i, "{BGC:RED}", 9))
		ob->ret += write(1, "\x1B[41m", 5);
	else if (!ft_strncmp(fmt + ob->i, "{BGC:GRN}", 9))
		ob->ret += write(1, "\x1B[42m", 5);
	else if (!ft_strncmp(fmt + ob->i, "{BGC:YEL}", 9))
		ob->ret += write(1, "\x1B[43m", 5);
	else if (!ft_strncmp(fmt + ob->i, "{BGC:BLU}", 9))
		ob->ret += write(1, "\x1B[44m", 5);
	else if (!ft_strncmp(fmt + ob->i, "{BGC:MGT}", 9))
		ob->ret += write(1, "\x1B[45m", 5);
	else if (!ft_strncmp(fmt + ob->i, "{BGC:CYN}", 9))
		ob->ret += write(1, "\x1B[46m", 5);
	else if (!ft_strncmp(fmt + ob->i, "{BGC:WHT}", 9))
		ob->ret += write(1, "\x1B[47m", 5);
	else
		return ;
	ob->i += 9;
}

static  void	set_color(const char *restrict fmt, t_ob *ob)
{
	if (!ft_strncmp(fmt + ob->i, "{BLK}", 5))
		ob->ret += write(1, "\x1B[30m", 5);
	else if (!ft_strncmp(fmt + ob->i, "{RED}", 5))
		ob->ret += write(1, "\x1B[31m", 5);
	else if (!ft_strncmp(fmt + ob->i, "{GRN}", 5))
		ob->ret += write(1, "\x1B[32m", 5);
	else if (!ft_strncmp(fmt + ob->i, "{YEL}", 5))
		ob->ret += write(1, "\x1B[33m", 5);
	else if (!ft_strncmp(fmt + ob->i, "{BLU}", 5))
		ob->ret += write(1, "\x1B[34m", 5);
	else if (!ft_strncmp(fmt + ob->i, "{MGT}", 5))
		ob->ret += write(1, "\x1B[35m", 5);
	else if (!ft_strncmp(fmt + ob->i, "{CYN}", 5))
		ob->ret += write(1, "\x1B[36m", 5);
	else if (!ft_strncmp(fmt + ob->i, "{WHT}", 5))
		ob->ret += write(1, "\x1B[37m", 5);
	else
		return ;
	ob->i += 5;
}

void	check_settings(const char *restrict fmt, t_ob *ob)
{
	int	 tmp;

	tmp = ob->i;
	if (ft_strncmp(fmt[tmp], "{off}", 5))
	{
		ob->ret += write(1, "\x1B[0m", 4);
		ob->i += 5;
	}
	else if (ft_strncmp(fmt[tmp], "{set:", 5))
		set_options(fmt, ob);
	else if (ft_strncmp(fmt[tmp], "{bgc:", 5))
		set_background(fmt, ob);
	else
		set_color(fmt, ob);
	if (tmp == ob->i)
		ob->i += write(1, &fmt[ob->i++], 1);
}