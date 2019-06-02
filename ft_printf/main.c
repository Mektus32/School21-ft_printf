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
	//ft_printf("%.1f %f %f %f %f", 10.10, 10.20, 10.30, 10.40, 10.50);
	//ft_printf("%С", L'猫');
  //ft_printf("%d%d%d\n", 42, 43, 44);
  //ft_printf("%ld\n", 2147483647);
  //ft_printf("%lld\n", 9223372036854775807);
  //ft_printf("%x\n", 505);
  //ft_printf("%X\n", 505);
  //ft_printf("%p\n", &ft_printf);
  ft_printf("%b", 5);
//   ft_printf("%-10d\n", 3);
//   ft_printf("% d\n", 3);
//   ft_printf("%+d\n", 3);
//   ft_printf("%010d\n", 1);
//   ft_printf("%hhd\n", 0);
//   ft_printf("%jd\n", 9223372036854775807);
//   ft_printf("%zd\n", 4294967295);
//   ft_printf("%\n");
//   ft_printf("%U\n", 4294967295);
//   ft_printf("%u\n", 4294967295);
//   ft_printf("%o\n", 40);
//   ft_printf("%%#08x\n", 42);
//   ft_printf("%x\n", 1000);
//   ft_printf("%#X\n", 1000);
//   ft_printf("%s\n", NULL);
//   ft_printf("%S\n", L"ݗݜशব");
//   ft_printf("%s%s\n", "test", "test");
//   ft_printf("%s%s%s\n", "test", "test", "test");
//   ft_printf("%C\n", 15000);
}