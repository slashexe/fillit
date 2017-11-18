/*
**applique une fonction donnée  à l'info  dans certain maillon
**
**@params *begin_list
**		liste fournie
**@params (*f)
**		fonction
*/

void	ft_list_foreach_if(t_list *begin_list,
		void (*f)(void *), void *data_ref, int (*cmp)())
{
	t_list	*current;

	current = begin_list;
	while (current)
	{
		if (cmp(current->data, data_ref) == 0)
			f(current->data);
		curr:ent = current->next;
	}
}