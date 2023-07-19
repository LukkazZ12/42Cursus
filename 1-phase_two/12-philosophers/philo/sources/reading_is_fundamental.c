/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_is_fundamental.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 16:41:41 by lucade-s          #+#    #+#             */
/*   Updated: 2023/07/18 21:46:43 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "werkroom.h"

static void	get_the_glasses(t_queens *queen)
{
	if (queen->index % 2 == 1)
	{
		pthread_mutex_lock(queen->left_glasses);
		print_queen_state(queen, HAS_TAKEN_GLASSES);
		pthread_mutex_lock(queen->right_glasses);
		print_queen_state(queen, HAS_TAKEN_GLASSES);
	}
	else
	{
		pthread_mutex_lock(queen->right_glasses);
		print_queen_state(queen, HAS_TAKEN_GLASSES);
		pthread_mutex_lock(queen->left_glasses);
		print_queen_state(queen, HAS_TAKEN_GLASSES);
	}
}

static void	*rupaul_is_judging(void *queens_)
{
	int					i;
	unsigned long		current_time;
	t_queens			*queens;

	queens = (t_queens *)queens_;
	i = 0;
	while (1)
	{
		current_time = time_now() - queens->library->start;
		if (current_time - get_time_last_reading(&queens[i]) > \
			queens->library->time_to_sashay_away)
		{
			print_queen_state(&queens[i], SASHAYED_AWAY);
			set_library_is_over(queens);
			return (NULL);
		}
		i = (i + 1) % queens->library->num_of_queens;
		usleep(1000);
	}
	return (NULL);
}

static void	read_the_queens(t_queens *queen)
{
	get_the_glasses(queen);
	print_queen_state(queen, IS_READING);
	set_time_last_reading(queen);
	usleep(queen->library->time_to_read * 1000);
	pthread_mutex_unlock(queen->left_glasses);
	pthread_mutex_unlock(queen->right_glasses);
	queen->readings++;
	if (queen->readings == queen->library->times_must_read)
		set_queen_readings(queen);
	if (read_the_house_down(queen->library))
		set_library_is_over(queen);
	if (ru_is_laughing(queen))
	{
		print_queen_state(queen, IS_BEING_READ);
		usleep(queen->library->time_to_be_read * 1000);
		print_queen_state(queen, IS_GAGGING);
		usleep(500);
	}
}

static void	*paris_is_burning(void *queens_i)
{
	t_queens	*queen;

	queen = (t_queens *)queens_i;
	if (queen->index % 2 == 0)
		usleep(5000);
	if (queen->library->num_of_queens == 1)
	{
		pthread_mutex_lock(queen->left_glasses);
		print_queen_state(queen, HAS_TAKEN_GLASSES);
		pthread_mutex_unlock(queen->left_glasses);
		return (NULL);
	}
	while (ru_is_laughing(queen))
		read_the_queens(queen);
	if (queen->index % 2 == 0)
		usleep(3000);
	return (NULL);
}

int	reading_is_fundamental(t_queens *queens, t_library *library)
{
	int	i;

	if (pthread_create(&library->rupaul, NULL, &rupaul_is_judging, queens))
		return (say_something_funny_silky_nutmeg_ganache());
	i = 0;
	while (i < library->num_of_queens)
	{
		if (pthread_create(&library->queens[i], \
			NULL, &paris_is_burning, &queens[i]))
			return (say_something_funny_silky_nutmeg_ganache());
		i++;
	}
	i = 0;
	while (i < library->num_of_queens)
	{
		if (pthread_join(library->queens[i], NULL))
			return (say_something_funny_silky_nutmeg_ganache());
		i++;
	}
	if (pthread_join(library->rupaul, NULL))
		return (say_something_funny_silky_nutmeg_ganache());
	return (0);
}
