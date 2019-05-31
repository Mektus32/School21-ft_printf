#include "ft_printf.h"

typedef struct		lol
{
	unsigned long			man : 52;
	unsigned long			exp : 11;
	unsigned long			sign : 1;
}					lol_t;

typedef union		kek
{
	long double		nbr;
	lol_t			noi;
}					kek_t;

void			print_bits(unsigned long value, unsigned int len)
{
	unsigned long	marker;
	unsigned int i;
	char		temp;

	marker = 1lu << (len - 1);
	i = 0;
	while (i < len)
	{
		temp = '0' + ((value & marker) >> ((len - 1u) - i ));
		write(1, &temp, 1);
		marker >>= 1u;
		i++;
	}
	write(1, "\n", 1);
}

void		move_bits(kek_t kek)
{
	unsigned long a = kek.noi.exp - 1023;

	print_bits((kek.noi.man /*| 0x10000000000000lu*/) >> (52u - a), 53);
	print_bits(((kek.noi.man << a) & 0x7FFFFFFFFFFFFlu), 52);
}

int 			main()
{
	// kek_t		kek;
	// unsigned long whole;
	// unsigned long fract;

	// kek.nbr = 5.25;
	// print_bits(kek.noi.sign, 1);
	// print_bits(kek.noi.exp, 11);
	// printf("exp = %d\n", kek.noi.exp);
	// print_bits(kek.noi.man, 52);
	// move_bits(kek);
	ft_printf("%.1f", 10.86);
}