# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: besellem <besellem@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/18 20:02:29 by besellem          #+#    #+#              #
#    Updated: 2020/08/25 23:27:50 by besellem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ft_tail
SRCS	+=	main.c
SRCS	+=	ft_libft.c
SRCS	+=	ft_errors.c
SRCS	+=	ft_stdin_case.c
OBJS	=	$(SRCS:.c=.o)
INCS	=	ft_tail.h
CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f

all:
			@ $(CC) $(FLAGS) $(SRCS) -c
			@ $(CC) $(FLAGS) $(OBJS) -o $(NAME) -I $(INCS)

sanit:
			@ $(CC) $(FLAGS) -fsanitize=address -fno-omit-frame-pointer -o $(NAME) $(SRCS) -I $(INCS)

clean:
			@ $(RM) $(OBJS)

fclean:		clean
			@ $(RM) $(NAME)

re:			fclean all
