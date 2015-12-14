/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouloube <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 10:18:46 by aouloube          #+#    #+#             */
/*   Updated: 2015/12/14 14:00:43 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*read_one(int fd, int index)
{
	char	buf[20];
	int		i;
	int		len;
	char	*res;

	len = read(fd, buf, 20);
	i = 0;
	if (len < 20)
		exit_error(7);
	res = (char *)malloc(17 * sizeof(*res));
	while (i < len)
	{
		if (buf[i] != '\n' && buf[i] != '.' && buf[i] != '#')
			exit_error(1);
		if (buf[i] == '#')
			res[i - (i / 5)] = index + 'A';
		else if ((buf[i] == '\n') && ((i % 5) != 4))
			exit_error(2);
		else
			res[i - (i / 5)] = '.';
		i++;
	}
	res[i - (i / 5)] = '\0';
	check_tetris(res);
	return (res);
}

t_tetris	*read_file(char *file, t_tetris *tab)
{
	int		i;
	int		fd;
	char	buf[1];

	fd = open(file, O_RDONLY);
	tab[0].form = read_one(fd, 0);
	tab[0].last_try = -1;
	i = 1;
	while (read(fd, buf, 1))
	{
		if (*buf != '\n')
			exit_error(10);
		tab[i].form = read_one(fd, i);
		tab[i].last_try = -1;
		i++;
	}
	close(fd);
	check_tetris(tab[0].form);
	return (tab);
}
