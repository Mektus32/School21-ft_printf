#include "libft.h"

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

static	char	*ft_strmirror(char *str)
{
	int		i;
	int		flag;
	char	*tmp;
	int		size;

	if (ft_strlen(str) < 8)
		size = 8;
	else if (ft_strlen(str) < 16)
		size = 16;
	else if (ft_strlen(str) < 32)
		size = 32;
	else
		size = 64;
	i = -1;
	flag = 1;
	tmp = ft_free_strjoin_duo(ft_memset(ft_strnew(size - ft_strlen(str)), '0', size - ft_strlen(str)), str);
	while (tmp[++i] != '\0')
		if (tmp[i] == '0')
			tmp[i] = '1';
		else if (tmp[i] == '1')
			tmp[i] = '0';
	i = ft_strlen(tmp);
	while (--i >= 0)
		if (flag == 1 && tmp[i] == '0')
		{
			tmp[i] = '1';
			flag = 0;
		}
		else if (flag == 1 && tmp[i] == '1')
			tmp[i] = '0';
	return (tmp);
}

static	char	*ft_negative(long long int nbr, int base, int uppercase)
{
	int					i;
	char				*tmp;
	long long int		res;
	int					j;

	nbr *= -1;
	i = 0;
	res = 1;
	while (res <= nbr && i < 63)
	{
		res <<= 1;
		i++;
	}
	j = i;
	tmp = ft_strnew(i);
	i = -1;
	while (++i < j)
	{
		tmp[i] = nbr % 2 + '0';
		nbr >>= 1;
	}
	tmp = ft_strrev(tmp);
	tmp = ft_strmirror(tmp);
	return (ft_atoa_binary_base(tmp, base, uppercase));
}

char    *ft_itoa_base(long long int nbr, int base, int uppercase)
{
	int					i;
	long long int		res;
	char				*tmp;
	int					j;
	int					k;

	k = 0;
	if (base < 2 || base > 16)
		return (NULL);
	if (base == 10 && nbr == -9223372036854775807ll - 1)
		return (ft_strdup("-9223372036854775808"));
	if (base == 16 && nbr == (-9223372036854775807ll - 1) && uppercase != 0)
		return (ft_strdup("7FFFFFFFFFFFFFFF"));
	if (base == 16 && nbr == (-9223372036854775807ll - 1) && uppercase == 0) 
		return (ft_strdup("7fffffffffffffff"));
	if (base == 8 && nbr == (-9223372036854775807ll - 1) && uppercase == 0) 
		return (ft_strdup("777777777777777777777"));
	if (nbr < 0)
		return (ft_negative(nbr, base, uppercase));
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