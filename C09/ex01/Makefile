# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: besellem <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/17 10:09:40 by besellem          #+#    #+#              #
#    Updated: 2020/08/17 10:09:42 by besellem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
INCS	=	includes
SRCS	=	srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c \
			srcs/ft_strlen.c srcs/ft_strcmp.c
OBJS	=	${SRCS:.c=.o}
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
LIBC	=	ar rc
LIBR	=	ranlib
RM		=	rm -f

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCS}

${NAME}:	${OBJS}
			${LIBC} ${NAME} ${OBJS}
			${LIBR} ${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all
