#include "ft_printf.h"

int     ft_print_di(long long int nbr, char *new)
{
    int     i;
    char    *tmp;
	int		len;
	t_bool	negativ;
    t_print t = {0,0,0,0,0,0,0,0,0,0,0,0,0,"00"};
    
    i = -1;
	t.a_nbr = -1;
    while(new[++i] != '\0')
    {
        if (new[i] == '-' || new[i] == '+' || new[i] == ' ' ||
			new[i] == '#' || new[i] == '0' || new[i] == 39)
		{
			if (t.w_nbr == 0 && t.w_star == FALSE && t.a_dot == FALSE && t.a_nbr == -1 &&
			t.s_type == FALSE)
        	{
            	if (new[i] == '-')
                	t.f_minus = TRUE;
            	else if (new[i] == '+')
                	t.f_plus = TRUE;
            	else if (new[i] == ' ')
                	t.f_space = TRUE;
            	else if (new[i] == '#')
                	t.f_grid = TRUE;
            	else if (new[i] == '0')
                	t.f_zero = TRUE;
				else if (new[i] == 39)
					t.f_quote = TRUE;
            	continue;
        	}
			else
				exit(0);//error
		}
        if (t.a_dot == FALSE && t.a_nbr == -1 && t.s_type == FALSE &&
			((new[i] >= '1' && new[i] <= '9') || new[i] == '*'))
        {
            if (new[i] >= '1' && new[i] <= '9')
                i += ft_nbrlen((t.w_nbr = ft_atoi(&(new[i])))) - 1;
            else if (t.w_star == TRUE || (t.w_nbr != 0 && new[i] == '*'))
				exit(0);//error
			else if (new[i] == '*')
				t.w_star = TRUE;
			continue;
        }
		if (new[i] == '.')
			t.a_dot = TRUE;
		if (t.a_dot == TRUE && t.s_type == FALSE)
		{
			i++;
			if ((new[i] >= '0' && new[i] <= '9') && t.a_star == FALSE)
			{
				i+= ft_nbrlen(t.a_nbr = ft_atoi(&(new[i]))) - 1;
				t.a_nbr_bool = TRUE;
			}
			else if (t.a_star == TRUE)
				exit(0);//error
			if (new[i] == '*')
			{
				if (t.a_star == FALSE && t.a_nbr == -1)
				{
					t.a_star = TRUE;
					i++;
				}
				else
					exit(0);//error
			}
		}
		if (new[i] == 'h' || new[i] == 'l' || new[i] == 'L' || new[i] == 'j' || new[i] == 'z')
		{
			t.s_type = TRUE;
			t.s_str[0] = new[i];
			t.s_str[1] = new[i + 1];//?
			i += 2;
		}
    }
	if (t.f_grid == TRUE || t.s_str[0] == 'L')
        exit(0);//error
    t.f_plus == TRUE ? t.f_space = FALSE : 0;
	t.w_nbr = (t.f_plus == TRUE && nbr >= 0ll && (t.f_minus == TRUE || t.f_zero == TRUE)) ? t.w_nbr - 1 : t.w_nbr;
    if (t.f_minus == TRUE)
        t.f_zero = FALSE;
	negativ = FALSE;
	if (t.s_type == TRUE)
	{
		if (t.s_str[0] == 'h' && t.s_str[1] != 'h')
			nbr = (short)nbr;
		if (t.s_str[0] == 'h' && t.s_str[1] == 'h')
			nbr = (char)nbr;
	}
	else
		nbr = (int)nbr;
	if (nbr == 0ll && t.a_dot == TRUE)
		tmp = ft_strnew(1);
	else
		tmp = (nbr < 0ll && (t.f_zero == TRUE || t.a_dot == TRUE)) ? ft_itoa(-nbr) : ft_itoa(nbr);
	t.w_nbr = (nbr < 0ll && t.f_zero == TRUE) ? t.w_nbr - 1: t.w_nbr;
	(t.a_dot == TRUE && t.f_zero == TRUE) ? t.f_zero = FALSE : 0;
	if (t.a_dot == TRUE && t.a_nbr > (int)ft_strlen(tmp))
		tmp = ft_free_strjoin_duo(ft_memset(ft_strnew(t.a_nbr - ft_strlen(tmp)), '0', t.a_nbr - ft_strlen(tmp)), tmp);
	if (t.f_space == TRUE && nbr >= 0ll)
    	tmp = ft_free_join_rev(" ", tmp);
	if (t.f_zero == TRUE && t.w_nbr > (int)ft_strlen(tmp))
		tmp = ft_free_strjoin_duo(ft_memset(ft_strnew(t.w_nbr - ft_strlen(tmp)), '0', t.w_nbr - ft_strlen(tmp)), tmp);
	if (t.f_minus == TRUE && t.w_nbr > (int)ft_strlen(tmp))
		tmp = ft_free_strjoin_duo(tmp, ft_memset(ft_strnew(t.w_nbr - ft_strlen(tmp)), ' ', t.w_nbr - ft_strlen(tmp)));
	if (t.f_plus == TRUE && nbr >= 0ll)
    	tmp = ft_free_join_rev("+", tmp);
	if (t.w_nbr > (int)ft_strlen(tmp))
		tmp = ft_free_strjoin_duo(ft_memset(ft_strnew(t.w_nbr - ft_strlen(tmp)), ' ', t.w_nbr - ft_strlen(tmp)), tmp);
	(nbr < 0ll && (t.f_zero == TRUE || t.a_dot == TRUE)) ? ft_putchar('-') : 0;
	len = (nbr < 0ll && (t.f_zero == TRUE || t.a_dot == TRUE)) ? 1 : 0;
	len += (int)ft_strlen(tmp);
	ft_putstr(tmp);
    free(tmp);
	return (len);
}