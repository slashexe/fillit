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
	t_tris		*test;
	int			cpt;
	int			cptt;
	int			nbpiece;
	int			nbtest;

	cpt = 0;
	cptt = 0;
	nbtest = 0;
	if (!(pieces = nonoread(argv[1], &nbpiece, 0, 0)))
		return (0);
	if (!(test = (t_tris*)malloc(sizeof(t_tris) * nbpiece)))
		return (0);
	while (cpt < nbpiece)
	{
		pieces[cpt] = ft_driftright(test, pieces[cpt], nbtest);
		pieces[cpt] = ft_driftup(test, pieces[cpt], nbtest);
		test[cpt] = ft_driftleft(test, pieces[cpt], nbtest);
		cpt++;
		nbtest++;
	}
	ft_get_grid(pieces, ft_get_size(test, pieces[cpt], nbtest), nbpiece - 1);
	cpt = 0;
	cptt = 0;
	while (cptt < nbpiece)
	{
		while (cpt < 4)
		{
			printf("piece : %c x : %d y : %d\n", test[cptt].name,\
					test[cptt].coord[cpt].x, test[cptt].coord[cpt].y);
			cpt++;
		}
		printf("\n");
		cpt = 0;
		cptt++;
	}
	cpt = 0;
	cptt = 0;
/*
	printf("%s\n", "__________________________________________________________");

	test[0] = pieces[0];
	pieces[1] = ft_driftright(test, pieces[1], nbpiece - 1);
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
	printf("%s\n", "__________________________________________________________");
	pieces[1] = ft_driftup(test, pieces[1], nbpiece - 1);
	pieces[1] = ft_driftleft(test, pieces[1], nbpiece - 1);*/
	return (0);
	
}
