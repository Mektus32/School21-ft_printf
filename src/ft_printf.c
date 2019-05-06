/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 20:22:31 by ojessi            #+#    #+#             */
/*   Updated: 2019/05/06 21:32:50 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list	ap;

	va_start(ap, format);
	while (*format)
	{
		if (ft_strncmp(format, "%", 1) == 0)
			ft_checkarg(ap, format);
		else
			ft_putchar(*format);
		format++;
	}
	return (0);
}

int		main(void)
{
	ft_printf("kek%d", 10);
	return (0);
}
