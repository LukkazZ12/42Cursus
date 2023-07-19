/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuck_and_untuck.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 21:53:37 by lucade-s          #+#    #+#             */
/*   Updated: 2023/07/18 21:25:50 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "werkroom.h"

void	set_library_is_over(t_queens *queen)
{
	pthread_mutex_lock(&queen->library->ru_is_judging);
	queen->library->the_library_is_over = 1;
	pthread_mutex_unlock(&queen->library->ru_is_judging);
}

void	set_time_last_reading(t_queens *queen)
{
	pthread_mutex_lock(&queen->library->time_last_reading);
	queen->time_since_last_reading = time_now() - queen->library->start;
	pthread_mutex_unlock(&queen->library->time_last_reading);
}

unsigned int	get_time_last_reading(t_queens *queen_i)
{
	unsigned int	time_last_reading;

	pthread_mutex_lock(&queen_i->library->time_last_reading);
	time_last_reading = queen_i->time_since_last_reading;
	pthread_mutex_unlock(&queen_i->library->time_last_reading);
	return (time_last_reading);
}

void	set_queen_readings(t_queens *queen)
{
	pthread_mutex_lock(&queen->library->readings);
	queen->library->queens_readings[queen->index - 1] = 1;
	pthread_mutex_unlock(&queen->library->readings);
}

int	get_queen_readings(t_library *library, int i)
{
	unsigned int	readings;

	pthread_mutex_lock(&library->readings);
	readings = library->queens_readings[i];
	pthread_mutex_unlock(&library->readings);
	return (readings);
}
