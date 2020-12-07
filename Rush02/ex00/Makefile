# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: besellem <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/23 08:53:24 by besellem          #+#    #+#              #
#    Updated: 2020/08/23 08:53:25 by besellem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	rush-02

SRCS	+=	main.c
SRCS	+=	funcs00.c
SRCS	+=	funcs01.c
SRCS	+=	ft_split.c
SRCS	+=	checks.c
SRCS	+=	fill_data.c
SRCS	+=	solve.c

OBJS	=	$(SRCS:.c=.o)

INCS	=	rush02.h

CC		=	gcc

FLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f


all:
			@ $(CC) $(FLAGS) $(SRCS) -c
			@ $(CC) $(FLAGS) $(OBJS) -o $(NAME) -I $(INCS)

sanit:
			@ $(CC) $(FLAGS) -fsanitize=address -o $(NAME) $(SRCS) -I $(INCS)

clean:
			@ $(RM) $(OBJS)

fclean:		clean
			@ $(RM) $(NAME)

re:			fclean all
