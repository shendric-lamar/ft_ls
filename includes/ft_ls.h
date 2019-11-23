#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include <dirent.h>
# include <stdio.h>
# include <unistd.h>

typedef struct  s_ls
{
    char    **input;
    int     size;
    int     i;
    int     j;
	int		k;
	char	*path;
}               t_ls;

int		main(int ac, char **av);

void	display_all(t_ls *ls);
#endif
