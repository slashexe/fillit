#include "fillit.h"
/*
int		reso(t_tris ret, t_tris *pieces, int nbpiece, int size, int iter);
{
	if (iter == nbpiece)
		return (0);
	test[0] = ft_driftz(pieces[0]);
	pieces[iter] = ft_driftright(test, pieces[iter], iter - 1);
	test[iter] = ft_drift_ul(test, pieces[iter], iter - 1);
	if (ft_get_size(test, test[nbpiece], nbpiece - 1) <= size)
		return (0);
	if (reso(ret, pieces, nbpiece, size, iter + 1))
		return (1);
	return (1);
}

t_tris	*resolve(t_tris *pieces, int nbpiece);
{
	t_tris	*ret;
	int		size;
	int		cpt;
	int		actuel;
	int		nbret;

	size = 2;
	cpt = 0;
	actuel = 0;
	if (!(ret = (t_tris*)malloc(sizeof(t_tris) * nbpiece)))
		return (0);
	size = 3;
	while (cpt < nbret)
	{
		ret[cpt] = pieces[actual]; 
		cpt++;
		if(size)
	}
	reurn (ret);
}*/

t_tris	*resolve(t_tris *pieces, int nbpiece)
{
	int		cpta;
	int		cptb;
	int		cpt;
	t_tris	tmp;
	t_tris	*tab;
	t_duo	temp;
	t_duo	*ret;

	cpt = 0;
	cpta = 0;
	cptb = 1;
	if (!(ret = (t_duo*)malloc(sizeof(t_duo) * nbpiece * (nbpiece - 1))))
		return (0);
	if (!(tab = (t_tris*)malloc(sizeof(t_tris) * 2)))
		return (0);
	while (cpta < nbpiece)
	{
		cptb = 0;
		while (cptb < nbpiece)
		{
			if (cpta != cptb)
			{
				tab[0] = tmp;
				tab[1] = tmp;
				tab[0] = ft_driftz(pieces[cpta]);
				tab[1] = ft_drift_ul(tab, pieces[cptb], 1);
				temp.a = tab[0];
				temp.b = tab[1];
				temp.size = ft_get_size(tab, 2);
				ret[cpt] = temp;
				cpt++; 
			}
			cptb++;
		}
		cpta++;
	}
	return (tab);
}










