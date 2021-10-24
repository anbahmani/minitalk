/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 22:55:11 by abahmani          #+#    #+#             */
/*   Updated: 2021/10/24 12:07:20 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk_bonus.h"
extern int *g_client_pid;

static void initialize_g_var()
{
	g_client_pid = malloc(sizeof(int) * 2);
	if (!g_client_pid)
		return ;
	g_client_pid[0] = 0;
	g_client_pid[1] = 0;
}

static void	analyze_signal(int signal)
{
	static unsigned char	byte = 0;
	static unsigned	int 	bits = 0;

	if (signal == SIGUSR1)
		byte = byte | 1;
	bits++;
	if (bits > 7)
	{
		if (!byte)
		{
			kill(g_client_pid[0], SIGUSR1);
			free(g_client_pid);
			g_client_pid = NULL;
		}
		else
			write(1, &byte, 1);
		byte = 0;
		bits = 0;
	}
	else
		byte = byte << 1;
}

static void	analyze_client_pid(int signal)
{
	static unsigned char	byte = 0;
	static unsigned	int 	bits = 0;

	if (!g_client_pid)
		initialize_g_var();
	if (signal == SIGUSR1)
		byte = byte | 1;
	bits++;
	if (bits > 7)
	{
		if (!byte)
		{
			g_client_pid[0] /= 10;
			g_client_pid[1] = 1;
		}
		else
			g_client_pid[0]= (g_client_pid[0] + (byte - '0')) * 10;
		byte = 0;
		bits = 0;
	}
	else
		byte = byte << 1;
}

static void	wait_signal()
{
	while (1)
	{
		if (!g_client_pid || !g_client_pid[1])
		{
			signal(SIGUSR1, analyze_client_pid);
			signal(SIGUSR2, analyze_client_pid);
		}
		else
		{		
			signal(SIGUSR1, analyze_signal);
			signal(SIGUSR2, analyze_signal);
		}
		sleep(10);
	}
}

int main(void)
{
	ft_printf("%i\n", getpid());
	initialize_g_var();
	wait_signal();
}