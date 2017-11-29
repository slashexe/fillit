#include "fillit.h"

t_tris	ft_driftup(t_tris *reso, t_tris src, int nbpiece)
{
	int	isedge;
	int	cptres;
	int cptsrc;
	int cptris;

	cptres = 0;
	cptsrc = 0;
	cptris = 0;
	isedge = 0;
	
	while (!isedge)
	{
		cptsrc = 0;
		while (cptsrc < 4)
		{
			cptris = 0;
			while(cptris < nbpiece)
			{
				cptres = 0;
				while(cptres < 4)
				{
					if ((reso[cptris].coord[cptres].y == src.coord[cptsrc].y - 1 \
					&& reso[cptris].coord[cptres].x == src.coord[cptsrc].x) \
					|| src.coord[cptsrc].y - 1 < 0)
					{

						isedge = 1;
					}
					cptres++;
				}
				cptris++;
			}
			cptsrc++;
		}
		if (!isedge)
		{
			cptres = -1;
			while (++cptres < 4)
				src.coord[cptres].y--;
		}
	}
	return (src);
}