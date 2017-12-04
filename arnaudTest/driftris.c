#include "fillit.h"

t_tris	ft_drift_ul(t_tris *reso, t_tris src, int nbpiece)
{
	int isedge_y;
	int isedge_x;
	int cptres;
	int cptsrc;
	int cptcoord;
	int cptresocoord;

	isedge_x = 0;
	isedge_y = 0;
	while (!isedge_x || !isedge_y)
	{
		cptres = 0;
		while (cptres < nbpiece)
		{
			cptresocoord = 0;
			while (cptresocoord < 4)
			{
				cptcoord = 0;
				while (cptcoord < 4)
				{
					if ((reso[cptres].coord[cptresocoord].x == src.coord[cptcoord].x - 1 \
					&& reso[cptres].coord[cptresocoord].y == src.coord[cptcoord].y) \
					|| (reso[cptres].coord[cptresocoord].x == src.coord[cptcoord].x - 1 \
					&& reso[cptres].coord[cptresocoord].y == src.coord[cptcoord].y - 1) \
					|| src.coord[cptcoord].x - 1 < 0)
					{
						isedge_x = 1;
						printf("x point : %c %c \nreso.x = %d | src.x = %d\nreso.y = %d | src.y = %d\n\n",src.name ,reso[cptres].name, \ 
						reso[cptres].coord[cptresocoord].x, \
						src.coord[cptcoord].x,\
						reso[cptres].coord[cptresocoord].y,\
						src.coord[cptcoord].y);
					}
					if ((reso[cptres].coord[cptresocoord].y == src.coord[cptcoord].y - 1 \
					&& reso[cptres].coord[cptresocoord].x == src.coord[cptcoord].x) \
					|| src.coord[cptcoord].y - 1 < 0)
					{
						printf("y point : %c %c\nreso.x = %d | src.x = %d\nreso.y = %d | src.y = %d\n\n",src.name ,reso[cptres].name, \ 
						reso[cptres].coord[cptresocoord].x, \
						src.coord[cptcoord].x,\
						reso[cptres].coord[cptresocoord].y,\
						src.coord[cptcoord].y);
						isedge_y = 1;
					}
					cptcoord++;
				}
				cptresocoord++;
			}
			cptres++;
		}
		if (!isedge_x)
		{
			cptcoord = -1;
			while (++cptcoord < 4)
				src.coord[cptcoord].x--;
		}
		if (!isedge_y)
		{
			cptcoord = -1;
			while (++cptcoord < 4)
				src.coord[cptcoord].y--;
		}
		if (isedge_x != isedge_y)
		{
			isedge_x = 0;
			isedge_y = 0;
		}
	}
	return (src);
}

t_tris	ft_driftz(t_tris src)
{
	int	cptcoord;
	int min_x;
	int min_y;

	cptcoord = 0;
	min_x = src.coord[cptcoord].x;
	min_y = src.coord[cptcoord].y;
	while (cptcoord < 4)
	{
		if (min_x > src.coord[cptcoord].x)
			min_x = src.coord[cptcoord].x;
		if (min_y > src.coord[cptcoord].y)
			min_y = src.coord[cptcoord].y;
		cptcoord++;
	}
	cptcoord = 0;
	while (cptcoord < 4)
	{
		src.coord[cptcoord].x -= min_x;
		src.coord[cptcoord].y -= min_y;
		cptcoord++;
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
		src.coord[cptcoord].x += max_x + 1;
		src.coord[cptcoord].y += max_y;
		cptcoord++;
	}
	return (src);
}








































