/*
**applique une fonction donnée  à l'info  de chaque maillon
**
**@params *begin_list
**		liste fournie
**@params (*f)
**		fonction
*/

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list	*current;

	current = begin_list;
	while (current)
	{
		f(current->data);
		current = current->next;
	}
}