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

	array[0] = 'd';
	array[1] = 'i';
	array[2] = 'o';
	array[3] = 'u';
	array[4] = 'x';
	array[5] = 'X';
	array[6] = 'e';
	array[7] = 'E';
	array[8] = 'f';
	array[9] = 'F';
	array[10] = 'g';
	array[11] = 'G';
	array[12] = 'a';
	array[13] = 'A';
	array[14] = 'c';
	array[15] = 's';
	array[16] = 'p';
	array[17] = 'n';
	array[18] = '%';
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
			str = ft_params_arg(&format);
			ft_checkarg(ap, str);
			free(str);
		}
		else
			ft_putchar(*format);
		format++;
	}
	return (0);
}

int		main(void)
{
	//float a = -0.1012313;//6
	
	ft_printf("%.10d kek %2.9s grgerg %f", 200, "lol", 10.19);
	return (0);
}
