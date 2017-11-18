void	ft_list_clear(t_list **begin_list)
{
	t_list	*list;
	t_list	*tmp;

	list = *begin_list;
	while (list)
	{
		if (list->next)
			tmp = list->next;
		else
			tmp = NULL;
		free(list);
		list = tmp;
	}
	*begin_list = NULL;
}