/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 18:10:52 by nlagache          #+#    #+#             */
/*   Updated: 2015/12/14 14:34:47 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_result
{
	char		tab[200];
	int			min_size;
}				t_result;

typedef struct	s_tetris
{
	char		*form;
	int			spot;
	int			last_try;
}				t_tetris;

int				coordinate_transformation(int i, t_result *res, t_tetris piece);
void			place_form(t_result *res, t_tetris piece);
void			delete_tetris(t_result *res, t_tetris tetris);
void			print_result(t_result *res);
int				ft_square(int nb);
void			fill_with_points(t_result *res);
t_tetris		*read_file(char *file, t_tetris *tab);
int				check_tetris(char *tetris);
void			exit_error(int error_nb);
char			get_first_diese(char *tetris, int x, int y);
void			ft_solve_tetris(t_result *res, t_tetris *tetris, int index);
int				ft_fit_tetris(t_result *res, t_tetris *piece);

#endif
