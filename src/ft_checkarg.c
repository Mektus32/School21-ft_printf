/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkarg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <ojessi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 21:04:42 by ojessi            #+#    #+#             */
/*   Updated: 2019/05/13 22:03:08 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_checkarg(va_list ap, char *str)
{
	int		i;

	i = -1;
	while (str[++i] != '\0')
		if (str[i] == 's')
			return (ft_print_s(va_arg(ap, char *), str));
		else if (str[i] == 'd' || str[i] == 'i')
			return (ft_print_di(va_arg(ap, long long int), str));
		else if (str[i] == 'c')
			return (ft_print_c((char)va_arg(ap, int), str));
		else if (str[i] == 'f')
			ft_putfnbr(va_arg(ap, double), 6);
		return (0);
}
