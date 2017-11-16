#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"

typedef struct	s_map
{
	int			size;
	char		**array;
}				t_map;


t_list			*read_tetri(int fd);
#endif