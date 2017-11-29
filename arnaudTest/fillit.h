/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:56:39 by avinas            #+#    #+#             */
/*   Updated: 2017/11/29 14:57:00 by avinas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

t_tris				*nonoread(char *file, int *nbpiece, int cpt, int pos);
int					isvalide(char *line);
t_tris				*getris(char *line, int name);

#endif
