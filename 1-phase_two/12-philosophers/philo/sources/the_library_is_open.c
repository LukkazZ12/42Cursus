/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_library_is_open.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 16:19:01 by lucade-s          #+#    #+#             */
/*   Updated: 2023/07/04 21:57:11 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "werkroom.h"

static void	get_arround_queens(t_queens **queens, t_library *library)
{
	int	i;

	*queens = (t_queens *)malloc(sizeof(t_queens) * library->num_of_queens);
	i = 0;
	while (i < library->num_of_queens)
	{
		(*queens)[i].index = i + 1;
		(*queens)[i].readings = 0;
		(*queens)[i].time_since_last_reading = 0;
		(*queens)[i].left_glasses = &library->glasses[i];
		(*queens)[i].right_glasses = &library->glasses[(i + 1) \
			% library->num_of_queens];
		(*queens)[i].library = library;
		i++;
	}
}

int	the_library_is_open(t_queens **queens, t_library *library, char *argv[])
{
	int	i;

	library->num_of_queens = ft_atoui(argv[1]);
	library->time_to_sashay_away = ft_atoui(argv[2]);
	library->time_to_read = ft_atoui(argv[3]);
	library->time_to_be_read = ft_atoui(argv[4]);
	if (argv[5])
		library->times_must_read = ft_atoui(argv[5]);
	else
		library->times_must_read = 0;
	library->the_library_is_over = 0;
	library->start = time_now();
	library->queens = (pthread_t *)malloc(sizeof(pthread_t) \
		* (library->num_of_queens));
	library->glasses = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) \
		* library->num_of_queens);
	if (pthread_mutex_init(&library->print, NULL))
		return (say_something_funny_silky_nutmeg_ganache(*queens, library));
	// if (pthread_mutex_init(&library->last_reading, NULL))
	// 	return (say_something_funny_silky_nutmeg_ganache(*queens, library));
	// if (pthread_mutex_init(&library->ru_is_laughing_lock, NULL))
	// 	return (say_something_funny_silky_nutmeg_ganache(*queens, library));
	i = 0;
	while (i < library->num_of_queens)
	{
		if (pthread_mutex_init(&library->glasses[i], NULL))
			return (say_something_funny_silky_nutmeg_ganache(*queens, library));
		i++;
	}
	get_arround_queens(queens, library);
	return (0);
}
