#include "ft_printf.h"

static	char	ft_letter(int value, int uppercase)
{
	if (uppercase != 0)
		uppercase = -32;
	else
		uppercase = 0;
	if (value == 10)
		return ('a' + uppercase);
	if (value == 11)
		return ('b' + uppercase);
	if (value == 12)
		return ('c' + uppercase);
	if (value == 13)
		return ('d' + uppercase);
	if (value == 14)
		return ('e' + uppercase);
	if (value == 15)
		return ('f' + uppercase);
	return (0);
}

char    *ft_itoa_base_u(unsigned long long int nbr, int base, int uppercase)
{
	int					i;
	unsigned long long int		res;
	char				*tmp;
	int					j;
	int					k;

	k = 0;
	if (base < 2 || base > 16)
		return (NULL);
	i = 0;
	res = 1;
	while (res <= nbr && (res * base != 0) && i < 63)
	{
		res *= base;
		i++;
	}
	if (res * base == 0)
		i++;
	j = i;
	tmp = ft_strnew(i);
	i = -1;
	while (++i < j)
	{
		tmp[i] = nbr % base > 9 ? ft_letter(nbr % base, uppercase) : nbr % base + '0';
		nbr /= base;
	}
	ft_strrev(tmp);
	i = -1;
	while (tmp[++i] != '\0')
		if (tmp[i] == '0')
			k++;
	if (k == (int)ft_strlen(tmp))
		{
			free(tmp);
			tmp = ft_strdup("0");
		}
	return (tmp);
}