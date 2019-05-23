#include "ft_printf.h"

void    print_percent(t_ob *ob)
{
    if (ob->flag.minus)
    {
        ob->ret += write(ob->fd, "%", 1);
        while (--ob->flag.weight > 0)
            ob->ret += write(ob->fd, " ", 1);
    }
    else
    {
        while (--ob->flag.weight > 0)
            ob->ret += (ob->flag.zero) ?
            write(ob->fd, "0", 1) : write(ob->fd, " ", 1);
            ob->ret += write(ob->fd, "%", 1);
    }
    ob->i++;
}

