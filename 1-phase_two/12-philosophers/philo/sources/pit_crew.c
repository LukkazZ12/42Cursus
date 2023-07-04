/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pit_crew.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 17:07:24 by lucade-s          #+#    #+#             */
/*   Updated: 2023/07/04 15:37:35 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "werkroom.h"

unsigned long	time_now(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	print_queen_state(t_queens *queen, char *state)
{
	unsigned long	current_time;

	pthread_mutex_lock(&queen->library->print);
	current_time = time_now() - queen->library->start;
	printf("%lu %i %s", current_time, queen->index, state);
	pthread_mutex_unlock(&queen->library->print);
}
