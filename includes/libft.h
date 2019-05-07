/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 20:37:53 by ojessi            #+#    #+#             */
/*   Updated: 2019/05/07 16:38:03 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "string.h"
# include <unistd.h>
# include <stdlib.h>

int		ft_strncmp(const char *str1, const char *str2, size_t n);
void	ft_putchar(char c);
void	ft_putstr(char const *str);
void	ft_putnbr(int nb);
void	ft_abs(int *nbr);
void	ft_absf(float *nbr);
float	ft_truncf(float nbr);
int		ft_pow(int nbr, int power);
void	*ft_memset(void *memptr, int value, size_t num);
char	*ft_strnew(size_t size);
void	ft_putfnbr(float fnbr, size_t quantity);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *str, int ch);

#endif
