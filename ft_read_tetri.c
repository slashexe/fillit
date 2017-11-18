t_list	*read_tetri(int fd)
{
	char	*buff;
	t_list	*list;

	buff = ft_strnew(21);
	while (read(fd, &buff, 21) >= 20)
	{
		buff[1] = '\0';
		write(1, &buff, 1);
	}
	close(fd);
	return (0);
}