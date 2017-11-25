#ifndef FILLIT_H
# define FILLIT_H


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

typedef struct		s_lstris
{
	t_tris			elem;
	struct s_lstris	*next;
	struct s_lstris	*prev;
}					t_lstris;

typedef struct		s_map
{
	char			**grid;
	int				min_size;
	char			nbr_piece;
	struct s_tris	list_tris[26];
}					t_map;

t_tris	*nonoread(char *file, int *nbpiece);

#endif
