#include "../include/libft.h"
#include "../include/fillit.h"

t_conf	*open_file(char *file, t_conf *conf)
{
	int		fd;

	fd = open(file, O_DIRECTORY);
	if (fd >= 0)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	if ((conf = read_file(&fd, conf)) == 0)
		return (NULL);
	return (conf);
}

t_conf	*read_file(int *fd, t_conf *conf)
{
	char	*buff;
	int		i;
	t_tris	*tetris;
	int		lastRead;
	int		reading;

	i = 0;
	lastRead = -1;
	buff = ft_strnew(21);
	while ((reading = read(*fd, buff, 21)))
	{
		lastRead = reading;
		tetris = create_tris(buff, i);
		if (tetris == NULL)
			return (NULL);
		conf->nbr_piece = i + 1;
		conf->list_tris[i++] = *tetris;
	}
	if (lastRead != 20 || reading != 0)
		return (NULL);
	return (conf);
}