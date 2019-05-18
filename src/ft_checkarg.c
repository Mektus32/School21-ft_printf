/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkarg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <ojessi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 21:04:42 by ojessi            #+#    #+#             */
/*   Updated: 2019/05/18 19:39:54 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_checkarg(va_list ap, char *str)
{
	int		i;

	i = -1;
	while (str[++i] != '\0')
		if (str[i] == 's' || str[i] == 'S')
			return (ft_print_s(va_arg(ap, char *), str));
		else if (str[i] == 'd' || str[i] == 'i' || str[i] == 'D')
			return (ft_print_di(va_arg(ap, long long int), str));
		else if (str[i] == 'c' || str[i] == 'C')
			return (ft_print_c((char)va_arg(ap, int), str));
		else if (str[i] == 'f')
			ft_putfnbr(va_arg(ap, double), 6);
		else if (str[i] == 'x')
			return (ft_print_Xox(ap, str, 16, 0));
		else if (str[i] == 'X')
			return (ft_print_Xox(ap, str, 16, 1));
		else if (str[i] == 'o')
			return (ft_print_Xox(ap, str, 8, 0));
		else if (str[i] == 'O')
			return (ft_print_Xox(ap, str, 8, 1));
		else if (str[i] == '%')
			return (ft_print_persent(str));
		else if (str[i] == 'u' || str[i] == 'U')
			return (ft_print_u(ap, str));
		else if (str[i] == 'p')
			return (ft_print_p(va_arg(ap, long), 0, str));
		else if (str[i] == 'P')
			return (ft_print_p(va_arg(ap, long), 1, str));
		return (0);
}
