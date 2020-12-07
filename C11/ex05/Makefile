# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: besellem <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/18 14:55:52 by besellem          #+#    #+#              #
#    Updated: 2020/08/18 14:55:54 by besellem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	do-op
SRCS	=	main.c fun.c
OBJS	=	${SRCS:.c=.o}
INCL	=	do_op.h
CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f

all:
			@ ${CC} ${FLAGS} ${SRCS} -c
			@ ${CC} ${FLAGS} ${OBJS} -o ${NAME} -I ${INCL}

clean:
			@ ${RM} ${OBJS}

fclean:		clean
			@ ${RM} ${NAME}

re:			fclean all
