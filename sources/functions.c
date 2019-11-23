#include "ft_ls.h"

void    ft_error(int flag)
{
    if (flag == 1)
        ft_putendl("malloc error!");
    else if (flag == 2)
        ft_putendl("usage: ./ft_ls [-lRart] [directory...]");
}
