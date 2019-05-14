#include "ft_printf.h"
#define LEN ((c == 0) ? (int)ft_strlen(tmp) - 1 : (int)ft_strlen(tmp))

int		ft_print_c(char	c, char *new)
{
	int     i;
    char    *tmp;
	int		len;
    t_print t = {0,0,0,0,0,0,0,0,0,0,0,0,0,"00"};
    
    i = -1;
    while(new[++i] != '\0')
    {
        if (new[i] == '-' || new[i] == '+' || new[i] == ' ' ||
			new[i] == '#' || new[i] == '0' || new[i] == 39)
		{
			if (t.w_nbr == 0 && t.w_star == FALSE && t.a_dot == FALSE && t.a_nbr == 0 &&
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
        if (t.a_dot == FALSE && t.a_nbr == 0 && t.s_type == FALSE &&
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
			if ((new[i] >= '0' && new[i] <= '9') && t.a_star == FALSE)
			{
				i+= ft_nbrlen(t.a_nbr = ft_atoi(&(new[i]))) - 1;
				t.a_nbr_bool = TRUE;
			}
			else if (t.a_star == TRUE)
				exit(0);//error
			if (new[i] == '*')
			{
				if (t.a_star == FALSE && t.a_nbr_bool == FALSE)
				{
					t.a_star = TRUE;
					i++;
				}
				else
					exit(0);//error
			}
		}
		if (new[i] == 'h' || new[i] == 'l' || new[i] == 'L')
		{
			t.s_type = TRUE;
			t.s_str[0] = new[i];
			t.s_str[1] = new[i + 1];//?
			i += 2;
		}
    }
	if (c == 0)
		tmp = ft_strdup("^@");
	else
		tmp = ft_memset(ft_strnew(1), c, 1);
	if (t.a_dot == TRUE || t.f_quote == TRUE || t.f_zero == TRUE
	|| t.f_plus == TRUE || t.f_grid == TRUE || t.s_type == TRUE)
		exit(0);//error
	if (t.f_minus == TRUE && t.w_nbr > LEN)
		tmp = ft_free_strjoin_duo(tmp, ft_memset(ft_strnew(t.w_nbr - LEN), ' ', t.w_nbr - LEN));
	if (t.w_nbr > LEN)
		tmp = ft_free_strjoin_duo(ft_memset(ft_strnew(t.w_nbr - LEN), ' ', t.w_nbr - LEN), tmp);
	ft_putstr(tmp);
	len = LEN;
	free(tmp);
	return (len);
}