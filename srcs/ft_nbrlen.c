#include "ft_printf.h"

int     ft_nbrlen(int   nbr)
{
    int		len;

	len = 0;
	if (nbr < 0)
	{
		len++;
		nbr *= -1;
	}
	while (nbr / 10 > 0)
	{
		len++;
		nbr /= 10;
	}
	len++;
	return (len);
}