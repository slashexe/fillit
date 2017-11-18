/*
**Trie liste en comparant par ordre croissant 
**le contenu de la liste,
**
**@params **begin_list
**      liste fournie
**@params (*cmp)
**      fonction compare
*/

void    ft_list_sort(t_list **begin_list, int (*cmp)())
{
    t_list  *current;
    int     link;

    link = 1;
    if (*begin_list == NULL)
        return ;
    current = *begin_list;
    while (link)
    {
        link = 0;
        current = *begin_list;
        while (current->next)
        {
            if (cmp(current->data, current->next->data) > 0)
            {
                ft_ptrswap(&current->data, &current->next->data);
                link = 1;
            }
            current = current->next;
        }
    }
}