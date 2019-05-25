#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define FLAGS " #*+-.0123456789Lhjltz"
# define ISNUM(x) (x >= '0' && x <= '9')

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
//# include <unistd.h>
# include <io.h>
# include <wchar.h>
# include <limits.h>
# include <stdint.h>

typedef	struct	s_doll
{
	int		dollar : 1;
	int		num;
}				t_doll;

typedef enum	e_type
{
	type_notype = 0,
	type_h,
	type_hh,
	type_l,
	type_ll,
	type_j,
	type_z,
	type_t,
	type_L
}				t_type;

typedef	struct		s_flag
{
    int		minus : 1;
	int		plus : 1;
	int		space : 1;
	int		hash : 1;
	int		zero : 1;
	int		quote : 1;
	int		dot : 1;
	int		negativ : 1;
	int		weight;
	int		prec;

}					t_flag;

typedef	struct		s_ob
{
	va_list		ap[2];
	int			i;
	int			ret;
	int			fd;
	t_flag		flag;
	t_type		type;
	t_doll		dollar;
	char		*out;
}					t_ob;

int		ft_strncmp(const char *str1, const char *str2, size_t n);
char	*ft_strchr(const char *str, int ch);
int		ft_printf(const char *restrict fmt, ...);
char	*ft_free_strcpy(char *dest, char *source);
char	*ft_strnew(size_t size);
int		ft_strlen(const char *str);
char	*ft_free_strjoin_duo(char const *s1, char const *s2);
int		ft_atoi(const char *str);
char	*ft_free_strncpy(char *dest, const char *new, size_t n);
void	*ft_memset(void *memptr, int value, size_t num);
char	*ft_strdup(const char *str);
char	*ft_itoa(int n);
char	*ft_ltoa(long n);
char	*ft_free_strjoin_rev(char *src, char *new);
char	*ft_strjoin(char const *s1, char const *s2);
void	check_settings(const char *restrict fmt, t_ob *ob);
void	check_args(const char *__restrict fmt, t_ob *ob);
void	choise_specs(const char *restrict fmt, t_ob *ob);
void	print_percent(t_ob *ob);
void	print_char(t_ob *ob);
void	print_str(t_ob *ob);
void	print_int(t_ob *ob);
void	init_str_arg(t_ob *ob, char **tmp);
void	init_char_arg(t_ob *ob, int *c);
void	init_int_arg(t_ob *ob, long *nbr);
void	print_digit(t_ob *ob);
#endif