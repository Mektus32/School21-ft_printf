#include "ft_printf.h"
#define PREC (ob->flag.prec)
#define MNS (ob->flag.minus)
#define WGH (ob->flag.weight)
#define OUT (ob->out)

void    print_xox(t_ob *ob, char c, long nbr)
{
	if (ob->flag.dot && !nbr)
	{
		if ((c == 'o' || c == 'O') && ob->flag.hash)
			c += 0;
		else
		{
			free(ob->out);
			ob->out = ft_strdup("");
		}
	}
	if (ob->flag.hash)
		WGH += (c == 'x' || c == 'X') ? -2 : -1;
	if (ob->flag.dot && PREC > ft_strlen(OUT))
		OUT = ft_free_strjoin_duo(ft_memset(ft_strnew(PREC - ft_strlen(OUT)), 
		'0', PREC - ft_strlen(OUT)), OUT);
	if (ob->flag.zero && WGH > ft_strlen(OUT))
		OUT = ft_free_strjoin_duo(ft_memset(ft_strnew(WGH - ft_strlen(OUT)), 
		'0', WGH - ft_strlen(OUT)), OUT);
	if (MNS && WGH > ft_strlen(OUT))
		OUT = ft_free_strjoin_duo(OUT, ft_memset(ft_strnew(WGH - 
		ft_strlen(OUT)), ' ', WGH - ft_strlen(OUT)));
	if (ob->flag.hash && nbr)
	{
		OUT = ft_free_strjoin_duo(c == 'x' || c == 'X' ? ft_strdup("0X") : 
			ft_strdup("0"), OUT);
		WGH += (c == 'x' || c == 'X') ? 2 : 1;
	}
	if (WGH > ft_strlen(OUT))
		OUT = ft_free_strjoin_duo(ft_memset(ft_strnew(WGH - ft_strlen(OUT)), 
		' ', WGH - ft_strlen(OUT)), OUT);
	if (c == 'x' || c == 'o')
		OUT = ft_tolower(OUT);
	ob->i++;
	ob->ret += write(ob->fd, OUT, ft_strlen(OUT));
	free(ob->out);
}