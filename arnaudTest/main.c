/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 21:10:57 by avinas            #+#    #+#             */
/*   Updated: 2017/11/29 14:46:58 by avinas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	t_tris		*pieces;
	t_tris		test[1];
	int			cpt;
	int			cptt;
	int			nbpiece;

	cpt = 0;
	cptt = 0;
	if (!(pieces = nonoread(argv[1], &nbpiece, 0, 0)))
		return (0);
	test[0] = pieces[0];
	pieces[1] = ft_driftup(test, pieces[1], nbpiece - 1);
	while (cptt < nbpiece)
	{
		while (cpt < 4)
		{
			printf("piece : %c x : %d y : %d\n", pieces[cptt].name,\
					pieces[cptt].coord[cpt].x, pieces[cptt].coord[cpt].y);
			cpt++;
		}
		printf("\n");
		cpt = 0;
		cptt++;
	}
}
