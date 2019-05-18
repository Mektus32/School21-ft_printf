/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <ojessi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 20:22:31 by ojessi            #+#    #+#             */
/*   Updated: 2019/05/18 19:39:33 by ojessi           ###   ########.fr       */
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
	array[16] = 'U';
	array[17] = 'S';
	array[18] = 'O';
	array[19] = 'C';
	array[20] = 'D';
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
	int		len;
	int		tmplen;

	tmplen = 0;
	va_start(ap, format);
	len = 0;
	while (*format)
	{
		
		if (ft_strncmp(format, "%", 1) == 0)
		{
			if ((str = ft_params_arg(&format)) == NULL)
			{
				format++;
				continue;
			}
			if ((tmplen = ft_checkarg(ap, str)) < 0)
			{
				tmplen = 0;
				if (str[tmplen] == ' ')
					tmplen++;
				len += ft_strlen(str + tmplen);
				ft_putstr(str + tmplen);
				free(str);
				format++;
				continue;
			}
			len += tmplen;
			free(str);
		}
		else
		{
			ft_putchar(*format);
			len++;
		}
		format++;
	}
	va_end(ap);
	return (len);
}