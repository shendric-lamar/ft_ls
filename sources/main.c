#include "ft_ls.h"

void    init(t_ls *ls, char **av)
{
    ls->input == NULL;
    ls->size == 0;
    ls->i = 0;
    ls->j = 0;
	ls->path = av[2];
}

void    store_input(t_ls *ls, char **av)
{
    ls->i = 1;
    while (av[ls->i] != '\0')
    {
        ls->j = 0;
        while (av[ls->i][ls->j] != '\0')
        {
            if (av[ls->i][ls->j] == '-')
            {
                printf("j: %d\n", ls->j);
                if (av[ls->i][ls->j] == "-")
                    ls->input[0] = av[ls->i][ls->j];
                printf("ls->input: %s\n", ls->input[0]);
                if (av[ls->i][ls->j] == "l")
                    ls->input[1] = "l";
                if (av[ls->i][ls->j] == "R")
                    ls->input[2] = "R";
                if (av[ls->i][ls->j] == "a")
                    ls->input[3] = "a";
                if (av[ls->i][ls->j] == "r")
                    ls->input[4] = "r";
                if (av[ls->i][ls->j] == "t")
                    ls->input[5] = "t";
            }
            ls->j++;
        }
        ls->i++;
    }
}

void    malloc_input(t_ls *ls)
{
    ls->i = 0;
    ls->input = (char **)malloc(sizeof(char *) * 6);
    while (ls->i < 6)
    {
        ls->input[ls->i] = (char *)malloc(sizeof(char) * 1);
        ls->i++;
    }
}

int     main(int ac, char **av)
{
    t_ls ls;

    init(&ls, av);
    if (ac >= 2)
    {
        malloc_input(&ls);
        store_input(&ls, av);
        print(&ls);
    }
}
