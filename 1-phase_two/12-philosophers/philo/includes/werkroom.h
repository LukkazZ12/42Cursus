/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   werkroom.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 20:12:56 by lucade-s          #+#    #+#             */
/*   Updated: 2023/07/20 17:53:13 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WERKROOM_H
# define WERKROOM_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# define NUM_OF_QUEENS 1
# define TIME_TO_SASHAY_AWAY 2
# define TIME_TO_READ 3
# define TIME_TO_BE_READ 4
# define TIMES_MUST_READ 5
# define START 6
# define HAS_TAKEN_GLASSES "has taken a fork"
# define IS_READING "is eating"
# define IS_BEING_READ "is sleeping"
# define IS_GAGGING "is thinking"
# define SASHAYED_AWAY "died"

typedef struct s_library
{
	int					num_of_queens;
	unsigned long		time_to_sashay_away;
	unsigned long		time_to_read;
	unsigned long		time_to_be_read;
	int					times_must_read;
	int					the_library_is_over;
	int					*queens_readings;
	unsigned long		start;
	pthread_t			rupaul;
	pthread_t			*queens;
	pthread_mutex_t		*glasses;
	pthread_mutex_t		print;
	pthread_mutex_t		ru_is_judging;
	pthread_mutex_t		time_last_reading;
	pthread_mutex_t		readings;
}	t_library;

typedef struct s_queens
{
	int					index;
	int					readings;
	int					last_reading_time;
	time_t				time_since_last_reading;
	pthread_mutex_t		*left_glasses;
	pthread_mutex_t		*right_glasses;
	t_library			*library;
}	t_queens;

// hello_hello_hello.c functions
unsigned int	ft_atoui(const char *nptr);
int				hello_hello_hello(int argc, char *argv[]);

// pit_crew.c functions
//int				get_value_from_library(t_library *library, int ver);
int				read_the_house_down(t_library *library);
int				ru_is_laughing(t_queens *queen);
void			print_queen_state(t_queens *queen, char *state);

// reading_is_fundamental.c functions
int				reading_is_fundamental(t_queens *queens, t_library *library);

// the_library_is_open.c functions
int				the_library_is_open(t_queens **queens, \
	t_library *library, char *argv[]);

// the_library_is_officially_closed.c functions
void			the_library_is_officially_closed(t_queens *queens, \
	t_library *library);
int				say_something_funny_silky_nutmeg_ganache(void);

// tuck_and_untuck.c functions
void			set_library_is_over(t_queens *queen);
void			set_time_last_reading(t_queens *queen);
unsigned int	get_time_last_reading(t_queens *queen_i);
void			set_queen_readings(t_queens *queen);
int				get_queen_readings(t_library *library, int i);

#endif