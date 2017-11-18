/*
**Echange le contenue de 2 pointeurs
*/

void    ft_ptrswap(void **s1, void **s2)
{
    void    *tmp;

    tmp = *s2;
    *s2 = *s1;
    *s1 = tmp;
}