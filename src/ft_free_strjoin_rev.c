/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_strjoin_rev.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <ojessi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 19:21:34 by ojessi            #+#    #+#             */
/*   Updated: 2019/06/02 14:46:33 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_free_strjoin_rev(char *src, char *new)
{
	char	*tmp;

	if (!(tmp = ft_strjoin(src, new)))
		return (NULL);
	free(new);
	new = NULL;
	return (tmp);
}
