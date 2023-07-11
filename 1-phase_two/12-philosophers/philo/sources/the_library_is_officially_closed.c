/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_library_is_officially_closed.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 16:25:14 by lucade-s          #+#    #+#             */
/*   Updated: 2023/07/10 21:39:54 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "werkroom.h"

void	the_library_is_officially_closed(t_queens *queens, t_library *library)
{
	int	i;

	pthread_mutex_destroy(&library->print);
	pthread_mutex_destroy(&library->ru_is_judging);
	pthread_mutex_destroy(&library->time_last_reading);
	pthread_mutex_destroy(&library->readings);
	i = 0;
	while (i < library->num_of_queens)
	{
		pthread_mutex_destroy(&library->glasses[i]);
		i++;
	}	
	free(library->queens);
	free(library->glasses);
	free(queens);
	free(library);
}

int	say_something_funny_silky_nutmeg_ganache(void)
{
	printf("Error to init a mutex or to create or to join a thread.");
	return (1);
}
