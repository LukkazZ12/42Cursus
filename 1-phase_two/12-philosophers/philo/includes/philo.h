/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 20:12:56 by lucade-s          #+#    #+#             */
/*   Updated: 2023/06/29 15:41:54 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_dragrace
{
	int					num_of_queens;
	int					time_to_sashay_away;
	int					time_to_read;
	int					time_to_be_read;
	int					times_must_read;
	pthread_t			*queens;
	pthread_mutex_t		a_queen_is_reading;
}	t_dragrace;

// check_args.c functions
unsigned int	ft_atoui(const char *nptr);
int				hello_hello_hello(int argc, char *argv[]);

#endif