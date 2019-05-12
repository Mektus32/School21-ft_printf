#include "libft.h"

int     ft_nbrlen(int nbr)
{
    int     len;

    len = 0;
    if (nbr < 0)
    {
        len++;
        ft_abs(&nbr);
    }
    while (nbr / 10 > 0)
    {
        len++;
        nbr /= 10;
    }
    len++;
    return (len);
}