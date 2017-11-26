#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"


typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_tris
{
	char			name;
	t_point			coord[4];
}					t_tris;

typedef struct		s_map
{
	char			**grid;
	int				min_size;
	char			nbr_piece;
	struct s_tris	list_tris[26];
}					t_map;

t_list			*read_tetri(int fd);
#endif