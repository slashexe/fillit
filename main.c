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

#include "libft.h"
#include "fillit.h"


int		main(int argc, char **argv)
{
	t_list	*list;
	t_map	*map;

	if (argc != 2)
	{
		ft_putstr("a voir si error ou non\n");
		return (1);
	}
	/*
	**read_tetris doit lire entree
	**
	**verifier forme valide ou non
	**
	**
	**return t_list list return null si erreur dans la lecture
	*/
	if ((list = read_tetri(open(argv[1], O_RDONLY))) == NULL)
	{
		ft_putstr("error\n");
		return (1);
	}
	/*
	**reste ici;
	**resoudre + print
	*/
	return (0);
}