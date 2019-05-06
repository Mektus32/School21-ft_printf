/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 20:36:42 by ojessi            #+#    #+#             */
/*   Updated: 2019/05/06 20:44:16 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t i;

	i = 0;
	if (!n)
		return (0);
	while ((str1[i] != '\0' || str2[i] != '\0') && i < n - 1)
	{
		if ((unsigned char)str1[i] != (unsigned char)str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	if ((unsigned char)str1[i] != (unsigned char)str2[i])
		return ((unsigned char)str1[i] - (unsigned char)str2[i]);
	return (0);
}
