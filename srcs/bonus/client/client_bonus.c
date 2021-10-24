/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 22:55:08 by abahmani          #+#    #+#             */
/*   Updated: 2021/10/24 12:09:58 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk_bonus.h"

static void	get_acknowledge(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("Accusé de réception bien reçu !");
}

static void	send_byte(int byte, pid_t pid)
{
	int tmp;

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
	signal(SIGUSR1, get_acknowledge);
}

static void	parse_msg(unsigned char *msg, pid_t pid)
{
	int	i;

	i = -1;
	while (msg[++i])
		send_byte((int) msg[i], pid);
	send_byte(0, pid);
}

static void send_pid_to_serv(pid_t pid_serv)
{
	char	*pid_str;

	pid_str = ft_itoa(getpid());
	parse_msg((unsigned char *) pid_str, pid_serv);
	free(pid_str);
}

int	main(int argc, char **argv)
{
	pid_t			pid_serv;
	unsigned char	*msg;

	if (argc != 3)
	{
		ft_putstr_fd("Erreur ! Le nombre de paramètres est incorrecte : ", 2);
		ft_putstr_fd("./client <pid du serveur> <message>\n", 2);
		return (1);
	}
	pid_serv = ft_atoi(argv[1]);
	msg = (unsigned char *) argv[2];
	send_pid_to_serv(pid_serv);
	parse_msg(msg, pid_serv);
}