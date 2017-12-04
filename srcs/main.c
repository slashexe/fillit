/*
** pas plus de 26 tetriminos
**
**
**
**
**
**
**
**return (char 'A' puis ++)
*/

#include "../include/libft.h"
#include "../include/fillit.h"


int		main(int argc, char **argv)
{
	t_list	*list;
	t_map	*map;

	map = init_conf();
	if (*argc == 2)
	{
		if ((map = open_file(argv[1], map)) != NULL)
		{
			algo(map);
			ft_print_grid(map->grid);
			return (1);
		}
	}
	ft_putstr("error\n");
	return (0);
	


	/*
	**read_tetris doit lire entree
	**
	**verifier forme valide ou non
	**
	**
	**return t_list list return null si erreur dans la lecture
	*/

	/*
	**reste ici;
	
	**resoudre + print
	*/
}