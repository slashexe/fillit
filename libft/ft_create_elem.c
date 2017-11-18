t_list	*ft_create_elem(void *data)
{
	t_list *elem;

	elem = NULL;
	elem = (t_list*)malloc(sizeof(t_list))
	if (elem)
	{
		elem->next = NULL;
		elem->data = data;
	}
	return (elem);
}