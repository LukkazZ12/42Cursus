/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:27:52 by lucade-s          #+#    #+#             */
/*   Updated: 2023/04/13 18:31:34 by lucade-s         ###   ########.fr       */
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
	int					bit_acknowledged;
	int					pid;
	int					ver;
}						t_client;

void		terminate(int status, char *error_msg);
void		ft_putstr_fd(char *s, int fd);
void		ft_putchar_fd(char c, int fd);
void		ft_putnbr_fd(int n, int fd);
int			ft_atoi(const char *nptr);

#endif