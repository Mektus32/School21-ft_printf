/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_strcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <ojessi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 21:45:30 by ojessi            #+#    #+#             */
/*   Updated: 2019/05/18 16:25:47 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_free_strcpy(char *dest, char *source)
{
	int i;
	int	j;

	i = 8;
	j = 0;
	while (source[i] != '\0')
	{
		dest[j] = source[i];
		i++;
		j++;
	}
	free(source);
	dest[j] = '\0';
	return (dest);
}
