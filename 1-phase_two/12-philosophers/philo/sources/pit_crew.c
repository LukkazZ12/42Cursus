/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pit_crew.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 17:07:24 by lucade-s          #+#    #+#             */
/*   Updated: 2023/07/20 17:53:10 by lucade-s         ###   ########.fr       */
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

int	ru_is_laughing(t_queens *queen)
{
	int	laughing;

	laughing = 1;
	pthread_mutex_lock(&queen->library->ru_is_judging);
	if (queen->library->the_library_is_over)
		laughing = 0;
	pthread_mutex_unlock(&queen->library->ru_is_judging);
	return (laughing);
}

void	print_queen_state(t_queens *queen, char *state)
{
	int				over;
	unsigned long	current_time;
	struct timeval	time;

	gettimeofday(&time, NULL);
	current_time = time.tv_sec * 1000 + time.tv_usec / 1000 \
		- queen->library->start;
	pthread_mutex_lock(&queen->library->ru_is_judging);
	over = queen->library->the_library_is_over;
	pthread_mutex_unlock(&queen->library->ru_is_judging);
	if (!over)
	{
		pthread_mutex_lock(&queen->library->print);
		printf("%lu %i %s\n", current_time, queen->index, state);
		pthread_mutex_unlock(&queen->library->print);
	}
}
