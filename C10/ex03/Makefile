# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: besellem <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/24 15:02:33 by besellem          #+#    #+#              #
#    Updated: 2020/08/24 15:02:34 by besellem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ft_hexdump
SRCS	+=	main.c
SRCS	+=	ft_checks.c
SRCS	+=	ft_libft.c
INCS	=	ft_hexdump.h
OBJS	=	$(SRCS:.c=.o)
CC		=	gcc
SANITF	=	-fsanitize=address
FLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f

all:
			@ $(CC) $(FLAGS) $(SRCS) -c
			@ $(CC) $(FLAGS) $(OBJS) -o $(NAME) -I $(INCS)

sanit:
			@ $(CC) $(FLAGS) $(SANITF) $(SRCS) -o $(NAME) -I $(INCS)

clean:
			@ $(RM) $(OBJS)

fclean:		clean
			@ $(RM) $(NAME)

re:			fclean all
