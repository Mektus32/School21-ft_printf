#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define PF_FLAG " #*+-.0123456789Lhjltz"

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <wchar.h>
# include <limits.h>
# include <stdint.h>

typedef	struct	s_pf_dollar
{
	int			dollar;
	int			num;
}				t_pf_dollar;

typedef enum	e_pf_type
{
	pf_notype = 0,
	pf_h,
	pf_hh,
	pf_l,
	pf_ll,
	pf_j,
	pf_z,
	pf_t,
	pf_L
}				t_pf_type;

typedef	struct	s_pf_flag
{
	int		f_minus;
	int		f_plus;
	int		f_space;
	int		f_hash;
	int		f_zero;
	int		w_nbr;
	int		a_nbr;
	int		negativ;
}				t_pf_flag;

typedef struct	s_pf_obj
{
	va_list		ap[2];
	int			ret;
	int			i;
	int			fd;
	char		*out;
	t_pf_flag	flag;
	t_pf_dollar	dollar;
	t_pf_type	type;
}				t_pf_obj;

int     ft_printf(const char *restrict fmt, ...);
void	ft_bzero(void *s, size_t n);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
char	*ft_strchr(const char *str, int ch);
int		ft_atoi(const char *str);
int     ft_nbrlen(int   nbr);
char	*ft_strdup(const char *str);
char	*ft_itoa(int n);
char	*ft_ltoa(long n);
int		ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char    *ft_free_strjoin(char *del, char const *src);
char    *ft_free_strjoin_rev(char const *src, char *del);
char    *ft_free_strjoin_duo(char *new, char *del);
char	*ft_strnew(int size);
void	*ft_memset(void *memptr, int value, int num);
void    ft_init_flags(t_pf_flag *flag);
void	ft_get_w_nbr(t_pf_obj *ob);
void	ft_get_flag(const char *restrict fmt, t_pf_obj *ob);
void	ft_get_type(const char *restrict fmt, t_pf_obj *ob);
void	ft_get_a_nbr(const char *restrict fmt, t_pf_obj *ob);
void	ft_get_dollar(const char *restrict fmt, t_pf_obj *ob);
void	ft_get_spec(const char *restrict fmt, t_pf_obj *ob);
void	ft_print_percent(t_pf_obj *ob);
void	ft_print_int(t_pf_obj *ob);
void    ft_init_int_arg(t_pf_obj *ob, long *nbr);
void	ft_print_digit(t_pf_obj *ob);

#endif