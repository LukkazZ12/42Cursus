/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:27:37 by lucade-s          #+#    #+#             */
/*   Updated: 2023/04/05 21:11:20 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

t_client	g_client;

void	send_bit(int bit)
{
	if (bit)
	{
		if (kill(g_client.pid, SIGUSR1) == -1)
			terminate(1, "Server offline or invalid PID");
		usleep(100);
	}
	else
	{
		if (kill(g_client.pid, SIGUSR2) == -1)
			terminate(1, "Server offline or invalid PID");
		usleep(100);
	}
}

t_handler	*ft_signal(int signum, t_handler *handler)
{
	g_client.action.sa_sigaction = handler;
	sigemptyset(&g_client.action.sa_mask);
	g_client.action.sa_flags = SA_SIGINFO;
	if (sigaction(signum, &g_client.action, &g_client.old_action) < 0)
		ft_putstr_fd("Signal error.\n", 1);
	return (g_client.old_action.sa_sigaction);
}

static void	msg_received(int sig, siginfo_t *info, void *context)
{
	if (g_client.count == 0)
	{
		(void) sig;
		(void) context;
		ft_putnbr_fd(info->si_pid, 1);
		ft_putstr_fd(" server PID: data received.\n", 1);
	}
	g_client.count++;
	if (sig == SIGUSR1)
		g_client.bit_acknowledged = 1;
}

void	byte_to_binary(char byte)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		g_client.bit_acknowledged = 0;
		send_bit(byte & (0x01 << i));
		while (!g_client.bit_acknowledged)
		{
			usleep(100);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	static int	i;

	if (argc != 3)
		terminate(1, "Invalid number of arguments.");
	ft_signal(SIGUSR1, msg_received);
	g_client.pid = ft_atoi(argv[1]);
	g_client.count = 0;
	if (g_client.pid <= 0)
		terminate(1, "Invalid PID.");
	i = 0;
	while (argv[2][i] != '\0')
	{
		byte_to_binary(argv[2][i]);
		i++;
	}
	byte_to_binary('\n');
	return (0);
}
