/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 20:18:28 by ojessi            #+#    #+#             */
/*   Updated: 2019/05/07 17:15:21 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define COUNT_ARG 16

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>
# include <unistd.h>
# include "libft.h"

typedef enum 	e_bool
{
 	FALSE,
	TRUE
}				t_bool;

typedef	struct	s_print
{
	t_bool	f_minus;
	t_bool	f_plus;
	t_bool	f_space;
	t_bool	f_grid;//решетка
	t_bool	f_zero;
	t_bool	f_quote;//кавычка
	int		w_nbr;
	t_bool	w_star;
	t_bool	a_dot;
	int		a_nbr;
	t_bool	a_nbr_bool;
	t_bool	a_star;
	t_bool	s_type;
	char	s_str[2];
}				t_print;

int				ft_printf(const char *format, ...);
void			ft_checkarg(va_list ap, char *str);
int				ft_print_s(char *str, char *new);
int				ft_print_di(long long int nbr, char *new);

#endif
