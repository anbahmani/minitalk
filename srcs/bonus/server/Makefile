# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/14 22:56:24 by abahmani          #+#    #+#              #
#    Updated: 2021/10/24 20:40:55 by abahmani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=		server

SRCS	=		server_bonus.c

OBJS	=	${SRCS:.c=.o}

INCS	=	-I ../../includes

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f
				
${NAME}:	${OBJS}
			${MAKE} -C ../../libft
			${CC} ${CFLAGS} ${INCS} $^ -o $@ ../../libft/libft.a
				
all:		${NAME}

.c.o:
			${CC} ${CFLAGS} ${INCS} -c $< -o $@


clean:
			${MAKE} -C ../../libft clean
			${RM} ${OBJS}

fclean:		clean
			${MAKE} -C ../../libft fclean
			${RM} ${NAME}

re:             fclean all

.PHONY:         all clean fclean re