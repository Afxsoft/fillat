/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouloube <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 13:54:00 by aouloube          #+#    #+#             */
/*   Updated: 2015/12/08 17:27:43 by aouloube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

void	ft_error(char *msg)
{
	ft_putstr("Error : ");
	ft_putendl(msg);
	exit(0);
}

void	ft_readfile(char *file, int fd)
{
	char	tmp;
	int		i;

	i = 0;
	while (read(fd, &tmp, 1))
	{
		/*if (i == 20)
		{
			y++;
			i = 0;
		}
		else
		{
			if (tmp != '.' && tmp != '#' && tmp != '\n')
				ft_error("The character used is not allowed");
			buff[y][i] = tmp;
			printf("%c", tmp);
		}*/
		
			file[i] = tmp;
		i++;
	}
	file[i] = '\0';
}

void	ft_tab2m(char *file, char buff[26][20])
{
	int		i;
	int		y;
	int		v;
	int 	size;

	i = 0;
	y = 0;
	v = 0;
	size = ft_strlen(file);
	while (size > 0)
	{
		if (y == 0)
		if (file[i] != '.' && file[i] != '#' && file[i] != '\n')
			ft_error("The character used is not allowed");
		buff[y][v] = file[i];
		if (file[i] == '\n' && file [i - 1] == '\n')
		{
			y++;
			v = 0;
		}else
			v++;
		i++;
		size--;
	}
	printf("%s", buff[0]);
}

void	ft_tchecker(char b[26][20])
{
	int		i;
	int		y;
	int		count;
	int		t;

	i = 0;
	y = 0;
	count = 0;
	while (b[y][i])
	{
		t = (b[y][i] == '#' && count == 1) ? i : t;
		if (b[y][i] == '#' && count == 2)
		{
			if (t != i - 1 && t != i - 5 && b[y][i + 1] != '#' && \
					b[y][i - 4] != '#')
				ft_error("the block dont touch another block 11");
		}
		else if (b[y][i] == '#' && b[y][i - 1] != '#' && b[y][i + 1] != '#' \
				&& b[y][i - 5] != '#' && b[y][i + 5] != '#')
			ft_error("the block dont touch another block 22");
		count = (b[y][i] == '#') ? count + 1 : count;
		y = (i == 20) ? y + 1 : y;
		count = (i == 20) ? 0 : count;
		i = (i == 20) ? 1 : i + 1;
	}
}

void	ft_diesechecker(char b[26][20])
{
	int		i;
	int		y;
	int		count;
	int		t;

	i = 0;
	y = 0;
	count = 0;
	while (b[y][i])
	{
		count = (b[y][i] == '#') ? count + 1 : count;
		y = (i == 20) ? y + 1 : y;
		if (i == 19)
			if (count != 4)
				ft_error("# number is incorrect");
		count = (i == 20) ? 0 : count;
		i = (i == 20) ? 0 : i;
		i++;
	}
}

void	ft_charchecker(char b[26][20])
{
	int		i;
	int		y;
	int		count;
	int		t;

	i = 0;
	y = 0;
	count = 0;
	while (b[y][i])
	{
		count++;
		y = (i == 21) ? y + 1 : y;
		if (b[y][i] == '\n')
		{
			if (count != 5 && count != 1)
				ft_error("Number of Tretriminos is incorrect");
			count = 0;
		}
		i = (i == 21) ? 0 : i;
		i++;
	}
}

void	ft_ttry(char buff[26][20])
{
//	char	tab[4][5];
	int		i;
	int		y;

	i = 0;
	y = 0;
	
	//printf("%s", buff[1]);
	while (buff[y][i])
	{
		if (i == 21 )
		{
			i = 0;
			y++;
			}
		
		i++;
	}
}

int		main(int argc, char **argv)
{
	int		fd;
	char	file[560];
	char	buff[26][20];

	if (argc == 2)
	{
		ft_readfile(file, open(argv[1], O_RDONLY));
		//printf("%s", file);
		ft_tab2m(file, buff);
		printf("%s", buff[0]);
		//ft_tchecker(buff);
		//ft_diesechecker(buff);
		//ft_charchecker(buff);
		//ft_ttry(buff);
	}
	return (0);
}
