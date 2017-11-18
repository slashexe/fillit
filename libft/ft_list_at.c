/*
**renvoie le n-ième élément de la liste
**
**@params *begin_list
**		liste fournie
**@params nbr
**		numéro a delete
**
**@return la list a jour
*/

t_list	*ft_lsit_at(t_list *begin_list, unsigned int nbr)
{
	t_list	*elem;
	int		size;

	size = ft_list_size(begin_list);
	if (nbr < 0 || nbr > size)
		return (NULL);
	elem = begin_list;
	while (nbr--)
		elem = elem->next;
	return (elem);
}