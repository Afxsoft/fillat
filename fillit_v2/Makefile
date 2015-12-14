#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlagache <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/10 14:17:09 by nlagache          #+#    #+#              #
#    Updated: 2015/12/14 10:00:36 by nlagache         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit

SRCS = main.c			\
	   functions.c		\
	   solve_tetris.c	\
	   if_valid.c		\
	   check_text.c		\
	   print.c			\

CFLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

$(NAME)	:	$(OBJS)
			gcc $(CFLAGS) -o $(NAME) $(OBJS)

all		:	$(NAME)

clean	:
			rm -rf $(OBJS)

fclean	:	clean
			rm -rf $(NAME)

re		:	fclean all