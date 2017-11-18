/*
**@params ac
**		nombre de av
**@params **av
**	chaine de caractere a passer dans la liste
**
**@return la nouvelle list cree
*/

t_list	*ft_list_push_params(int ac, char **av)
{
	t_list	*list;
	int		i;

	i = 1;
	if (ac < 1)
		return (NULL);
	list = ft_create_elem(av[0]);
	while (i < ac)
		ft_list_push_front(&list, av[i++]);
	return (list);
}