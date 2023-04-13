/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:27:37 by lucade-s          #+#    #+#             */
/*   Updated: 2023/04/13 20:02:17 by lucade-s         ###   ########.fr       */
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
		usleep(SLEEP_TIME);
	}
	else
	{
		if (kill(g_client.pid, SIGUSR2) == -1)
			terminate(1, "Server offline or invalid PID");
		usleep(SLEEP_TIME);
	}
}

static void	signal_handler(int signal)
{
	if (signal == SIGUSR1)
	{
		if (g_client.ver == 0)
		{
			ft_putnbr_fd(g_client.pid, 1);
			ft_putstr_fd(" server PID: data received.\n", 1);
		}
		g_client.bit_acknowledged = 1;
	}
}

static void	byte_to_binary(char byte)
{
	int		i;
	char	aux;
	
	i = 0;
	aux = byte;
	while (i < 8)
	{
		g_client.bit_acknowledged = 0;
		if (aux == '\n' && i == 7)
			g_client.ver = 0;
		send_bit(byte & (0x01 << i));
		while (!g_client.bit_acknowledged)
			usleep(SLEEP_TIME);
		i++;
	}
}

int	main(int argc, char **argv)
{
	static int			i;
	struct sigaction	action;

	if (argc != 3)
		terminate(1, "Invalid number of arguments.");
	g_client.ver = 1;
	action = (struct sigaction){0};
	action.sa_handler = signal_handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	sigaction(SIGUSR1, &action, NULL);
	g_client.pid = ft_atoi(argv[1]);
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
