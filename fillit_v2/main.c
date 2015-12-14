/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouloube <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 13:29:09 by aouloube          #+#    #+#             */
/*   Updated: 2015/12/14 14:34:32 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = (unsigned char*)s;
	while (n > 0)
	{
		*p = 0;
		p++;
		n--;
	}
}

void	set_place(t_tetris *tab)
{
	int i;
	int j;

	i = 0;
	while (tab[i].form != NULL)
	{
		j = 0;
		while (tab[i].form[j] == '.')
			j++;
		tab[i].spot = j;
		i++;
	}
}

int		nb_of_pieces(t_tetris *tetris)
{
	int i;

	i = 0;
	while (tetris[i].form != NULL)
		i++;
	return (i);
}

int		main(int argc, char **argv)
{
	t_tetris	tab[26];
	t_result	res;

	ft_bzero(tab, 26 * sizeof(*tab));
	fill_with_points(&res);
	if (argc == 2)
	{
		read_file(argv[1], tab);
		res.min_size = ft_square(nb_of_pieces(tab) * 4);
		set_place(tab);
		ft_solve_tetris(&res, tab, 0);
	}
	exit_error(20);
}
