/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 20:22:31 by ojessi            #+#    #+#             */
/*   Updated: 2019/05/07 17:15:18 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_fill_array(char *array)
{

	array[0] = 'c';//c
	array[1] = 's';//s
	array[2] = 'p';//p
	array[3] = 'd';//d
	array[4] = 'i';//i
	array[5] = 'o';//o
	array[6] = 'u';//u
	array[7] = 'x';//x
	array[8] = 'X';//X
	array[9] = 'f';//f
	array[10] = 'e';//e
	array[11] = 'g';//g
	array[12] = 'b';//b
	array[13] = 'r';//r
	array[14] = 'k';//k
	array[15] = '%';
}

static	char	*ft_params_arg(const char **format)
{
	int		i;
	int		j;
	char	array[COUNT_ARG];
	int		len;
	char	*new;

	ft_fill_array(array);
	j = 0;
	len = 0;
	new = NULL;
	while ((*format)[++j] != '\0')
	{
		i = -1;
		len++;
		while (++i < COUNT_ARG)
			if ((*format)[j] == array[i])
			{
				new = ft_strsub(*format, 1, len);
				*format += len;
				return (new);
			}
	}
	return (new);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*str;

	va_start(ap, format);
	while (*format)
	{
		if (ft_strncmp(format, "%", 1) == 0)
		{
			if ((str = ft_params_arg(&format)) == NULL)
				exit(0);
			ft_checkarg(ap, str);
			free(str);
		}
		else
			ft_putchar(*format);
		format++;
	}
	va_end(ap);
	return (0);
}

int		main(void)
{
	//float		a = -0.1012313;//6
    //int		a = 10;
    //int		*p = &a;
	
	//ft_printf("%.10d kek %2.9s grgerg %f", 200, "lol", 10.19);
	ft_printf("%-+13.4d§\n", 100);
	//ft_printf("%d\n", ft_nbrlen(-100));
	printf("%-+13.4d§\n", 100);
    // printf("p = %p, x = %x, d = %d", p, p, p);
	//printf("%1$d:%2$.*3$d:%4$.*3$d\n", 1, 2, 3, 4);//1:002:004
	//printf("%.d",2);
	return (0);
}
