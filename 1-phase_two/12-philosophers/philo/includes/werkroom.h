/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   werkroom.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 20:12:56 by lucade-s          #+#    #+#             */
/*   Updated: 2023/07/01 17:08:56 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WERKROOM_H
# define WERKROOM_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_library
{
	int					num_of_queens;
	int					time_to_sashay_away;
	int					time_to_read;
	int					time_to_be_read;
	int					times_must_read;
	unsigned long		start;
	pthread_t			*queens;
	pthread_mutex_t		*glasses;
	pthread_mutex_t		print;
}	t_library;
	//pthread_mutex_t		rupaul_is_judging;

typedef struct s_queens
{
	int					index;
	int					readings;
	time_t				time_since_last_reading;
	pthread_mutex_t		*left_glasses;
	pthread_mutex_t		*right_glasses;
	t_library			*library;
}	t_queens;

// hello_hello_hello.c functions
unsigned int	ft_atoui(const char *nptr);
int				hello_hello_hello(int argc, char *argv[]);

// pit_crew.c functions
unsigned long	time_now(void);
void			print_queen_state(t_queens *queen, char *state);

// reading_is_fundamental.c functions
int				reading_is_fundamental(t_queens *queens, t_library *library);

// the_library_is_open.c functions
int				the_library_is_open(t_queens **queens, \
	t_library *library, char *argv[]);

// the_library_is_officially_closed.c functions
void			the_library_is_officially_closed(t_queens *queens, \
	t_library *library);
int				say_something_funny_silky_nutmeg_ganache(t_queens *queens, \
	t_library *library);

#endif