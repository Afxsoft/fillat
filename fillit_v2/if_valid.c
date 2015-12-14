/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouloube <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 10:20:12 by aouloube          #+#    #+#             */
/*   Updated: 2015/12/14 15:08:48 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		count_diese(char *tetris)
{
	int i;
	int diese;

	i = 0;
	diese = 0;
	while (i < 16)
	{
		if (tetris[i] != '.')
			diese++;
		i++;
	}
	return (diese);
}

int		check_form(char *tetris, int x, int y, int direction)
{
	if (get_first_diese(tetris, x, y) != '.')
	{
		if (direction == 0)
			return (1 + check_form(tetris, x + 1, y, 1) +
					check_form(tetris, x - 1, y, -1)
					+ check_form(tetris, x, y + 1, 0));
		else if (direction == 1)
			return (1 + check_form(tetris, x + 1, y, 1) +
					check_form(tetris, x, y + 1, 0));
		else if (direction == -1)
			return (1 + check_form(tetris, x - 1, y, -1) +
					check_form(tetris, x, y + 1, 0));
	}
	return (0);
}

int		check_tetris(char *tetris)
{
	int x;
	int y;

	if (count_diese(tetris) != 4)
		exit_error(3);
	x = 0;
	y = 0;
	while (get_first_diese(tetris, x, y) == '.')
	{
		x++;
		if (x == 4)
		{
			x = 0;
			y++;
		}
	}
	if (check_form(tetris, x, y, 1) < 4)
		exit_error(4);
	return (0);
}
