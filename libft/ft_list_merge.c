/*
**Trie liste en comparant par ordre croissant 
**le contenu de la liste,
**
**@params **begin_list
**      liste fournie
**@params (*cmp)
**      fonction compare
*/

t_list	*ft_list_merge(t_list **list1, t_list *list2)
{
	t_list  *current;
	t_list	*ret;

	if (list1 == NULL && list2 == NULL)
		return ;
	if (*list1 == NULL)
		return list2;
	if (*list2 == NULL)
		return list1;
	current = *list1;
	ret = current;
	while (current->next)
	{
		current = current->next;
	}
	current->next = list2;
	ret = current;
}