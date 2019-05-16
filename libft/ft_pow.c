/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <ojessi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 13:55:13 by ojessi            #+#    #+#             */
/*   Updated: 2019/05/16 15:15:47 by ojessi           ###   ########.fr       */
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
	if (nbr != 10)
		while (++i < power)
			res *= nbr;
	else
	{
		res = 0;
		while (++i < power)
			res += (nbr << 3) + (nbr << 1);
	}
	return (res);
}
