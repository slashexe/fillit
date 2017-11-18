/*
**@params *begin_list
**			liste fournie
**@params (*cmp)
**			fonction de comparaison
**@params *data_ref
**			data a comparer
**
**@return	l'adresse du premier maillon dont la donnée est égale a la 
**			donné de référence
*/

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	t_list	*current;

	current = begin_list;
	while (current)
	{
		if (cmp(current->data, data_ref) == 0)
			return (current);
		current = current->next;
	}
	return (NULL);
}