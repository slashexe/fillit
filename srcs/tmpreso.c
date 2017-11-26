t_point	*ft_new_point(int x; int y)
{
	t_point	*ret;

	ret = (*t_point)malloc(sizeof(t_point));
	ret->x = x;
	ret->y = y;
	return (ret);
}

void		ft_print_grid(char **tab)
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
}

char	**ft_new_grid(int size)
{
	int		i;
	int		j;
	char	ret;

	i = 0;
	ret = (char**)malloc(sizeof(char*) * (len + 1));
	if (!ret)
		ft_pustr("malloc error1\n");
	while (size - i)
	{
		ret[i] = (char*)malloc(sizeof(char) * size);
		if (!ret[i])
			ft_pustr("malloc error2\n");
		j = 0;
		while (size - j)
		{
			ret[i][j] = '.';
			j++;
		}
		ret[i][j] = '\0';
		i++;
	}
}

char	**ft_copy_grid(char **grid, int size)
{
	int		i;
	int		j;
	char	**ret;

	i = 0;
	ret = (char**)malloc(sizeof(char*) * (len + 1));
	while (size - i)
	{
		j = 0;
		while (siwe - j)
		{
			if (grid[i][j] != '.')
				ret[i][j] = grid[i][j];
			j++;
		}
		ret[i][j] = '\0';
		i++;
	}
	ret[NULL];//ok?
	return (ret;)
}


void	tmpReso(t_tris *map)
{
	char	**grid;
	t_point	pos;

	pos = ft_new_point(0, 0);
	map->min_size = 4;
	grid = ft_new_grid(conf->min_size);
	//faire reso dan la condition
	while (false)
	{
		map->min_size++;
		grid = ft_new_grid(conf->min_size);
	}
}