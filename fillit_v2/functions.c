/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouloube <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 11:38:16 by aouloube          #+#    #+#             */
/*   Updated: 2015/12/14 14:32:11 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	get_first_diese(char *tetris, int x, int y)
{
	if ((x >= 4) || (y >= 4) || (x < 0) || (y < 0))
		return ('.');
	else
		return (tetris[x + (y * 4)]);
}

int		ft_square(int nb)
{
	int i;

	i = 1;
	while ((i * i) < nb)
		i++;
	return (i);
}

void	exit_error(int error_nb)
{
	write(1, "error\n", 6);
	exit(error_nb);
}

void	fill_with_points(t_result *res)
{
	int i;

	i = 0;
	while (i < 200)
	{
		res->tab[i] = '.';
		i++;
	}
}
