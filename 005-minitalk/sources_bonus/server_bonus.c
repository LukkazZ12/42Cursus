/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:27:31 by lucade-s          #+#    #+#             */
/*   Updated: 2023/04/21 16:43:42 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	terminate(char *error_msg)
{
	if (error_msg)
	{
		ft_putstr_fd("ERROR: ", 1);
		ft_putstr_fd(error_msg, 1);
		ft_putstr_fd("\n", 1);
	}
	exit(1);
}

static void	print_pid(void)
{
	ft_putstr_fd("Server PID is: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd(".\n", 1);
}

static void	signal_handler(int signal, siginfo_t *info, void *context)
{
	static int	bit;
	static char	byte;

	(void)context;
	if (signal == SIGUSR1)
		byte |= 128 >> bit;
	bit++;
	if (bit == 8)
	{
		ft_putchar_fd(byte, 1);
		bit = 0;
		byte = 0;
	}
	if (kill(info->si_pid, signal))
		terminate("Error communicating with Client.");
}

int	main(void)
{
	struct sigaction	action;

	print_pid();
	action = (struct sigaction){0};
	action.sa_sigaction = signal_handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
		pause();
	return (0);
}
