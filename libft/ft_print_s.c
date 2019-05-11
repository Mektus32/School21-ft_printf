#include "ft_printf.h"

int     ft_print_s(char *str, char *new)
{
    str = NULL;
    int     i;
    t_print t = {0,0,0,0,0,0,0,0,0,0,0,0,0};
    
    i = -1;
    t.w_nbr = -1;
    t.a_nbr = 0;
    while(new[++i] != '\0')
    {
        if (new[i] == '-' || new[i] == '+' || new[i] == ' ' ||
			new[i] == '#' || new[i] == '0' || new[i] == 39)
		{
			if (t.w_nbr == -1 && t.w_star == FALSE && t.a_dot == FALSE && t.a_nbr == 0 &&
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
            	continue;//?
        	}
			else
				exit(0);//error
		}
        if (t.a_dot == FALSE && t.a_nbr == 0 && t.s_type == FALSE &&
			((new[i] >= '1' && new[i] <= '9') || new[i] == '*'))
        {
            if (new[i] >= '1' && new[i] <= '9')
            {
                t.w_nbr = ft_atoi(&(new[i]));
                while (new[i] >= '1' && new[i] <= '9')
                    i++;
            }
            else if (t.w_star == TRUE || (t.w_nbr != -1 && new[i] == '*'))
				exit(0);//error
			else if (new[i] == '*')
				t.w_star = TRUE;
			//continue;//?
        }
		if (new[i] == '.')
			t.a_dot = TRUE;
		if (t.a_dot == TRUE && t.s_type == FALSE)
		{
			if ((new[i] >= '0' && new[i] <= '9') && t.a_star == FALSE)
			{
				t.a_nbr = ft_atoi(&(new[i]));//ft_nbr_len;
				t.a_nbr_bool = TRUE;
				i++;
				while (new[i] >= '0' && new[i] <= '9')
					i++;
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
		if (new[i] == 's')
			t.s_type = TRUE;
    }
	printf("f_minus = %d\nf_plus = %d\nf_space = %d\nf_grid = %d\nf_zero = %d\nf_quote = %d\nw_nbr = %d\nw_star = %d\na_dot = %d\na_nbr = %d\na_star = %d\ns_typed = %d\nt_nbr_bool = %d\n", t.f_minus, t.f_plus, t.f_space, t.f_grid, t.f_zero, t.f_quote, t.w_nbr, t.w_star, t.a_dot, t.a_nbr, t.a_star, t.s_type, t.a_nbr_bool);
    return (0);
}