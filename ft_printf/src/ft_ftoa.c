#include "ft_printf.h"

char    *ft_ftoa(long double nbr)
{
    char    *str;
    long    tmp;
    int     neg;
    int     len;

    neg = (nbr < 0 ? -1 : 1);
    len = (nbr < 0 ? 1 : 0);
    nbr *= neg;
    tmp = (long)nbr;
    while (tmp > 0 && len++ >= 0)
        tmp /= 10;
    while (nbr - (long)nbr != 0 && len++ >= 0)
        nbr *= 10;
    str = ft_strnew(len);
    while (--len >= 0)
    {
        str[len] = (long)nbr + '0';
        nbr /= 10;
        if (neg == -1 && len == 1)
        {
            str[0] = '-';
            break ;
        }
    }
    return (str);
}