#include "fillit.h"

char		**ft_new_grid(int size)
{
	int		i;
	int		j;
	char	**ret;

	i = 0;
	ret = (char**)malloc(sizeof(char*) * (size + 1));
	if (!ret)
		ft_putstr("malloc error1\n");
	while (size - i)
	{
		ret[i] = (char*)malloc(sizeof(char) * size);
		if (!ret[i])
			ft_putstr("malloc error2\n");
		j = 0;
		while (size - j)
		{
			ret[i][j] = '.';
			j++;
		}
		ret[i][j] = '\0';
		i++;
	}
	return (ret);
}

int			ft_get_size(t_tris *reso, t_tris src, int nbpiece)
{
	int cptreso;
	int cptcoord;
	int	max_x;
	int	max_y;

	cptcoord = 0;
	cptreso = 0;
	max_x = 0;
	max_y = 0;
	while (cptreso < nbpiece)
	{
		cptcoord = 0;
		while (cptcoord < 4)
		{
			if (max_x < reso[cptreso].coord[cptcoord].x)
				max_x = reso[cptreso].coord[cptcoord].x;
			if (max_y < reso[cptreso].coord[cptcoord].y)
				max_y = reso[cptreso].coord[cptcoord].y;
			cptcoord++;
		}
		cptreso++;
	}
	if (max_x > max_y)
		return (max_x);
	return (max_y);
}

static void	ft_print_grid(char **tab)
{
	int		i;
	int		j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			ft_putchar(tab[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	ft_putchar('\n');
}

void		ft_get_grid(t_tris *grid, int size, int nb_pieces)
{
	int		cptcoord;
	int		cptreso;
	char	**ret;

	ret = ft_new_grid(size);
	cptcoord = 0;
	cptreso = 0;
	while (cptreso <= nb_pieces)
	{
		cptcoord = 0;
		while (cptcoord < 4)
		{
			ret[grid[cptreso].coord[cptcoord].y][grid[cptreso].coord[cptcoord].x] \
			= grid[cptreso].name;
			cptcoord++;
		}
		cptreso++;
	}
	ft_print_grid(ret);
}