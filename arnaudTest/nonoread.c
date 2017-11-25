/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nonoread.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 21:16:43 by avinas            #+#    #+#             */
/*   Updated: 2017/11/23 18:08:13 by avinas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "fillit.h"

#define BUFF_SIZE 21

int		open_file(char *file)
{
	int		fd;

	fd = open(file, O_DIRECTORY);
	if (fd >= 0)
		return (0);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	return (fd);
}

t_tris	getris(char *line, int name)
{
	int		cptx;
	int		cpty;
	int		cptpoint;
	t_point	tabpoint[4];
	t_tris	ret;

	cptx = 0;
	cpty = 0;
	cptpoint = 0;
	while (*line)
	{
		(*line == '#' && cptpoint < 4) ? tabpoint[cptpoint].x = cptx : 0;
		(*line == '#' && cptpoint < 4) ? tabpoint[cptpoint++].y = cpty : 0;
		if (*line == '#' && cptpoint > 4)
			return (ret);
		cptx++;
		(*line == '\n') ? cpty++ : 0;
		(*line == '\n') ? cptx = 0 : 0;
		line++;
	}
	if (cptpoint < 3)
		return (ret);
	cptx = -1;
	while (cptx++ < 3)
	{
		ret.coord[cptx] = tabpoint[cptx];
	}
	ret.name = 'A' + name;
	return (ret);
}

int		countris(char *file)
{
	char	buff[BUFF_SIZE + 1];
	int		fd;
	int		pos;
	int		cptris;

	cptris = 0;
	fd = open_file(file);
	while ((pos = read(fd, buff, BUFF_SIZE)))
	{
		buff[pos] = '\0';
		cptris++;
	}
	close(fd);
	return (cptris);
}

t_tris	*nonoread(char *file, int *nbpiece)
{
	int		fd;
	int		pos;
	int		cpt;
	char	buff[BUFF_SIZE + 1];
	t_tris	*tris;

	*nbpiece = countris(file);
	fd = open_file(file);
	cpt = 0;
	if (!(tris = (t_tris*)malloc(sizeof(t_tris) * *nbpiece)))
		return (NULL);
	while ((pos = read(fd, buff, BUFF_SIZE)))
	{
		buff[pos] = '\0';
		tris[cpt] = getris(buff, cpt);
		cpt++;
	}
	close(fd);
	return (tris);
}
