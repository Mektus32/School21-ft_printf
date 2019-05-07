/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 14:04:51 by ojessi            #+#    #+#             */
/*   Updated: 2019/05/07 14:05:36 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *memptr, int value, size_t num)
{
	unsigned char *str;


	str = memptr;
	while (num-- > 0)
		*str++ = value;
	return (memptr);
}
