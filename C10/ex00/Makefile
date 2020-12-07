# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: besellem <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/18 18:51:13 by besellem          #+#    #+#              #
#    Updated: 2020/08/18 18:51:14 by besellem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ft_display_file
SRC		=	main.c
OBJ		=	$(SRC:.c=.o)
CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f

all:
			@ $(CC) $(FLAGS) $(SRC) -c
			@ $(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
			@ $(RM) $(OBJ)

fclean:		clean
			@ $(RM) $(NAME)

re:			fclean all
