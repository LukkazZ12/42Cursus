/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_is_fundamental.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 16:41:41 by lucade-s          #+#    #+#             */
/*   Updated: 2023/07/01 17:07:41 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "werkroom.h"

static void	*read_the_queens(void *queens_i)
{
	t_queens	*queen;

	queen = (t_queens *)queens_i;
	if (queen->index % 2 == 0)
		usleep(5000);
	pthread_mutex_lock(queen->left_glasses);
	print_queen_state(queen, "has taken a fork\n");
	pthread_mutex_unlock(queen->right_glasses);
	print_queen_state(queen, "has taken a fork\n");
	return (NULL);
}

int	reading_is_fundamental(t_queens *queens, t_library *library)
{
	int	i;

	i = 0;
	while (i < library->num_of_queens)
	{
		if (pthread_create(&library->queens[i], \
				NULL, &read_the_queens, &queens[i]))
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
