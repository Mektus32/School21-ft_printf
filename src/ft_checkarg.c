/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkarg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 21:04:42 by ojessi            #+#    #+#             */
/*   Updated: 2019/05/07 17:15:23 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_checkarg(va_list ap, char *str)
{
	while (*str)
	{
		if (*str == 's')
			ft_putstr(va_arg(ap, char *));
		else if (*str == 'd')
			ft_putnbr(va_arg(ap, int));
		else if (*str == 'c')
			ft_putchar((char)va_arg(ap, int));
		else if (*str == 'f')
			ft_putfnbr(va_arg(ap, double), 6);
		str++;
	}
}
