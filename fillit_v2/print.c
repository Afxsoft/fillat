/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouloube <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 11:48:14 by aouloube          #+#    #+#             */
/*   Updated: 2015/12/14 14:37:20 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_result(t_result *res)
{
	int i;

	i = 0;
	while (i < res->min_size)
	{
		write(1, res->tab + (i * res->min_size), res->min_size);
		write(1, "\n", 1);
		i++;
	}
}

void	delete_tetris(t_result *res, t_tetris tetris)
{
	int i;

	i = 0;
	while (i < (res->min_size * res->min_size))
	{
		if (res->tab[i] == tetris.form[tetris.spot])
			res->tab[i] = '.';
		i++;
	}
}

void	place_form(t_result *res, t_tetris piece)
{
	int i;

	i = piece.spot;
	while (i < 16)
	{
		if (piece.form[i] != '.')
			res->tab[coordinate_transformation(i, res, piece)] = piece.form[i];
		i++;
	}
}
