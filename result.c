/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouloube <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 11:48:14 by aouloube          #+#    #+#             */
/*   Updated: 2015/12/11 14:13:49 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_result(t_result *res)
{
	int i;

	i = 0;
	while (i < res->size)
	{
		write(1, res->tab + (i * res->size), res->size);
		write(1, "\n", 1);
		i++;
	}
}

void	delete_tetris(t_result *res, t_tetris tetris)
{
	int i;

	i = 0;
	while (i < (res->size * res->size))
	{
		if (res->tab[i] == tetris.shape[tetris.place])
			res->tab[i] = '.';
		i++;
	}
}

void	put_piece(t_result *res, t_tetris piece)
{
	int i;

	i = piece.place;
	while (i < 16)
	{
		if (piece.shape[i] != '.')
			res->tab[coordinate_transformation(i, res, piece)] = piece.shape[i];
		i++;
	}
}
