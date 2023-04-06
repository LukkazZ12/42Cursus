/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:27:52 by lucade-s          #+#    #+#             */
/*   Updated: 2023/04/05 20:32:52 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define SLEEP_TIME 100

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/types.h>

typedef struct s_client
{
	struct sigaction	action;
	struct sigaction	old_action;
	int					bit_acknowledged;
	int					pid;
	int					count;
}	t_client;
typedef void			t_handler(int sig, siginfo_t *info, void *context);
typedef unsigned char	t_byte;

void		terminate(int status, char *error_msg);
void		ft_putstr_fd(char *s, int fd);
void		ft_putchar_fd(char c, int fd);
void		ft_putnbr_fd(int n, int fd);
int			ft_atoi(const char *nptr);

#endif