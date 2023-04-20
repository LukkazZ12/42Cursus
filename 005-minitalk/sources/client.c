/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:27:37 by lucade-s          #+#    #+#             */
/*   Updated: 2023/04/20 16:16:30 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_client	g_client;

static void	signal_handler(int signal)
{
	static int	i = 0;

	if (signal == SIGUSR1)
		ft_putchar_fd('1', 1);
	else
		ft_putchar_fd('0', 1);
	i++;
	g_client.bit_acknowledged = 1;
	if (i == 8)
	{
		ft_putchar_fd(' ', 1);
		i = 0;
	}
}

static void	byte_to_binary(char byte)
{
	int		i;
	int		signal;

	i = 0;
	while (i < 8)
	{
		g_client.bit_acknowledged = 0;
		if (byte << i & 128)
			signal = SIGUSR1;
		else
			signal = SIGUSR2;
		if (kill(g_client.pid, signal))
			terminate("Server offline or invalid PID");
		usleep(SLEEP_TIME);
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
		terminate("Invalid number of arguments.");
	action = (struct sigaction){0};
	action.sa_handler = signal_handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	g_client.pid = ft_atoi(argv[1]);
	if (g_client.pid <= 0)
		terminate("Invalid PID.");
	i = 0;
	while (argv[2][i] != '\0')
	{
		byte_to_binary(argv[2][i]);
		i++;
	}
	byte_to_binary('\n');
	return (0);
}
