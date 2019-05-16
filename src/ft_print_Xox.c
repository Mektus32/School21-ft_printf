#include "ft_printf.h"

int     ft_print_Xox(long long int nbr, char *new, int base, int uppercase)
{
    int		i;
    char	*tmp;
	int		len;
    int		size;
	
    t_print t = {0,0,0,0,0,0,0,0,0,0,0,0,0,"00"};
    
    i = -1;
	t.a_nbr = -1;
    size = 8;
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
		if (new[i] == 'l' || new[i] == 'j')
		{
			t.s_type = TRUE;
			t.s_str[0] = new[i];
			t.s_str[1] = new[i + 1];//?
			i += 2;
		}
    }
	
	if (t.f_plus == TRUE || t.f_space == TRUE || t.f_quote == TRUE)
		exit(0);//error

	if (t.f_minus == TRUE)
		t.f_zero = 0;
	if (t.s_type == TRUE)
	{
		if  (t.s_str[0] == 'j')
			nbr = (unsigned long long int)nbr;
	}
	else
		nbr = (int)nbr;

	if (t.w_nbr == 0 && t.a_nbr_bool == TRUE && t.a_nbr == 0 && nbr == 0ll)
		if (base != 8 || t.f_grid == FALSE)
			return (0);

	if (t.a_dot == TRUE && nbr == 0)
	{
		if (base != 8 || t.f_grid == FALSE)
			tmp = ft_strdup(" ");
		else
			tmp = ft_itoa_base(nbr, base, uppercase);
	}
	else
		tmp = ft_itoa_base(nbr, base, uppercase);

	if (t.f_grid == TRUE && (t.f_minus == TRUE || t.f_zero == TRUE) && base == 16)
		t.w_nbr -= 2;

	if (size > (int)ft_strlen(tmp) && base == 16 && nbr < 0)
		tmp = ft_free_strjoin_duo(ft_memset(ft_strnew(size - ft_strlen(tmp)), (uppercase == 1) ? 'F' : 'f', size - ft_strlen(tmp)), tmp);

	if (t.a_dot == TRUE && t.a_nbr > (int)ft_strlen(tmp))
		tmp = ft_free_strjoin_duo(ft_memset(ft_strnew(t.a_nbr - ft_strlen(tmp)), '0', t.a_nbr - ft_strlen(tmp)), tmp);

	if (t.f_zero == TRUE && t.w_nbr > (int)ft_strlen(tmp))
		tmp = ft_free_strjoin_duo(ft_memset(ft_strnew(t.w_nbr - ft_strlen(tmp)), '0', t.w_nbr - ft_strlen(tmp)), tmp);

	if (t.f_grid == TRUE && nbr != 0 && base == 8)
		tmp = ft_free_strjoin_duo(ft_strdup("0"), tmp);

	if (t.f_minus == TRUE && t.w_nbr > (int)ft_strlen(tmp))
		tmp = ft_free_strjoin_duo(tmp, ft_memset(ft_strnew(t.w_nbr - ft_strlen(tmp)), ' ', t.w_nbr - ft_strlen(tmp)));

	if (t.f_grid == TRUE && nbr != 0 && base == 16)
		tmp = ft_free_strjoin_duo((uppercase == 1) ? ft_strdup("0X") : ft_strdup("0x"), tmp);

	if (t.w_nbr > (int)ft_strlen(tmp))
		tmp = ft_free_strjoin_duo(ft_memset(ft_strnew(t.w_nbr - ft_strlen(tmp)), ' ', t.w_nbr - ft_strlen(tmp)), tmp);

	ft_putstr(tmp);

	len = (int)ft_strlen(tmp);
	free(tmp);
	return (len);
}