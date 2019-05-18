/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <ojessi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 20:37:53 by ojessi            #+#    #+#             */
/*   Updated: 2019/05/18 16:07:55 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "string.h"
# include <unistd.h>
# include <stdlib.h>
# include "ft_printf.h"

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
int		ft_atoi(const char *str);
int		ft_nbrlen(int nbr);
size_t	ft_strlen(const char *str);
char	*ft_itoa(long long int n);
char	*ft_strdup(const char *str);
char	*ft_free_join(char *new, char *src);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_free_join_rev(char *src, char *new);
char	*ft_free_strsub(char const *s, unsigned int start, size_t len);
char	*ft_free_strjoin_duo(char const *s1, char const *s2);
char	*ft_itoa_base(long long int nbr, int base, int uppercase);
char	*ft_strrev(char *s);
char	*ft_atoa_binary_base(char *str, int base, int uppercase);
char	*ft_free_strncpy(char *dest, const char *new, size_t n);
char	*ft_itoa_u(unsigned long long int n);
char	*ft_itoa_base_u(unsigned long long int nbr, int base, int uppercase);
char	*ft_free_strcpy(char *dest, char *source);

#endif
