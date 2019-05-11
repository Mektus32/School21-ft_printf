/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 14:13:21 by ojessi            #+#    #+#             */
/*   Updated: 2019/05/07 17:15:16 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_putfnbr(float fnbr, size_t quantity)
{
	float		rest;
	char	*str;

	if (fnbr < 0)
	{
		ft_putchar('-');
		ft_absf(&fnbr);
	}
	ft_putnbr((int)ft_truncf(fnbr));
	ft_putchar('.');
	if (fnbr - ft_truncf(fnbr) == 0)
	{
		str = ft_strnew(quantity);
		ft_memset(str, '0', quantity);
		ft_putstr(str);
		free(str);
	}
	else
	{
		rest = ((fnbr - ft_truncf(fnbr)));//* ft_pow(10, quantity);
		printf("fnbr - trunc = %f - %f = rest = %f\n", fnbr, ft_truncf(fnbr), rest);
		ft_putnbr((int)ft_truncf(rest));
	}
}
