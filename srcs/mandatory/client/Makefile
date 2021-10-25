# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/06 14:57:23 by abahmani          #+#    #+#              #
#    Updated: 2021/10/25 15:25:40 by abahmani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=		client

SRCS	=		client.c
				

OBJS	=	${SRCS:.c=.o}

INCS	=	-I ../../includes

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

all:		${NAME}

${NAME}:	${OBJS}
			${MAKE} -C ../../libft
			${CC} ${CFLAGS} ${INCS} $^ -o $@ ../../libft/libft.a
			
				
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