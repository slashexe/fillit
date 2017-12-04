/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkfile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 17:55:03 by avinas            #+#    #+#             */
/*   Updated: 2017/11/29 14:56:17 by avinas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tris	*norm_getris(t_point *tabpoint, int name, t_tris *ret)
{
	int cpt;

	cpt = -1;
	while (cpt++ < 3)
		ret->coord[cpt] = tabpoint[cpt];
	ret->name = 'A' + name;
	//printf("x : %d | y : %d\n", ret->coord[0].x, ret->coord[0].y);
	return (ret);
}

t_tris	*getris(char *line, int name)
{
	int		cptx;
	int		cpty;
	int		cptpoint;
	t_point	tabpoint[4];
	t_tris	*ret;

	cptx = 0;
	cpty = 0;
	cptpoint = 0;
	if (!(ret = (t_tris*)malloc(sizeof(t_tris))))
		return (NULL);
	while (*line)
	{
		(*line == '#' && cptpoint < 4) ? tabpoint[cptpoint].x = cptx : 0;
		(*line == '#' && cptpoint < 4) ? tabpoint[cptpoint++].y = cpty : 0;
		(*line == '#' && cptpoint > 4) ? ret->name = '0' : 0;
		if (*line == '#' && cptpoint > 4)
			return (ret);
		cptx++;
		(*line == '\n') ? cpty++ : 0;
		(*line++ == '\n') ? cptx = 0 : 0;
	}
	(cptpoint < 4) ? ret->name = '0' : 0;
	if (cptpoint < 4)
		return (ret);
	return (norm_getris(tabpoint, name, ret));
}

int		norm_isvalide(char *line, int x, int *y)
{
	if (line[x + *y * 5] == '#')
	{
		if (line[x + 1 + *y * 5] != '#' && line[x - 1 + *y * 5] != '#' &&\
		line[x + (*y + 1) * 5] != '#' && line[x + (*y - 1) * 5] != '#')
			return (0);
	}
	else if (line[x + *y * 5] != '.' && line[x + *y * 5] != '\n')
		return (0);
	return (1);
}

int		isvalide(char *line)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (line[x + y * 5])
	{
		if (norm_isvalide(line, x, &y) == 0)
			return (0);
		x++;
		if (line[x + y * 5] == '\n')
		{
			if (x < 4 || x > 4)
				return (0);
			x = 0;
			y++;
		}
		if (x > 4 || y > 4)
			return (0);
	}
	return (1);
}
