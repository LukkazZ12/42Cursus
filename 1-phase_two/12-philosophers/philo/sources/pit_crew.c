/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pit_crew.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 17:07:24 by lucade-s          #+#    #+#             */
/*   Updated: 2023/07/10 21:56:35 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "werkroom.h"

int	read_the_house_down(t_library *library)
{
	int	i;
	int	sum;

	i = 0;
	sum = 0;
	while (i < library->num_of_queens)
	{
		sum = sum + get_queen_readings(library, i);
		i++;
	}
	if (sum == library->num_of_queens)
		return (1);
	return (0);
}

int	ru_is_laughing(t_library *library)
{
	int	laughing;

	laughing = 1;
	pthread_mutex_lock(&library->ru_is_judging);
	if (library->the_library_is_over)
		laughing = 0;
	pthread_mutex_unlock(&library->ru_is_judging);
	return (laughing);
}

unsigned long	time_now(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	print_queen_state(t_queens *queen, char *state)
{
	int				over;
	unsigned long	current_time;

	current_time = time_now() - queen->library->start;
	pthread_mutex_lock(&queen->library->ru_is_judging);
	over = queen->library->the_library_is_over;
	pthread_mutex_unlock(&queen->library->ru_is_judging);
	if (!over)
	{
		pthread_mutex_lock(&queen->library->print);
		printf("%lu %i %s", current_time, queen->index, state);
		pthread_mutex_unlock(&queen->library->print);
	}
}
