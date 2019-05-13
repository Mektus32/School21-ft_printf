#include "libft.h"

char	*ft_atoa_binary_base(char *str, int base, int uppercase)
{
	int				i;
	int				res;
	int				j;

	if (base < 2 || base > 16)
		return (NULL);
	i = ft_strlen(str);
	res = 0;
	j = -1;
	while (--i >= 0)
		res += (str[i] - '0') * ft_pow(2, ++j);
	return (ft_itoa_base(res, base, uppercase));
}
