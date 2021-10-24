/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 22:15:49 by abahmani          #+#    #+#             */
/*   Updated: 2021/10/24 12:25:56 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

static void	ft_putpid(pid_t pid)
{
	if (pid < 10)
		ft_putchar_fd(pid + '0', 1);
	else
	{
		ft_putpid(pid / 10);
		ft_putpid(pid % 10);
	}
}

static void	analyze_signal(int signal)
{
	static int				byte = 0;
	static unsigned int		bits = 0;

	if (signal == SIGUSR1)
		byte = byte | 1;
	bits++;
	if (bits > 7)
	{
		ft_putchar_fd((char) byte, 1);
		byte = 0;
		bits = 0;
	}
	else
		byte = byte << 1;
}

static void	wait_signal(void)
{
	while (1)
	{
		signal(SIGUSR1, analyze_signal);
		signal(SIGUSR2, analyze_signal);
		sleep(10);
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_putpid(pid);
	ft_putchar_fd('\n', 1);
	wait_signal();
}
