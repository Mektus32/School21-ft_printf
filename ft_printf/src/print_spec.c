#include "ft_printf.h"
#define PREC (ob->flag.prec)
#define MNS (ob->flag.minus)
#define WGH (ob->flag.weight)
#define OUT (ob->out)

void    print_percent(t_ob *ob)
{
    if (ob->flag.minus)
    {
        ob->ret += write(ob->fd, "%", 1);
        while (--ob->flag.weight > 0)
            ob->ret += write(ob->fd, " ", 1);
    }
    else
    {
        while (--ob->flag.weight > 0)
            ob->ret += (ob->flag.zero) ?
            write(ob->fd, "0", 1) : write(ob->fd, " ", 1);
            ob->ret += write(ob->fd, "%", 1);
    }
    ob->i++;
}

void    print_str(t_ob *ob)
{
	char	*tmp;
    
	init_str_arg(ob, &tmp);
	OUT = tmp == NULL ? ft_strdup("(null)") : ft_strdup(tmp);
    if (PREC < ft_strlen(OUT) && ob->flag.dot)
		OUT = ft_free_strncpy(ft_strnew(PREC < 0 ? 0 : PREC), OUT,
			PREC < 0 ? 0 : PREC);
	if (MNS && WGH > ft_strlen(OUT))
		OUT = ft_free_strjoin_duo(OUT, ft_memset(ft_strnew(WGH - 
			ft_strlen(OUT)), ' ', WGH - ft_strlen(OUT)));
	if (!MNS && WGH > ft_strlen(OUT))
		OUT = ft_free_strjoin_duo(ft_memset(ft_strnew(WGH - 
			ft_strlen(OUT)), ' ', WGH - ft_strlen(OUT)), OUT);
	ob->i++;
	ob->ret += write(ob->fd, OUT, ft_strlen(OUT));
	free(OUT);
}

void	print_char(t_ob *ob)
{
	int		c;

	init_char_arg(ob, &c);
	ob->i++;
	if (c == 0)
	{
		while (--WGH > 0)
			ob->ret += write(ob->fd, " ", 1);
		ob->ret += write(ob->fd, "\0", 1);
		return ;
	}
	OUT = ft_memset(ft_strnew(1), c, 1);
	if (MNS && WGH > ft_strlen(OUT))
		OUT = ft_free_strjoin_duo(OUT, ft_memset(ft_strnew(WGH - 
			ft_strlen(OUT)), ' ', WGH - ft_strlen(OUT)));
	if (WGH > ft_strlen(OUT))
		OUT = ft_free_strjoin_duo(ft_memset(ft_strnew(WGH - ft_strlen(OUT)),
			' ', WGH - ft_strlen(OUT)), OUT);
	ob->ret += write(ob->fd, 	OUT, ft_strlen(OUT));
	free(OUT);
}