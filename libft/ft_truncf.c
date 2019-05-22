/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_truncf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 13:15:29 by ojessi            #+#    #+#             */
/*   Updated: 2019/05/07 13:16:36 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	ft_truncf(float nbr)
{
	int		whole;
	float	res;

	whole = (int)nbr;
	res = (float)whole;
	return (res);
}