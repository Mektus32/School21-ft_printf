#include "ft_printf.h"

typedef struct		lol
{
	unsigned long			man : 52;
	unsigned long			exp : 11;
	unsigned long			sign : 1;
}					lol_t;

typedef union		kek
{
	double		nbr;
	lol_t			noi;
}					kek_t;

int 			main()
{
	//filler_launch();

	// kek_t		kek;

	// kek.nbr = 2.001;
	// ft_printf("%lx, %lx, %lx\n", kek.noi.sign, kek.noi.exp, kek.noi.man);
	// ft_printf("%d\n", kek.noi.exp - 1023);// зависит от степени двойки целый части

	
	// for (int i = 0; i < 15; i++)
	// if (i < 5)
	// 	ft_printf("{wht}%s{wht}%s{wht}%s\n", "РОCCИЯ", "РОCCИЯ", "РОCCИЯ");
	// else if (i < 10)
	// 	ft_printf("{blu}%s{blu}%s{blu}%s\n", "РОCCИЯ", "РОCCИЯ", "РОCCИЯ");
	// else
	// 	ft_printf("{red}%s{red}%s{red}%s\n", "РОCCИЯ", "РОCCИЯ", "РОCCИЯ");
	
	return (0);
}