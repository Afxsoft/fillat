/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouloube <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 13:54:00 by aouloube          #+#    #+#             */
/*   Updated: 2015/12/10 16:52:08 by aouloube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct		s_shape
{
	char			*str;
	int				lenght;
	char			last_index;
}					t_shape;


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
		if (file[i] != '.' && file[i] != '#' && file[i] != '\n')
			ft_error("The character used is not allowed");
		buff[y][v] = file[i];
		if (file[i] == '\n' && file [i - 1] == '\n')
		{
			if (size == 1)
				ft_error("There is a return at the last element");
			else if (size == 1 && v != 18)
				ft_error("capout");
			y++;
			v = 0;
		}
		else
		{
			if (v > 20)
				ft_error("One or more tetraminos char is != 20");
			v++;
		}
		i++;
		size--;
	}
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

int		ft_diesechecker(char b[26][20])
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
		if (b[y][i] == '#')
			b[y][i] = y + 'A';		
		y = (i == 20) ? y + 1 : y;
		if (i == 19)
			if (count != 4)
				ft_error("# number is incorrect");
		count = (i == 20) ? 0 : count;
		i = (i == 20) ? 0 : i;
		i++;
	}
	return (y + 1);
}

void	ft_intab(int **tab, char b[26][20])
 {
	int		i;
	int		y;
	int		v;
	int		t;

	i = 0;
	y = 0;
	v = 0;
	while (b[y][i])
	{
		if (ft_isalpha(b[y][i]))
		{
			tab[y][v] = i;
			v++;
		}
		y = (i == 20) ? y + 1 : y;
		v = (i == 20) ? 0 : v;
		i = (i == 20) ? 0 : i;
		i++;
	}
}

void	ft_intaborder(int **intab, int size)
 {
	int		i;
	int		y;
	int		v;

	y = 0;
	while (y < size)
	{
		i = 0;
		v = 0;
		while (intab[y][i])
		{
			printf("[%d - %d]", i , intab[y][i]);
			if (i == 0 && intab[y][i] != 0)
				v = intab[y][i];
			intab[y][i] -= v;
		 i++;
		}
		y++;
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
		y = (i == 20) ? y + 1 : y;
		if (b[y][i] == '\n')
		{
			if (count != 5 && count != 1)
				ft_error("Number of Tretriminos is incorrect");
			count = 0;
		}
		i = (i == 20) ? 0 : i;
		i++;
	}
}

int		ft_sqr(int nb)
{
	int i;

	i = 1;
	while ((i * i) < nb)
		i++;
	return (i);
}

void	ft_shape(int **intab, int size)
{
	int		i;
	int		y;
	int		z;
	i = 0;
	y = 0;
	while (i < size)
	{
		y = 0;
		z = 1;
		while (y < 16)
		{
			if (intab[i][y] == y )
				ft_putchar('A');
			else 
				ft_putchar('.');
			
		/*if (z == 4)
		{
			ft_putchar('\n');
			z = 1;
		}
		else
			z++;*/
		y++;
			

		}
		i++;
	}
}

void	ft_solver(int **intab, int size)
{
	char f[1024];
	int i;
	int y;
	int z;
	int min;

	i = 0;
	y = 0;
	z = 0;
	min = ft_sqr(size * 4);
	while (i < size)
	{
		
		while (y < 4)
		{
		
			y++;
		}
		i++;
	}

}

void	ft_ttry(char buff[26][20])
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	while (buff[y][i])
	{
		if (i == 21)
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
	int		**intab;
	int		i;
	int 	size;

	if (argc == 2)
	{
		ft_readfile(file, open(argv[1], O_RDONLY));
		ft_tab2m(file, buff);
		ft_tchecker(buff);
		size = ft_diesechecker(buff);
		intab = (int **)malloc(sizeof(int *) * size);
		i = 0;
		while (i < size)
		{
			intab[i] = malloc(sizeof(int) * 4);
			i++;
		}
		ft_intab(intab, buff);
		ft_intaborder(intab, size);
		ft_shape(intab, size);
		ft_charchecker(buff);
		//ft_ttry(buff);
	}
	return (0);
}
