/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_tetris.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 14:24:51 by nlagache          #+#    #+#             */
/*   Updated: 2015/12/14 14:36:24 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_solve_tetris(t_result *res, t_tetris *tetris, int index)
{
	if (tetris[index].form == NULL)
	{
		print_result(res);
		exit(0);
	}
	else
	{
		while (ft_fit_tetris(res, &tetris[index]))
		{
			ft_solve_tetris(res, tetris, index + 1);
			delete_tetris(res, tetris[index]);
		}
		tetris[index].last_try = -1;
		if (index == 0)
		{
			res->min_size++;
			ft_solve_tetris(res, tetris, index);
		}
	}
}

int		coordinate_transformation(int i, t_result *res, t_tetris piece)
{
	return (((i % 4) - (piece.spot % 4))
			+ (((i / 4) - (piece.spot / 4)) * res->min_size)
			+ piece.last_try);
}

char	get_value_in_res(int i, t_result *res, t_tetris piece)
{
	int x;

	x = coordinate_transformation(i, res, piece);
	if (x >= (res->min_size * res->min_size))
		return ('#');
	if ((x % res->min_size) >
		(coordinate_transformation(piece.spot, res, piece) % res->min_size))
	{
		if ((i % 4 < piece.spot % 4))
			return ('#');
	}
	else if (i % 4 > piece.spot % 4)
		return ('#');
	return (res->tab[coordinate_transformation(i, res, piece)]);
}

int		fits_in(t_result *res, t_tetris piece)
{
	int i;

	i = piece.spot;
	while (i < 16)
	{
		if (piece.form[i] != '.')
		{
			if (get_value_in_res(i, res, piece) != '.')
			{
				return (0);
			}
		}
		i++;
	}
	return (1);
}

int		ft_fit_tetris(t_result *res, t_tetris *piece)
{
	piece->last_try++;
	if (piece->last_try < (res->min_size * res->min_size))
	{
		if (fits_in(res, *piece))
		{
			place_form(res, *piece);
			return (1);
		}
		else
			return (ft_fit_tetris(res, piece));
	}
	else
	{
		piece->last_try = -1;
		return (0);
	}
}
