/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkarg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 21:04:42 by ojessi            #+#    #+#             */
/*   Updated: 2019/05/06 21:37:41 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_checkarg(va_list ap, const char *format)
{
	printf("%c\n", *format);
	while (*format)
	{
		if (*format == 's')
		{
			ft_putstr(va_arg(ap, char *));
		}
		else if (*format == 'd')
		{
			ft_putnbr(va_arg(ap, int));
		}
		else if (*format == 'c')
		{
			ft_putchar((char)va_arg(ap, int));
		}
		format++;
	}
}
