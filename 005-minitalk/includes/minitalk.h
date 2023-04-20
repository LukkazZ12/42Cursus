/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:27:52 by lucade-s          #+#    #+#             */
/*   Updated: 2023/04/20 15:59:48 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define SLEEP_TIME 100

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

typedef struct s_client
{
	int	bit_acknowledged;
	int	pid;
}	t_client;

void	terminate(char *error_msg);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_atoi(const char *nptr);

#endif