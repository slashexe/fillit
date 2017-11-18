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

void	ft_list_reverse(t_list **begin_list)
{
	if (!*begin_list)
		return ;
	ft_list_rev(*begin_list, NULL, begin_list);
}

void	ft_list_rev(t_list *current, t_list *prev, t_list **list)
{
	t_list *next;

	if (!current->next)
	{
		*list = current;
		current->next = prev;
		return ;
	}
	next = current->next;
	current->next = prev;
	ft_list_rev(next, current, list);
}
