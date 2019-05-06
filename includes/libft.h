/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 20:37:53 by ojessi            #+#    #+#             */
/*   Updated: 2019/05/06 21:25:32 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "string.h"
# include <unistd.h>

int		ft_strncmp(const char *str1, const char *str2, size_t n);
void	ft_putchar(char c);
void	ft_putstr(char const *str);
void	ft_putnbr(int nb);

#endif
