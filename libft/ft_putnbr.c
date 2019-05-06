/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 21:24:09 by ojessi            #+#    #+#             */
/*   Updated: 2019/05/06 21:25:03 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int nb)
{
	int index;
	int number[20];

	index = -1;
	if (nb < 0)
	{
		if (nb == -2147483648)
		{
			nb = -214748364;
			number[++index] = 8;
		}
		ft_putchar('-');
		nb *= -1;
	}
	while (nb / 10 != 0)
	{
		number[++index] = nb % 10;
		nb /= 10;
	}
	number[++index] = nb % 10;
	index++;
	while (index != 0)
		ft_putchar('0' + number[--index]);
}
