#include "ft_printf.h"

int     ft_print_u(va_list ap, char *new)
{
    int						i;
    char					*tmp;
	int						len;
	unsigned long long int	nbr;
    t_print	t = {0,0,0,0,0,0,0,0,0,0,0,0,0,"00"};
    
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
				return (-1);//error
		}
        if (t.a_dot == FALSE && t.a_nbr == -1 && t.s_type == FALSE &&
			((new[i] >= '1' && new[i] <= '9') || new[i] == '*'))
        {
            if (new[i] >= '1' && new[i] <= '9')
                i += ft_nbrlen((t.w_nbr = ft_atoi(&(new[i])))) - 1;
            else if (t.w_star == TRUE || (t.w_nbr != 0 && new[i] == '*'))
				return (-1);//error
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
				return (-1);//error
			if (new[i] == '*')
			{
				if (t.a_star == FALSE && t.a_nbr == -1)
				{
					t.a_star = TRUE;
					i++;
				}
				else
					return (-1);//error
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
	if (t.f_grid == TRUE)
		return (-1);
	if (t.f_minus == TRUE)
	{
		t.f_zero = FALSE;
		t.f_space = FALSE;
	}
	if (t.s_type == TRUE || new[ft_strlen(new) - 1] == 'U')
	{
		if (((t.s_str[0] == 'l' && t.s_str[1] != 'l') || t.s_str[0] == 'j') || new[ft_strlen(new) - 1] == 'U')
			nbr = va_arg(ap ,unsigned long int);
		if (t.s_str[0] == 'l' && t.s_str[1] == 'l')
			nbr = va_arg(ap ,unsigned long long int);
		
	}
	else
		nbr = va_arg(ap, unsigned int);
	tmp = ft_itoa_u(nbr);
	if (t.a_dot == TRUE && t.a_nbr > (int)ft_strlen(tmp))
		tmp = ft_free_strjoin_duo(ft_memset(ft_strnew(t.a_nbr - ft_strlen(tmp)), '0', t.a_nbr - ft_strlen(tmp)), tmp);
	
	if (t.f_zero == TRUE && t.w_nbr > (int)ft_strlen(tmp))
		tmp = ft_free_strjoin_duo(ft_memset(ft_strnew(t.w_nbr - ft_strlen(tmp)), '0', t.w_nbr - ft_strlen(tmp)), tmp);
	
	if (t.f_minus == TRUE && t.w_nbr > (int)ft_strlen(tmp))
		tmp = ft_free_strjoin_duo(tmp, ft_memset(ft_strnew(t.w_nbr - ft_strlen(tmp)), ' ', t.w_nbr - ft_strlen(tmp)));
	
	if (t.w_nbr > (int)ft_strlen(tmp))
		tmp = ft_free_strjoin_duo(ft_memset(ft_strnew(t.w_nbr - ft_strlen(tmp)), ' ', t.w_nbr - ft_strlen(tmp)), tmp);	
    ft_putstr(tmp);
	len =ft_strlen(tmp);
	free(tmp);
	return (len);
}