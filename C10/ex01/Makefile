# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: besellem <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/18 18:58:47 by besellem          #+#    #+#              #
#    Updated: 2020/08/18 18:58:48 by besellem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ft_cat
SRC		=	main.c
OBJS	=	$(SRC:.c=.o)
CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f

all:
			@ $(CC) $(FLAGS) $(SRC) -c
			@ $(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
			@ $(RM) $(OBJS)

fclean:		clean
			@ $(RM) $(NAME)

re:			fclean all
