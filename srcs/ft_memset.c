/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <ojessi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 18:14:26 by ojessi            #+#    #+#             */
/*   Updated: 2019/05/20 20:59:03 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memset(void *memptr, int value, int num)
{
	unsigned char *str;

	str = memptr;
	while (num-- > 0)
		*str++ = value;
	return (memptr);
}
