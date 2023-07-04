/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_is_fundamental.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 16:41:41 by lucade-s          #+#    #+#             */
/*   Updated: 2023/07/04 17:58:39 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "werkroom.h"

unsigned long	get_last_time_reading(t_queens *queen)
{
	unsigned long	last_reading_time;

	pthread_mutex_lock(&queen->library->last_reading);
	last_reading_time = queen->time_since_last_reading;
	pthread_mutex_unlock(&queen->library->last_reading);
	return (last_reading_time);
}

int	get_the_ru_laugh(t_queens *queen)
{
	int	ru_laugh;

	pthread_mutex_lock(&queen->library->ru_is_laughing_lock);
	ru_laugh = queen->library->ru_is_laughing;
	pthread_mutex_unlock(&queen->library->ru_is_laughing_lock);
	return (ru_laugh);
}

int	ru_is_laughing(t_queens *queen)
{
	unsigned long	current_time;

	current_time = time_now() - queen->library->start;
	if (current_time - get_last_time_reading(queen) \
		> queen->library->time_to_sashay_away)
	{
		pthread_mutex_lock(&queen->library->ru_is_laughing_lock);
		queen->library->ru_is_laughing = 0;
		pthread_mutex_unlock(&queen->library->ru_is_laughing_lock);
		print_queen_state(queen, "died\n");
		return (0);
	}
	return (1);
}

static void	get_the_glasses(t_queens *queen)
{
	if (queen->index % 2)
	{
		pthread_mutex_lock(queen->left_glasses);
		print_queen_state(queen, "has taken a fork\n");
		pthread_mutex_lock(queen->right_glasses);
		print_queen_state(queen, "has taken a fork\n");
	}
	else
	{
		pthread_mutex_lock(queen->right_glasses);
		print_queen_state(queen, "has taken a fork\n");
		pthread_mutex_lock(queen->left_glasses);
		print_queen_state(queen, "has taken a fork\n");
	}
	pthread_mutex_unlock(queen->left_glasses);
	pthread_mutex_unlock(queen->right_glasses);
}

static void	read_the_queens(t_queens *queen)
{
	get_the_glasses(queen);
	print_queen_state(queen, "is eating\n");
	pthread_mutex_lock(&queen->library->last_reading);
	queen->time_since_last_reading = time_now() - queen->library->start;
	pthread_mutex_unlock(&queen->library->last_reading);
	usleep(queen->library->time_to_read * 1000);
	print_queen_state(queen, "is sleeping\n");
	usleep(queen->library->time_to_be_read * 1000);
	print_queen_state(queen, "is thinking\n");
	usleep(500);
}

static void	*step_foward(void *queens_i)
{
	t_queens	*queen;

	queen = (t_queens *)queens_i;
	if (queen->index % 2 == 0)
		usleep(5000);
	if (queen->library->num_of_queens == 1)
	{
		pthread_mutex_lock(queen->left_glasses);
		print_queen_state(queen, "has taken a fork\n");
		pthread_mutex_unlock(queen->left_glasses);
		return (NULL);
	}
	while (ru_is_laughing(queen))
		read_the_queens(queen);
	return (NULL);
}

int	reading_is_fundamental(t_queens *queens, t_library *library)
{
	int	i;

	i = 0;
	while (i < library->num_of_queens)
	{
		if (pthread_create(&library->queens[i], \
				NULL, &step_foward, &queens[i]))
			return (say_something_funny_silky_nutmeg_ganache(queens, library));
		i++;
	}
	i = 0;
	while (i < library->num_of_queens)
	{
		if (pthread_join(library->queens[i], NULL))
			return (say_something_funny_silky_nutmeg_ganache(queens, library));
		i++;
	}
	return (0);
}
