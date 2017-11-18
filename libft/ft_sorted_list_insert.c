/*
**Trie liste en comparant par ordre croissant 
**le contenu de la liste,
**
**@params **begin_list
**      liste fournie
**@params (*cmp)
**      fonction compare
*/

void    ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
    t_list  *current;

    ft_push_back(begin_list, data);
    current = *begin_list;
    ft_list_sort(&current, cmp);
}