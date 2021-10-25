# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/07 16:07:58 by abahmani          #+#    #+#              #
#    Updated: 2021/10/25 16:21:30 by abahmani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT		=		client

NAME_SERVER		=		server

BONUS_CLIENT	=		client_bonus

BONUS_SERVER	=		server_bonus

RM			=		rm -f

all:		${NAME_CLIENT} ${NAME_SERVER}

${NAME_CLIENT}:	
			${MAKE} -C ./srcs/mandatory/client
			mv ./srcs/mandatory/client/client .

${NAME_SERVER}:	
			${MAKE} -C ./srcs/mandatory/server
			mv ./srcs/mandatory/server/server .

bonus:		${BONUS_CLIENT} ${BONUS_SERVER}

${BONUS_CLIENT}:		
			${MAKE} -C ./srcs/bonus/client
			mv ./srcs/bonus/client/client_bonus .

${BONUS_SERVER}:		
			${MAKE} -C ./srcs/bonus/server
			mv ./srcs/bonus/server/server_bonus .

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
			${RM} client_bonus
			${RM} server_bonus

re:             fclean all

FORCE : ;

.PHONY:         FORCE all clean fclean re