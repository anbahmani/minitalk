# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/06 14:57:23 by abahmani          #+#    #+#              #
#    Updated: 2021/10/23 16:28:11 by abahmani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=		client

SRCS	=		client.c
				

OBJS	=	${SRCS:.c=.o}

INCS	=	-I ../../includes

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f
				
${NAME}:	${OBJS}
			${MAKE} -C ../../libft
			${MAKE} -C ../../ft_printf
			${CC} ${CFLAGS} ${INCS} $^ -o $@ ../../libft/libft.a ../../ft_printf/libftprintf.a
				
all:		${NAME}

.c.o:
			${CC} ${CFLAGS} ${INCS} -c $< -o $@


clean:
			${MAKE} -C ../../libft clean
			${MAKE} -C ../../ft_printf clean
			${RM} ${OBJS}

fclean:		clean
			${MAKE} -C ../../libft fclean
			${MAKE} -C ../../ft_printf fclean
			${RM} ${NAME}

re:             fclean all

.PHONY:         all clean fclean re