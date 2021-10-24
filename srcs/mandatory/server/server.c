/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 22:15:49 by abahmani          #+#    #+#             */
/*   Updated: 2021/10/24 20:42:25 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

static void	to_msg(char c)
{
	char		*tmp;
	char		tmp_char[2];
	static char	*msg;

	if (msg == NULL)
	{
		msg = malloc(sizeof(char));
		if (!msg)
			exit(1);
		msg[0] = '\0';
	}
	if (!c)
	{
		printf("%s", msg);
		free(msg);
		msg = NULL;
	}
	else
	{
		tmp_char[0] = c;
		tmp_char[1] = '\0';
		tmp = msg;
		msg = ft_strjoin(msg, tmp_char);
		free(tmp);
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
		to_msg((char) byte);
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
	printf("%ld\n", (long int)getpid());
	wait_signal();
}
