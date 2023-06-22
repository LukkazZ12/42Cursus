/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:27:37 by lucade-s          #+#    #+#             */
/*   Updated: 2023/06/21 20:53:44 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_client	g_client;

static void	terminate(char *error_msg)
{
	ft_putstr_fd("ERROR: ", 1);
	ft_putstr_fd(error_msg, 1);
	ft_putstr_fd("\n", 1);
	exit(1);
}

static void	signal_handler(int signal)
{
	if (signal == SIGUSR1 || signal == SIGUSR2)
		g_client.sending_signal = 0;
}

static void	bit_by_bit(char byte)
{
	int	i;
	int	signal;

	i = 0;
	while (i < 8)
	{
		g_client.sending_signal = 1;
		if (byte << i & 128)
			signal = SIGUSR1;
		else
			signal = SIGUSR2;
		if (kill(g_client.pid, signal))
			terminate("Server offline or invalid PID.");
		while (g_client.sending_signal)
			usleep(SLEEP_TIME);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int					i;
	struct sigaction	action;

	if (argc != 3)
		terminate("Invalid number of arguments."
			" Try <./client> <PID server> <message>.");
	action = (struct sigaction){0};
	action.sa_handler = signal_handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	g_client.pid = ft_atoll(argv[1]);
	if (g_client.pid <= 0)
		terminate("Invalid PID.");
	i = 0;
	while (argv[2][i] != '\0')
	{
		bit_by_bit(argv[2][i]);
		i++;
	}
	bit_by_bit('\n');
	return (0);
}
