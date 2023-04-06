/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:27:31 by lucade-s          #+#    #+#             */
/*   Updated: 2023/04/05 20:39:37 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

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
		byte |= (0x01 << bit);
	if (bit == 7)
	{
		if (byte)
			ft_putchar_fd(byte, 1);
		bit = 0;
		byte = 0;
	}
	else
		bit++;
	if (kill(info->si_pid, SIGUSR1))
		terminate(1, "Error communicating with Client.");
}

int	main(void)
{
	struct sigaction	action;
	struct sigaction	old_action;
	
	print_pid();
	action = (struct sigaction){0};
	action.sa_sigaction = signal_handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &action, &old_action);
	sigaction(SIGUSR2, &action, &old_action);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
