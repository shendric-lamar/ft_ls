#include "ft_ls.h"

void print(t_ls *ls)
{
	printf("%s\n", ls->input[0]);
	if (ls->input[0] == "-")
		display_all(ls);
}

void	display_all(t_ls *ls)
{
	DIR	*dir;
	struct dirent *ent;

	if (!(dir = opendir(ls->path)))
		write(1, "error", 5);
	while ((ent = readdir(dir)) != NULL)
	{
		if (ent->d_name[0] != '.')
			ft_putendl(ent->d_name);
		else
			ft_putendl(ent->d_name);
	}
	closedir(dir);
}
