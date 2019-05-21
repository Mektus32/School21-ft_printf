#include "ft_printf.h"
#define AN ob->flag.a_nbr
#define WN ob->flag.a_nbr
#define NEG (ob->flag.negativ)
#define LENA (AN - ft_strlen(ob->out))
#define LENW (WN - ft_strlen(ob->out))

void    ft_print_digit(t_pf_obj *ob)
{
	if (LENA > 0)
		ob->out = ft_free_strjoin_rev(ft_memset(ft_strnew(LENA), '0', LENA),
		 ob->out);
	if (ob->flag.f_space && !NEG)
		ob->out = ft_free_strjoin_rev(" ", ob->out);
	if (ob->flag.f_zero && LENW > 0)
		ob->out = ft_free_strjoin_duo(ft_memset(ft_strnew(NEG ? LENW - 1 
			: LENW), '0', NEG ? LENW - 1 : LENW), ob->out);
	if (ob->flag.f_minus && (NEG ? LENW - 1 > 0 : LENW > 0))
		ob->out = ft_free_strjoin_duo(ft_memset(ft_strnew(NEG ? LENW - 1 
			: LENW), ' ', NEG ? LENW - 1 : LENW), ob->out);
	if (NEG && ob->flag.f_plus)
		ob->out = ft_free_strjoin_rev("+", ob->out);
	else if (NEG && !(ob->flag.f_plus))
		ob->out = ft_free_strjoin_rev("-", ob->out);
	if (LENW > 0)
		ob->out = ft_free_strjoin_duo(ft_memset(ft_strnew(LENW), ' ', LENW),
		 ob->out);
	//ob->ret += write(ob->fd, &(ob->out), ft_strlen(ob->out));
	printf("%s\n", ob->out);
	free(ob->out);
}