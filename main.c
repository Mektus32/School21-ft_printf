#include "ft_printf.h"
#include <limits.h>
int     main(void)
{
    int     i = 10;
    //ft_printf("%+u", 4294967295);
    //ft_printf("%-5.10o", 2500);
    //ft_printf("%-'u", -1);
    //ft_printf("%U", 4294967296);
    //ft_printf("% 10.5d", 4242);
    //ft_printf("%d", ft_printf("100000000000000000000000000000000"));
    //ft_printf("%jx", -4294967297);
    //ft_printf("%#08x", 42);
    //ft_printf("%x", -42);
    //ft_printf("@moulitest: %#.o %#.0o", 0, 0);
    //ft_printf("@moulitest: %5.0x %5.x", 0, 0);
    // ft_printf("%p\n", &i);
    // printf("%p\n", &i);
    // printf("%o\n", 999988888);
    //ft_printf("%o", 999988888);
    // printf("%p\n", &i);
    // ft_printf("%p", &i);
    // ft_printf("a%Sb%sc%S", L"我", "42", L"猫");
    //ft_printf("%s\n", ft_itoa_base_u(999988888, 8, 0));
    printf("%O\n", LONG_MAX);
    ft_printf("%lO", LONG_MAX);
    return (0);
}