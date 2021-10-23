# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/07 16:07:58 by abahmani          #+#    #+#              #
#    Updated: 2021/10/23 18:24:31 by abahmani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		minitalk

RM			=		rm -f

${NAME}:	FORCE
			${RM} ${NAME}
			${MAKE} -C ./srcs/mandatory/client
			${MAKE} -C ./srcs/mandatory/server
			mv ./srcs/mandatory/client/client .
			mv ./srcs/mandatory/server/server .

bonus:		
			${RM} client
			${RM} server
			${MAKE} -C ./srcs/bonus/client
			${MAKE} -C ./srcs/bonus/server
			mv ./srcs/bonus/client/client .
			mv ./srcs/bonus/server/server .

all:		${NAME}

clean:		
			${MAKE} -C ./srcs/mandatory/client clean
			${MAKE} -C ./srcs/mandatory/server clean
			${MAKE} -C ./srcs/bonus/client clean
			${MAKE} -C ./srcs/bonus/server clean

fclean:		clean
			${MAKE} -C ./srcs/mandatory/client fclean
			${MAKE} -C ./srcs/mandatory/server fclean
			${MAKE} -C ./srcs/bonus/client fclean
			${MAKE} -C ./srcs/bonus/server fclean
			${RM} client
			${RM} server

re:             fclean all

FORCE : ;

.PHONY:         FORCE all clean fclean re