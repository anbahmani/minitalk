/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 22:15:43 by abahmani          #+#    #+#             */
/*   Updated: 2021/10/24 12:23:26 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

static void	send_byte(int byte, pid_t pid)
{
	int	tmp;

	tmp = 1 << 7;
	while (tmp)
	{
		if (!(byte & tmp))
		{
			if (kill(pid, SIGUSR2) == -1)
				ft_putstr_fd("Le pid saisie n'est pas valide.", 2);
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				ft_putstr_fd("Le pid saisie n'est pas valide.", 2);
		}
		tmp = tmp >> 1;
		usleep(50);
	}
}

static void	parse_msg(char *msg, pid_t pid)
{
	int	i;

	i = -1;
	while (msg[++i])
		send_byte((int) msg[i], pid);
	send_byte(0, pid);
}

int	main(int argc, char **argv)
{
	pid_t	pid_serv;
	char	*msg;

	if (argc != 3)
	{
		ft_putstr_fd("Erreur ! Le nombre de paramètres est incorrecte : ", 2);
		ft_putstr_fd("./client <pid du serveur> <message>\n", 2);
		return (1);
	}
	pid_serv = ft_atoi(argv[1]);
	msg = argv[2];
	parse_msg(msg, pid_serv);
}
