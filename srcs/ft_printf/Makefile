 # **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/27 13:46:11 by abahmani          #+#    #+#              #
#    Updated: 2021/03/27 14:08:10 by abahmani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRCS	=	ft_printf.c check.c conv_c.c conv_id.c conv_p.c conv_per.c conv_s.c\
			conv_u.c conv_x.c init.c ft_isdigit.c ft_isprint.c \
			ft_strlen.c conv_n.c use_buffer.c

OBJS	=	${SRCS:.c=.o}

CC		=	clang

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
		ar -rc ${NAME} ${OBJS}
		ranlib ${NAME}

all:		${NAME}

clean:			
	${RM} ${OBJS}

fclean:		clean			
		${RM} ${NAME}

re:			fclean all

.PHONY: 	all clean fclean re