/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nonoread.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 21:16:43 by avinas            #+#    #+#             */
/*   Updated: 2017/11/29 14:57:38 by avinas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
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
		if (isvalide(buff) == 0)
			return (-1);
	}
	close(fd);
	return (cptris);
}

t_tris	*nonoread(char *file, int *nbpiece, int cpt, int pos)
{
	int		fd;
	char	buff[BUFF_SIZE + 1];
	t_tris	*tris;

	tris = NULL;
	*nbpiece = countris(file);
	if (*nbpiece == -1)
		ft_putstr("error\n");
	else
	{
		fd = open_file(file);
		if (!(tris = (t_tris*)malloc(sizeof(t_tris) * *nbpiece)))
			return (NULL);
		while ((pos = read(fd, buff, BUFF_SIZE)))
		{
			buff[pos] = '\0';
			tris[cpt] = *getris(buff, cpt);
			(tris[cpt].name == '0') ? ft_putstr("error\n") : 0;
			if (tris[cpt++].name == '0')
				return (NULL);
		}
		close(fd);
	}
	return (tris);
}
