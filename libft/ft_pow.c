/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 13:55:13 by ojessi            #+#    #+#             */
/*   Updated: 2019/05/07 13:56:42 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_pow(int nbr, int power)
{
	int		i;
	int		res;

	if (nbr == 0 && power == 0)
		return (1);
	else if (nbr == 0 && power != 0)
		return (0);
	i = -1;
	res = 1;
	while (++i < power)
		res *= nbr;
	return (res);
}
