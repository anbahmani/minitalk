# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abahmani <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/16 14:49:32 by abahmani          #+#    #+#              #
#    Updated: 2021/01/16 14:52:52 by abahmani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

INCS	=	includes 

SRCS	= ft_memset.c ft_bzero.c ft_memcpy.c \
		  ft_memccpy.c ft_memmove.c ft_memchr.c\
		  ft_memcmp.c ft_strlen.c ft_isalpha.c\
		  ft_isdigit.c ft_isalnum.c ft_isalnum.c\
		  ft_isascii.c ft_isprint.c ft_toupper.c\
		  ft_tolower.c ft_strchr.c ft_strrchr.c\
		  ft_strncmp.c ft_strlcpy.c ft_strlcat.c\
		  ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c\
		  ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c\

OBJS	=	${SRCS:.c=.o}

CC	=	gcc

CFLAGS	=	-Wall -Wextra -Werror

LIBC	=	ar rc

LIBR	=	ranlib

RM	=	rm -f

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

.PHONY: 	all clean fclean re
