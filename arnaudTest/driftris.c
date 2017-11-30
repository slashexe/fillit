#include "fillit.h"

void	normedriftup(t_tris *reso, t_tris src, int nbpiece, int *isedge, int cptres)
{
	int cptsrc;
	int cptris;

	cptsrc = 0;
	cptris = 0;
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
					*isedge = 1;
				cptres++;
			}
			cptris++;
		}
		cptsrc++;
	}
}

void	normedriftleft(t_tris *reso, t_tris src, int nbpiece, int *isedge, int cptres)
{
	int cptsrc;
	int cptris;

	cptsrc = 0;
	cptris = 0;
	while (cptsrc < 4)
	{
		cptris = 0;
		while(cptris < nbpiece)
		{
			cptres = 0;
			while(cptres < 4)
			{
				if ((reso[cptris].coord[cptres].x == src.coord[cptsrc].x - 1 \
				&& reso[cptris].coord[cptres].y == src.coord[cptsrc].y) \
				|| src.coord[cptsrc].x - 1 < 0)
					*isedge = 1;
				cptres++;
			}
			cptris++;
		}
		cptsrc++;
	}
}

t_tris	ft_driftup(t_tris *reso, t_tris src, int nbpiece)
{
	int	isedge;
	int	cptres;

	cptres = 0;
	isedge = 0;
	if (nbpiece < 1)
	{
		while (!isedge)
		{
			while (cptres < 4)
			{
				if (src.coord[cptres].y - 1 > 0)
				{
					isedge = 1;
				}
				cptres++;
			}
			if (!isedge)
			{
				cptres = -1;
				while (++cptres < 4)
					src.coord[cptres].y--;
			}
		}
	}
	else
	{
		while (!isedge)
		{
			normedriftup(reso, src, nbpiece, &isedge, cptres);
			if (!isedge)
			{
				cptres = -1;
				while (++cptres < 4)
					src.coord[cptres].y--;
			}
		}
	}
	return (src);
}

t_tris	ft_driftleft(t_tris *reso, t_tris src, int nbpiece)
{
	int	isedge;
	int	cptres;

	cptres = 0;
	isedge = 0;
	
	if (nbpiece < 1)
	{
		while (!isedge)
		{
			while (cptres < 4)
			{
				if (src.coord[cptres].x - 1 > 0)
				{
					isedge = 1;
				}
				cptres++;
			}
			if (!isedge)
			{
				cptres = -1;
				while (++cptres < 4)
					src.coord[cptres].x--;
			}
		}
	}
	else
	{
		while (!isedge)
		{
			normedriftleft(reso, src, nbpiece, &isedge, cptres);
			if (!isedge)
			{
				cptres = -1;
				while (++cptres < 4)
					src.coord[cptres].x--;
			}
		}
	}
	return (src);
}

t_tris	ft_driftright(t_tris *reso, t_tris src, int nbpiece)
{
	int cptreso;
	int	cptcoord;
	int max_x;
	int max_y;

	cptreso = 0;
	cptcoord = 0;
	max_x = 0;
	max_y = 0;
	while (cptreso < nbpiece)
	{
		cptcoord = 0;
		while (cptcoord < 4)
		{
			if (max_x < reso[cptreso].coord[cptcoord].x)
				max_x = reso[cptreso].coord[cptcoord].x;
			if (max_y < reso[cptreso].coord[cptcoord].y)
				max_y = reso[cptreso].coord[cptcoord].y;
			cptcoord++;
		}
		cptreso++;
	}
	cptcoord = 0;
	while (cptcoord < 4)
	{
		src.coord[cptcoord].x += max_x;
		src.coord[cptcoord].y += max_y;
		cptcoord++;
	}
	return (src);
}
























































