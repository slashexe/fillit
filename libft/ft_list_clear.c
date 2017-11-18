void	ft_list_clear(t_list **begin_list)
{
	while (*begin_list)
	{
		free(*begin_list);
		(*begin_list) = (*begin_list)->next;
	}
	*begin_list = NULL;
}