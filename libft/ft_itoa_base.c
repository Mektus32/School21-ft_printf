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

	i = -1;
	flag = 1;
	tmp = ft_free_join_rev("0", str);
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

static	char	*ft_negative(int nbr, int base, int uppercase)
{
	int		i;
	char	*tmp;
	int		res;
	int		j;

	ft_abs(&nbr);
	i = 0;
	res = 1;
	while (res <= nbr)
	{
		res *= 2;
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

char    *ft_itoa_base(int nbr, int base, int uppercase)
{
	int		i;
	int		res;
	char	*tmp;
	int		j;

	if (base < 2 || base > 16)
		return (NULL);
	if (base == 10 && nbr == -2147483648)
		return ("-2147483648");
	if (nbr < 0)
		return (ft_negative(nbr, base, uppercase));
	i = 0;
	res = 1;
	while (res <= nbr)
	{
		res *= base;
		i++;
	}
	j = i;
	tmp = ft_strnew(i);
	i = -1;
	while (++i < j)
	{
		tmp[i] = nbr % base > 9 ? ft_letter(nbr % base, uppercase) : nbr % base + '0';
		nbr /= base;
	}
	ft_strrev(tmp);
	return (tmp);
}