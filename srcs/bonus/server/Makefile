# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/14 22:56:24 by abahmani          #+#    #+#              #
#    Updated: 2021/10/25 16:19:50 by abahmani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=		server_bonus

SRCS	=		server_bonus.c

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